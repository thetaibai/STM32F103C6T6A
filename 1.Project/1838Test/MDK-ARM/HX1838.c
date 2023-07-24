#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "string.h"
#include <stdlib.h> 
#include <math.h>
#include "stdio.h"

#define  RX_DBG_EN   0

#define  RX_SEQ_NUM  33

#if RX_DBG_EN
#define RX_DBG(format, ...) printf(format, ##__VA_ARGS__)
#else
#define RX_DBG(format, ...) ;
#endif

static uint8_t  tim_udt_cnt      = 0;
static uint8_t  cap_pol          = 0; 
static uint8_t  cap_pulse_cnt    = 0;
static uint8_t  sta_idle         = 1;
static uint8_t  cap_frame        = 0;

static uint16_t rx_frame[RX_SEQ_NUM*2] = {0}; 

struct {
    uint16_t  src_data[RX_SEQ_NUM*2];
    uint16_t  repet_cnt;
    union{
        uint32_t rev;
        struct
        {
            uint32_t key_val_n:8;
            uint32_t key_val  :8;
            uint32_t addr_n   :8;
            uint32_t addr     :8;
        }_rev;
    }data;
}rx;

uint8_t appro(int num1,int num2)
{
    return (abs(num1-num2) < 300);
}

void rx_rcv_init(void)
{
    cap_frame     = 0;                                       //δ����������
    sta_idle      = 0;                                       //�ǿ���״̬
    tim_udt_cnt   = 0;                                       //��ʱ�������0
    cap_pulse_cnt = 0;                                       //���񵽵ļ�����0
    
    memset(rx_frame,0x00,sizeof(rx_frame));
}

/* ����жϻص����� */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{   
	if(TIM1 == htim->Instance)
	{
        if(sta_idle)                                          //����״̬�������κδ���
        {
            return;
        }
        
        tim_udt_cnt++;                                         //���һ��
        if(tim_udt_cnt == 3)                                   //���3��
        {
            tim_udt_cnt = 0;                                   //�����������
            sta_idle    = 1;                                   //����Ϊ����״̬
            cap_frame   = 1;                                   //��ǲ����µ�����
        }
	} 
}


/* ��ƽ�����жϻص� */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    static uint16_t tmp_cnt_l,tmp_cnt_h;
	if(TIM1 == htim->Instance)
	{
        switch(cap_pol)                                                                                         //���ݼ��Ա�־λ�жϲ����ǵ͵�ƽ���Ǹߵ�ƽ
        {   
            /* �����½��� */
            case 0:
                tmp_cnt_l = HAL_TIM_ReadCapturedValue(&htim1,TIM_CHANNEL_1);                                    //��¼��ǰʱ��
                TIM_RESET_CAPTUREPOLARITY(&htim1, TIM_CHANNEL_1);                                               //��λ��������
                TIM_SET_CAPTUREPOLARITY(&htim1, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);                //�ı伫��
                
                cap_pol = 1;                                                                                    //���Ա�־λ��Ϊ������
                
                if(sta_idle)                                                                                    //�����ǰΪ����״̬�����в��񵽵�ʱ��Ϊ��һ���½���
                {
                    rx_rcv_init();
                    break;                                                                                      //����
                }
                rx_frame[cap_pulse_cnt] = tim_udt_cnt * 10000 + tmp_cnt_l - tmp_cnt_h;                          //���ϴβ���ļ�ʱ�����¼ֵ
                tim_udt_cnt = 0;                                                                                //���������0
                RX_DBG("(%2d)%4d us:H\r\n",cap_pulse_cnt,rx_frame[cap_pulse_cnt]);                              //DBG����ӡ���񵽵ĵ�ƽ����ʱ��
                cap_pulse_cnt++;                                                                                //����++
                break;
            
            /* ���������� */
            case 1:
                tmp_cnt_h = HAL_TIM_ReadCapturedValue(&htim1,TIM_CHANNEL_1);
                TIM_RESET_CAPTUREPOLARITY(&htim1, TIM_CHANNEL_1);               
                TIM_SET_CAPTUREPOLARITY(&htim1, TIM_CHANNEL_1, TIM_ICPOLARITY_FALLING);
                
                cap_pol = 0;   
                if(sta_idle)
                {
                    rx_rcv_init();
                    break;
                }
                rx_frame[cap_pulse_cnt] = tim_udt_cnt * 10000 + tmp_cnt_h - tmp_cnt_l;
                tim_udt_cnt = 0;
                RX_DBG("(%2d)%4d us:L\r\n",cap_pulse_cnt,rx_frame[cap_pulse_cnt]);
                cap_pulse_cnt++;
                break;
            
            default:
                break;
        }
    }
}


