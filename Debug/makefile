################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := E:/ti/CCS_THEIA/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS

GEN_OPTS__FLAG := @"./device.opt" 
GEN_CMDS__FLAG := -Wl,-l"./device_linker.cmd" 

ORDERED_OBJS += \
"./RF_Amplifier.o" \
"./ti_msp_dl_config.o" \
"./startup_mspm0g350x_ticlang.o" \
"./HARDWARE/ADC/ADC.o" \
"./HARDWARE/BTN/BTN.o" \
"./HARDWARE/DAC/DAC.o" \
"./HARDWARE/FREQ_DECODER/FREQ_DECODER.o" \
"./HARDWARE/LCD/HMI_GUI.o" \
"./HARDWARE/LCD/PAGE_HANDLE.o" \
"./HARDWARE/LCD/tjc_usart_hmi.o" \
"./HARDWARE/ROTARY_ENCODER/ROTARY_ENCODER.o" \
"./HARDWARE/TICK/Tick.o" \
"./HARDWARE/UART/UART.o" \
$(GEN_CMDS__FLAG) \
-Wl,-ldevice.cmd.genlibs \
-Wl,-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include HARDWARE/ADC/subdir_vars.mk
-include HARDWARE/BTN/subdir_vars.mk
-include HARDWARE/DAC/subdir_vars.mk
-include HARDWARE/FREQ_DECODER/subdir_vars.mk
-include HARDWARE/LCD/subdir_vars.mk
-include HARDWARE/ROTARY_ENCODER/subdir_vars.mk
-include HARDWARE/TICK/subdir_vars.mk
-include HARDWARE/UART/subdir_vars.mk
-include subdir_rules.mk
-include HARDWARE/ADC/subdir_rules.mk
-include HARDWARE/BTN/subdir_rules.mk
-include HARDWARE/DAC/subdir_rules.mk
-include HARDWARE/FREQ_DECODER/subdir_rules.mk
-include HARDWARE/LCD/subdir_rules.mk
-include HARDWARE/ROTARY_ENCODER/subdir_rules.mk
-include HARDWARE/TICK/subdir_rules.mk
-include HARDWARE/UART/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
01_RF_Amplifier.out 

EXE_OUTPUTS__QUOTED += \
"01_RF_Amplifier.out" 


# All Target
all: $(OBJS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "01_RF_Amplifier.out"

# Tool invocations
01_RF_Amplifier.out: $(OBJS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"E:/ti/CCS_THEIA/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/bin/tiarmclang.exe" @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -gdwarf-3 -Wl,-m"01_RF_Amplifier.map" -Wl,-i"E:/ti/SDK/mspm0_sdk_2_04_00_06/source" -Wl,-i"E:/ti/workspace/01_RF_Amplifier" -Wl,-i"E:/ti/workspace/01_RF_Amplifier/Debug/syscfg" -Wl,-i"E:/ti/CCS_THEIA/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/lib" -Wl,--diag_wrap=off -Wl,--display_error_number -Wl,--warn_sections -Wl,--xml_link_info="01_RF_Amplifier_linkInfo.xml" -Wl,--rom_model -o "01_RF_Amplifier.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "RF_Amplifier.o" "ti_msp_dl_config.o" "startup_mspm0g350x_ticlang.o" "HARDWARE\ADC\ADC.o" "HARDWARE\BTN\BTN.o" "HARDWARE\DAC\DAC.o" "HARDWARE\FREQ_DECODER\FREQ_DECODER.o" "HARDWARE\LCD\HMI_GUI.o" "HARDWARE\LCD\PAGE_HANDLE.o" "HARDWARE\LCD\tjc_usart_hmi.o" "HARDWARE\ROTARY_ENCODER\ROTARY_ENCODER.o" "HARDWARE\TICK\Tick.o" "HARDWARE\UART\UART.o" 
	-$(RM) "RF_Amplifier.d" "ti_msp_dl_config.d" "startup_mspm0g350x_ticlang.d" "HARDWARE\ADC\ADC.d" "HARDWARE\BTN\BTN.d" "HARDWARE\DAC\DAC.d" "HARDWARE\FREQ_DECODER\FREQ_DECODER.d" "HARDWARE\LCD\HMI_GUI.d" "HARDWARE\LCD\PAGE_HANDLE.d" "HARDWARE\LCD\tjc_usart_hmi.d" "HARDWARE\ROTARY_ENCODER\ROTARY_ENCODER.d" "HARDWARE\TICK\Tick.d" "HARDWARE\UART\UART.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

