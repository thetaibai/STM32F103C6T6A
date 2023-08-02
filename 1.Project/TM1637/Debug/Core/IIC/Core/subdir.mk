################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/IIC/Core/IIC.c 

OBJS += \
./Core/IIC/Core/IIC.o 

C_DEPS += \
./Core/IIC/Core/IIC.d 


# Each subdirectory must supply rules for building sources it contributes
Core/IIC/Core/%.o Core/IIC/Core/%.su Core/IIC/Core/%.cyclo: ../Core/IIC/Core/%.c Core/IIC/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/TM1637/Core/IIC/Config" -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/TM1637/Core/IIC/Core" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-IIC-2f-Core

clean-Core-2f-IIC-2f-Core:
	-$(RM) ./Core/IIC/Core/IIC.cyclo ./Core/IIC/Core/IIC.d ./Core/IIC/Core/IIC.o ./Core/IIC/Core/IIC.su

.PHONY: clean-Core-2f-IIC-2f-Core

