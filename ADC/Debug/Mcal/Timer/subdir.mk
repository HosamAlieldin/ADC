################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/Timer/Timer.c \
../Mcal/Timer/Timer_pbCfg.c 

OBJS += \
./Mcal/Timer/Timer.o \
./Mcal/Timer/Timer_pbCfg.o 

C_DEPS += \
./Mcal/Timer/Timer.d \
./Mcal/Timer/Timer_pbCfg.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/Timer/%.o: ../Mcal/Timer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


