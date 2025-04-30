################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
HARDWARE/BTN/%.o: ../HARDWARE/BTN/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/ti/CCS_THEIA/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"E:/ti/workspace/01_RF_Amplifier" -I"E:/ti/workspace/01_RF_Amplifier/Debug" -I"E:/ti/SDK/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"E:/ti/SDK/mspm0_sdk_2_04_00_06/source" -I"E:/ti/workspace/01_RF_Amplifier/HARDWARE" -gdwarf-3 -MMD -MP -MF"HARDWARE/BTN/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


