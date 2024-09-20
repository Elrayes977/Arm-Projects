################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MGPIO/MGPIO_prg.c 

OBJS += \
./MCAL/MGPIO/MGPIO_prg.o 

C_DEPS += \
./MCAL/MGPIO/MGPIO_prg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MGPIO/MGPIO_prg.o: ../MCAL/MGPIO/MGPIO_prg.c MCAL/MGPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"E:/Abdo/embedded/NTI-embedded/ARM/NTI/MY workspace/ARM_vesion1-0-DMA/MCAL/MAFIO" -I"E:/Abdo/embedded/NTI-embedded/ARM/NTI/MY workspace/ARM_vesion1-0-DMA/MCAL/MEXTI" -I"E:/Abdo/embedded/NTI-embedded/ARM/NTI/MY workspace/ARM_vesion1-0-DMA/MCAL/MNVIC" -I../Inc -I"E:/Abdo/embedded/NTI-embedded/ARM/NTI/MY workspace/ARM_vesion1-0-DMA/HAL/HLED_MRX" -I"E:/Abdo/embedded/NTI-embedded/ARM/NTI/MY workspace/ARM_vesion1-0-DMA/MCAL/MSysTick" -I"E:/Abdo/embedded/NTI-embedded/ARM/NTI/MY workspace/ARM_vesion1-0-DMA/HAL/HSWITCH" -I"E:/Abdo/embedded/NTI-embedded/ARM/NTI/MY workspace/ARM_vesion1-0-DMA/HAL/LED" -I"E:/Abdo/embedded/NTI-embedded/ARM/NTI/MY workspace/ARM_vesion1-0-DMA/MCAL/MGPIO" -I"E:/Abdo/embedded/NTI-embedded/ARM/NTI/MY workspace/ARM_vesion1-0-DMA/MCAL/MRCC" -I"E:/Abdo/embedded/NTI-embedded/ARM/NTI/MY workspace/ARM_vesion1-0-DMA/HAL" -I"E:/Abdo/embedded/NTI-embedded/ARM/NTI/MY workspace/ARM_vesion1-0-DMA/LIB" -I"E:/Abdo/embedded/NTI-embedded/ARM/NTI/MY workspace/ARM_vesion1-0-DMA/MCAL" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/MGPIO/MGPIO_prg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

