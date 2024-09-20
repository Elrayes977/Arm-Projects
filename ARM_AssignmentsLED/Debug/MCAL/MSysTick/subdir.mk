################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MSysTick/MSTK_prg.c 

OBJS += \
./MCAL/MSysTick/MSTK_prg.o 

C_DEPS += \
./MCAL/MSysTick/MSTK_prg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MSysTick/MSTK_prg.o: ../MCAL/MSysTick/MSTK_prg.c MCAL/MSysTick/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_TESTING101/HAL/HLED_MRX" -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_TESTING101/MCAL/MAFIO" -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_TESTING101/MCAL/MEXTI" -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_TESTING101/MCAL/MNVIC" -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_TESTING101/MCAL/MSysTick" -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_TESTING101/HAL/HSWITCH" -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_TESTING101/HAL/LED" -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_TESTING101/MCAL/MGPIO" -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_TESTING101/MCAL/MRCC" -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_TESTING101/HAL" -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_TESTING101/LIB" -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/ARM_TESTING101/MCAL" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/MSysTick/MSTK_prg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

