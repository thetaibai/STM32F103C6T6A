################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/7SEG/Core/7SEG.c 

OBJS += \
./Core/7SEG/Core/7SEG.o 

C_DEPS += \
./Core/7SEG/Core/7SEG.d 


# Each subdirectory must supply rules for building sources it contributes
Core/7SEG/Core/%.o Core/7SEG/Core/%.su Core/7SEG/Core/%.cyclo: ../Core/7SEG/Core/%.c Core/7SEG/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/7SEG_MPX4_CC/7SEG_MPX4_CC/Core/7SEG/Config" -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/7SEG_MPX4_CC/7SEG_MPX4_CC/Core/7SEG/Core" -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/7SEG_MPX4_CC/7SEG_MPX4_CC/Core/LittleOs/Config" -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/7SEG_MPX4_CC/7SEG_MPX4_CC/Core/LittleOs/Core" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-7SEG-2f-Core

clean-Core-2f-7SEG-2f-Core:
	-$(RM) ./Core/7SEG/Core/7SEG.cyclo ./Core/7SEG/Core/7SEG.d ./Core/7SEG/Core/7SEG.o ./Core/7SEG/Core/7SEG.su

.PHONY: clean-Core-2f-7SEG-2f-Core

