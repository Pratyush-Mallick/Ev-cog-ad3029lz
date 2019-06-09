################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.8.3/ARM/packs/AnalogDevices/ADI-SensorSoftware/1.1.0/Source/sensor/temp/adt7420/adi_adt7420.cpp 

SRC_OBJS += \
./RTE/Sensors/adi_adt7420.o 

CPP_DEPS += \
./RTE/Sensors/adi_adt7420.d 


# Each subdirectory must supply rules for building sources it contributes
RTE/Sensors/adi_adt7420.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.8.3/ARM/packs/AnalogDevices/ADI-SensorSoftware/1.1.0/Source/sensor/temp/adt7420/adi_adt7420.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -DADI_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM3029__ -D__SILICON_REVISION__=0xffff @includes-fa17de00122a6c7a501db96818522885.txt -Wall -c -mcpu=cortex-m3 -mthumb -MMD -MP -MF"RTE/Sensors/adi_adt7420.d" -MT"RTE/Sensors/adi_adt7420.d" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


