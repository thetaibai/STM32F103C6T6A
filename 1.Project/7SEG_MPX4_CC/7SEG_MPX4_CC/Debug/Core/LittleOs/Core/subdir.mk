################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/LittleOs/Core/OS.c 

OBJS += \
./Core/LittleOs/Core/OS.o 

C_DEPS += \
./Core/LittleOs/Core/OS.d 


# Each subdirectory must supply rules for building sources it contributes
Core/LittleOs/Core/%.o Core/LittleOs/Core/%.su Core/LittleOs/Core/%.cyclo: ../Core/LittleOs/Core/%.c Core/LittleOs/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/7SEG_MPX4_CC/7SEG_MPX4_CC/Core/7SEG/Config" -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/7SEG_MPX4_CC/7SEG_MPX4_CC/Core/7SEG/Core" -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/7SEG_MPX4_CC/7SEG_MPX4_CC/Core/LittleOs/Config" -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/7SEG_MPX4_CC/7SEG_MPX4_CC/Core/LittleOs/Core" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-LittleOs-2f-Core

clean-Core-2f-LittleOs-2f-Core:
	-$(RM) ./Core/LittleOs/Core/OS.cyclo ./Core/LittleOs/Core/OS.d ./Core/LittleOs/Core/OS.o ./Core/LittleOs/Core/OS.su

.PHONY: clean-Core-2f-LittleOs-2f-Core

