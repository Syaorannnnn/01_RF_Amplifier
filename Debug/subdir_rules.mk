################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/ti/CCS_THEIA/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"E:/ti/workspace/01_RF_Amplifier" -I"E:/ti/workspace/01_RF_Amplifier/Debug" -I"E:/ti/SDK/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"E:/ti/SDK/mspm0_sdk_2_04_00_06/source" -I"E:/ti/workspace/01_RF_Amplifier/HARDWARE" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-931841473: ../RF_Amplifier.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"E:/ti/sysconfig_1.23.1/sysconfig_cli.bat" --script "E:/ti/workspace/01_RF_Amplifier/RF_Amplifier.syscfg" -o "." -s "E:/ti/SDK/mspm0_sdk_2_04_00_06/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-931841473 ../RF_Amplifier.syscfg
device.opt: build-931841473
device.cmd.genlibs: build-931841473
ti_msp_dl_config.c: build-931841473
ti_msp_dl_config.h: build-931841473
Event.dot: build-931841473

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/ti/CCS_THEIA/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"E:/ti/workspace/01_RF_Amplifier" -I"E:/ti/workspace/01_RF_Amplifier/Debug" -I"E:/ti/SDK/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"E:/ti/SDK/mspm0_sdk_2_04_00_06/source" -I"E:/ti/workspace/01_RF_Amplifier/HARDWARE" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: E:/ti/SDK/mspm0_sdk_2_04_00_06/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/ti/CCS_THEIA/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"E:/ti/workspace/01_RF_Amplifier" -I"E:/ti/workspace/01_RF_Amplifier/Debug" -I"E:/ti/SDK/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"E:/ti/SDK/mspm0_sdk_2_04_00_06/source" -I"E:/ti/workspace/01_RF_Amplifier/HARDWARE" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


