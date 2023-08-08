################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/TM1637/Core/TM1637.c 

OBJS += \
./Core/TM1637/Core/TM1637.o 

C_DEPS += \
./Core/TM1637/Core/TM1637.d 


# Each subdirectory must supply rules for building sources it contributes
Core/TM1637/Core/%.o Core/TM1637/Core/%.su Core/TM1637/Core/%.cyclo: ../Core/TM1637/Core/%.c Core/TM1637/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/TM1637/Core/IIC/Config" -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/TM1637/Core/IIC/Core" -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/TM1637/Core/TM1637/Config" -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/TM1637/Core/TM1637/Core" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-TM1637-2f-Core

clean-Core-2f-TM1637-2f-Core:
	-$(RM) ./Core/TM1637/Core/TM1637.cyclo ./Core/TM1637/Core/TM1637.d ./Core/TM1637/Core/TM1637.o ./Core/TM1637/Core/TM1637.su

.PHONY: clean-Core-2f-TM1637-2f-Core

