################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MEXTI/MEXTI_prog.c 

OBJS += \
./MCAL/MEXTI/MEXTI_prog.o 

C_DEPS += \
./MCAL/MEXTI/MEXTI_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MEXTI/MEXTI_prog.o: ../MCAL/MEXTI/MEXTI_prog.c MCAL/MEXTI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"G:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_UART/MCAL/MAFIO" -I"G:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_UART/MCAL/MDMA" -I"G:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_UART/MCAL/MUART" -I"G:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_UART/MCAL/MEXTI" -I"G:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_UART/MCAL/MNVIC" -I../Inc -I"G:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_UART/HAL/HLED_MRX" -I"G:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_UART/MCAL/MSysTick" -I"G:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_UART/HAL/HSWITCH" -I"G:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_UART/HAL/LED" -I"G:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_UART/MCAL/MGPIO" -I"G:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_UART/MCAL/MRCC" -I"G:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_UART/HAL" -I"G:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_UART/LIB" -I"G:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_UART/MCAL" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/MEXTI/MEXTI_prog.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

