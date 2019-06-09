################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Asus/Desktop/JEWEL\ BEETLE/ADI/workspace/examples/ev-cog-ad3029lz_bsp_3.1.0/adt7420_example_noos/EV-COG-AD3029LZ/pinmux.c 

CPP_SRCS += \
C:/Users/Asus/Desktop/JEWEL\ BEETLE/ADI/workspace/examples/ev-cog-ad3029lz_bsp_3.1.0/adt7420_example_noos/adt7420_app.cpp 

SRC_OBJS += \
./adt7420_app.o \
./pinmux.o 

C_DEPS += \
./pinmux.d 

CPP_DEPS += \
./adt7420_app.d 


# Each subdirectory must supply rules for building sources it contributes
adt7420_app.o: C:/Users/Asus/Desktop/JEWEL\ BEETLE/ADI/workspace/examples/ev-cog-ad3029lz_bsp_3.1.0/adt7420_example_noos/adt7420_app.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -DADI_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM3029__ -D__SILICON_REVISION__=0xffff @includes-fa17de00122a6c7a501db96818522885.txt -Wall -c -mcpu=cortex-m3 -mthumb -MMD -MP -MF"adt7420_app.d" -MT"adt7420_app.d" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

pinmux.o: C:/Users/Asus/Desktop/JEWEL\ BEETLE/ADI/workspace/examples/ev-cog-ad3029lz_bsp_3.1.0/adt7420_example_noos/EV-COG-AD3029LZ/pinmux.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -DADI_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM3029__ -D__SILICON_REVISION__=0xffff @includes-6fa17b011ab78a8f117c727af2b9b094.txt -Wall -c -mcpu=cortex-m3 -mthumb -MMD -MP -MF"pinmux.d" -MT"pinmux.d" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


