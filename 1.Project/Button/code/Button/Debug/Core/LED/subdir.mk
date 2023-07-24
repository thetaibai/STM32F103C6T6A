################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/LED/LED.c 

OBJS += \
./Core/LED/LED.o 

C_DEPS += \
./Core/LED/LED.d 


# Each subdirectory must supply rules for building sources it contributes
Core/LED/%.o Core/LED/%.su Core/LED/%.cyclo: ../Core/LED/%.c Core/LED/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/Button/code/Button/Core/LittleOs/Config" -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/Button/code/Button/Core/LittleOs/Core" -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/Button/code/Button/Core/Button" -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/Button/code/Button/Core/LED" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-LED

clean-Core-2f-LED:
	-$(RM) ./Core/LED/LED.cyclo ./Core/LED/LED.d ./Core/LED/LED.o ./Core/LED/LED.su

.PHONY: clean-Core-2f-LED

