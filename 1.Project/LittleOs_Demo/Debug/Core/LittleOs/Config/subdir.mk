################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/LittleOs/Config/Task.c 

OBJS += \
./Core/LittleOs/Config/Task.o 

C_DEPS += \
./Core/LittleOs/Config/Task.d 


# Each subdirectory must supply rules for building sources it contributes
Core/LittleOs/Config/%.o Core/LittleOs/Config/%.su Core/LittleOs/Config/%.cyclo: ../Core/LittleOs/Config/%.c Core/LittleOs/Config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/LittleOs_Demo/Core/LittleOs/Core" -I"C:/Users/a9077/Desktop/learn/Chip/STM32F103C6T6/STM32F103C6T6A/1.Project/LittleOs_Demo/Core/LittleOs/Config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-LittleOs-2f-Config

clean-Core-2f-LittleOs-2f-Config:
	-$(RM) ./Core/LittleOs/Config/Task.cyclo ./Core/LittleOs/Config/Task.d ./Core/LittleOs/Config/Task.o ./Core/LittleOs/Config/Task.su

.PHONY: clean-Core-2f-LittleOs-2f-Config

