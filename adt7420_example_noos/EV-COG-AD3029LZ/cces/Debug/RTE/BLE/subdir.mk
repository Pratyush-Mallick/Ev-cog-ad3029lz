################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.8.3/ARM/packs/AnalogDevices/ADI-BleSoftware/1.0.0/Source/communication/ble/radio/adi_ble_logevent.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.8.3/ARM/packs/AnalogDevices/ADI-BleSoftware/1.0.0/Source/communication/ble/framework/noos/adi_ble_noos.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.8.3/ARM/packs/AnalogDevices/ADI-BleSoftware/1.0.0/Source/communication/ble/radio/adi_ble_radio.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.8.3/ARM/packs/AnalogDevices/ADI-BleSoftware/1.0.0/Source/communication/ble/transport/adi_ble_transport.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.8.3/ARM/packs/AnalogDevices/ADI-BleSoftware/1.0.0/Source/communication/common/adi_timestamp.c 

SRC_OBJS += \
./RTE/BLE/adi_ble_logevent.o \
./RTE/BLE/adi_ble_noos.o \
./RTE/BLE/adi_ble_radio.o \
./RTE/BLE/adi_ble_transport.o \
./RTE/BLE/adi_timestamp.o 

C_DEPS += \
./RTE/BLE/adi_ble_logevent.d \
./RTE/BLE/adi_ble_noos.d \
./RTE/BLE/adi_ble_radio.d \
./RTE/BLE/adi_ble_transport.d \
./RTE/BLE/adi_timestamp.d 


# Each subdirectory must supply rules for building sources it contributes
RTE/BLE/adi_ble_logevent.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.8.3/ARM/packs/AnalogDevices/ADI-BleSoftware/1.0.0/Source/communication/ble/radio/adi_ble_logevent.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -DADI_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM3029__ -D__SILICON_REVISION__=0xffff @includes-6fa17b011ab78a8f117c727af2b9b094.txt -Wall -c -mcpu=cortex-m3 -mthumb -MMD -MP -MF"RTE/BLE/adi_ble_logevent.d" -MT"RTE/BLE/adi_ble_logevent.d" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/BLE/adi_ble_noos.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.8.3/ARM/packs/AnalogDevices/ADI-BleSoftware/1.0.0/Source/communication/ble/framework/noos/adi_ble_noos.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -DADI_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM3029__ -D__SILICON_REVISION__=0xffff @includes-6fa17b011ab78a8f117c727af2b9b094.txt -Wall -c -mcpu=cortex-m3 -mthumb -MMD -MP -MF"RTE/BLE/adi_ble_noos.d" -MT"RTE/BLE/adi_ble_noos.d" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/BLE/adi_ble_radio.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.8.3/ARM/packs/AnalogDevices/ADI-BleSoftware/1.0.0/Source/communication/ble/radio/adi_ble_radio.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -DADI_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM3029__ -D__SILICON_REVISION__=0xffff @includes-6fa17b011ab78a8f117c727af2b9b094.txt -Wall -c -mcpu=cortex-m3 -mthumb -MMD -MP -MF"RTE/BLE/adi_ble_radio.d" -MT"RTE/BLE/adi_ble_radio.d" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/BLE/adi_ble_transport.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.8.3/ARM/packs/AnalogDevices/ADI-BleSoftware/1.0.0/Source/communication/ble/transport/adi_ble_transport.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -DADI_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM3029__ -D__SILICON_REVISION__=0xffff @includes-6fa17b011ab78a8f117c727af2b9b094.txt -Wall -c -mcpu=cortex-m3 -mthumb -MMD -MP -MF"RTE/BLE/adi_ble_transport.d" -MT"RTE/BLE/adi_ble_transport.d" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/BLE/adi_timestamp.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.8.3/ARM/packs/AnalogDevices/ADI-BleSoftware/1.0.0/Source/communication/common/adi_timestamp.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -DADI_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM3029__ -D__SILICON_REVISION__=0xffff @includes-6fa17b011ab78a8f117c727af2b9b094.txt -Wall -c -mcpu=cortex-m3 -mthumb -MMD -MP -MF"RTE/BLE/adi_timestamp.d" -MT"RTE/BLE/adi_timestamp.d" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


