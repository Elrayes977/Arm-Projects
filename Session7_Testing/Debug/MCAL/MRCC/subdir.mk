################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MRCC/MRCC_prg.c 

OBJS += \
./MCAL/MRCC/MRCC_prg.o 

C_DEPS += \
./MCAL/MRCC/MRCC_prg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MRCC/MRCC_prg.o: ../MCAL/MRCC/MRCC_prg.c MCAL/MRCC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/Session7_Testing/MCAL/MGPIO" -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/Session7_Testing/MCAL/MRCC" -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/Session7_Testing/HAL" -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/Session7_Testing/LIB" -I"F:/All emportant studies/NTI-embedded/ARM/NTI/MY workspace/Session7_Testing/MCAL" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/MRCC/MRCC_prg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