/*************************************  API Layer **************************************************/
void hx1838_cap_start(void)
{
    HAL_TIM_Base_Start_IT(&htim1);
    HAL_TIM_IC_Start_IT(&htim1,TIM_CHANNEL_1);
}

uint8_t hx1838_data_decode(void)
{
    memcpy(rx.src_data,rx_frame,RX_SEQ_NUM*4);
    memset(rx_frame,0x00,RX_SEQ_NUM*4);   
    RX_DBG("========= rx.src[] =================\r\n");
    for(uint8_t i = 0;i<=(RX_SEQ_NUM*2);i++)
    {
        RX_DBG("[%d]%d\r\n",i,rx.src_data[i]);
    }
    RX_DBG("========= rx.rec =================\r\n");
    if(appro(rx.src_data[0],9000) && appro(rx.src_data[1],4500))                 //#1. ���ǰ����
    {
        uint8_t tmp_idx = 0;
        rx.repet_cnt  = 0;                                                       //�����ظ�������0
        for(uint8_t i = 2;i<(RX_SEQ_NUM*2);i++)                                  //#2. �������
        {
            if(!appro(rx.src_data[i],560))
            {
                RX_DBG("%d,err:%d != 560\r\n",i,rx.src_data[i]);
                return 0;
            }
            i++;
            if(appro(rx.src_data[i],1680))
            {
                rx.data.rev |= (0x80000000 >> tmp_idx);                          //�� tmp_idx Ϊ��1
                tmp_idx++;
            }
            else if(appro(rx.src_data[i],560))
            {
                rx.data.rev &= ~(0x80000000 >> tmp_idx);                         //�� tmp_idx λ��0
                tmp_idx++;
            }
            else
            {
                RX_DBG("%d,err:%d != 560||1680\r\n",i,rx.src_data[i+1]);
                return 0;
            }
        }
    }
    else if(appro(rx.src_data[0],9000) && appro(rx.src_data[1],2250) && appro(rx.src_data[2],560))
    {
        rx.repet_cnt++;
        return 2;
    }
    else
    {
        RX_DBG("ǰ���������\r\n");
        return 0;
    }
    return 1;
}

void hx1838_proc(uint8_t res)
{
    if(res == 0)
    {
        printf("error \r\n");
        return;
    }
    
    if(res == 2)
    {
        printf("repet(%d)\r\n",rx.repet_cnt);
        return;
    }      
    

    switch(rx.data._rev.key_val)
    {
        case 162:
            printf("detected code [%s] \r\n","1");
            break;
        
        case 98:
            printf("detected code [%s] \r\n","2");
            break;
        
        case 226:
            printf("detected code [%s] \r\n","3");
            break;
        
        case 34:
            printf("detected code [%s] \r\n","4");
            break;
        
        case 2:
            printf("detected code [%s] \r\n","5");
            break;
        
        case 194:
            printf("detected code [%s] \r\n","6");
            break;
        
        case 224:
            printf("detected code [%s] \r\n","7");
            break;
        
        case 168:
            printf("detected code [%s] \r\n","8");
            break;
        
        case 144:
            printf("detected code [%s] \r\n","9");
            break;
        
        case 152:
            printf("detected code [%s] \r\n","0");
            break;
        
        case 104:
            printf("detected code [%s] \r\n","*");
            break;
        
        case 176:
            printf("detected code [%s] \r\n","#");
            break;
                
        case 24:
            printf("detected code [%s] \r\n","��");
            break;
                
        case 16:
            printf("detected code [%s] \r\n","��");
            break;
        
        case 74:
            printf("detected code [%s] \r\n","��");
            break;
        
        case 90:
            printf("detected code [%s] \r\n","��");
            break;
        
        case 56:
            printf("detected code [%s] \r\n","OK");
            break;
        
        default:
            printf("detected unknow code \r\n");
            break;
        
    }
}

void HX1838_demo(void)
{
    hx1838_cap_start();
    while(1)
    {
        if(cap_frame)
        {   
            hx1838_proc(hx1838_data_decode());
            cap_frame = 0;
        }
    };
    
}