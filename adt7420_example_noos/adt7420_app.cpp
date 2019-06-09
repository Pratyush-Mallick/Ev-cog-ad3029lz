/*!
 *****************************************************************************
   @file:    adt7420_app.cpp

   @brief:   ADT7420 temperature sensor demo

   @details: Example demonstrating the temperature sensor functionality
  -----------------------------------------------------------------------------

Copyright (c) 2017 Analog Devices, Inc.

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
  - Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
  - Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
  - Modified versions of the software must be conspicuously marked as such.
  - This software is licensed solely and exclusively for use with processors
    manufactured by or for Analog Devices, Inc.
  - This software may not be combined or merged with other code in any manner
    that would cause the software to become subject to terms and conditions
    which differ from those listed here.
  - Neither the name of Analog Devices, Inc. nor the names of its
    contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.
  - The use of this software may or may not infringe the patent rights of one
    or more patent holders.  This license does not release you from the
    requirement that you obtain separate licenses from these patent holders
    to use this software.

THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES, INC. AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
TITLE, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN
NO EVENT SHALL ANALOG DEVICES, INC. OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, PUNITIVE OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, DAMAGES ARISING OUT OF CLAIMS OF INTELLECTUAL
PROPERTY RIGHTS INFRINGEMENT; PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*****************************************************************************/


#include "adt7420_app.h"
#include <common.h>
#include <common/adi_timestamp.h>
#include <drivers/gpio/adi_gpio.h>
#include <base_sensor/adi_sensor_errors.h>
#include "bme680.h"
#include "adi_adt7420_config.h"

using namespace adi_sensor_swpack;

static void TempStandaloneMode();
static void user_delay_ms(uint32_t mSec);

SENSOR_RESULT open();
struct bme680_dev gas_sensor;
struct bme680_field_data data;
uint8_t dat;
int8_t i2c_read(uint8_t devid, uint8_t regaddr, uint8_t *dat, uint16_t leng);
int8_t i2c_write(uint8_t devidw, uint8_t regaddrw, uint8_t *datw, uint16_t lengw);

SENSOR_RESULT   eSensorResult;
ADT7420         adt7420;
Temperature     *pTemp = &adt7420;

/* Local Functions */
static void InitSystem(void);

/*!
 * @brief      Main
 *
 * @details    Application entry point.
 *
 * @param [in] argc : Number of arguments (unused)
 *
 * @param [in] argv : Arguments (unused)
 *
 */

int main(int argc, char *argv[])
{




    /* Initialize the system */
    InitSystem();

    /* Open Temperature sensor */
    eSensorResult = open();


    /* You may assign a chip select identifier to be handled later */
    gas_sensor.dev_id = ADI_CFG_I2C_DEFAULT_ADDR ;
    gas_sensor.intf = BME680_I2C_INTF;
    gas_sensor.read = i2c_read;
    gas_sensor.write =i2c_write;
    gas_sensor.delay_ms = user_delay_ms;
    /* amb_temp can be set to 25 prior to configuring the gas sensor
     * or by performing a few temperature readings without operating the gas sensor.
     */
    gas_sensor.amb_temp = 25;

    int8_t rslt = BME680_OK;
    rslt = bme680_init(&gas_sensor);

    /* Open Temperature sensor */
    //DEBUG_MESSAGE("OPEN RESULT %d \n",eSensorResult);
    uint8_t set_required_settings;

       gas_sensor.tph_sett.os_hum  = BME680_OS_2X;
       gas_sensor.tph_sett.os_pres = BME680_OS_4X;
       gas_sensor.tph_sett.os_temp = BME680_OS_8X;
       gas_sensor.tph_sett.filter  = BME680_FILTER_SIZE_3;

    // Set the remaining gas sensor settings and link the heating profile
    gas_sensor.gas_sett.run_gas = BME680_ENABLE_GAS_MEAS;
    // Create a ramp heat waveform in 3 steps
    gas_sensor.gas_sett.heatr_temp  = 320; // degree Celsius
    gas_sensor.gas_sett.heatr_dur   = 150; // milliseconds

    // Select the power mode
    // Must be set before writing the sensor configuration
    gas_sensor.power_mode = BME680_FORCED_MODE;

    // Set the required sensor settings needed
    set_required_settings = BME680_OST_SEL | BME680_OSP_SEL | BME680_OSH_SEL | BME680_FILTER_SEL | BME680_GAS_SENSOR_SEL;

    // Set the desired sensor configuration
    rslt = bme680_set_sensor_settings ( set_required_settings, &gas_sensor );
    //DEBUG_MESSAGE("Settings Set %d \n",rslt );

    rslt = bme680_set_sensor_mode ( &gas_sensor );
    //DEBUG_MESSAGE("Power Set %d \n",rslt );

    // Get the total measurement duration so as to sleep or wait till the measurement is complete
    uint16_t meas_period;
    bme680_get_profile_dur ( &meas_period, &gas_sensor );


    // Let the callbacks take care of everything
    while(1) {


            rslt = bme680_get_sensor_data ( &data, &gas_sensor );
            //DEBUG_MESSAGE("data %d \n",data );


            // Prepare the data to be sent through the UART. NOTE: sprintf does NOT allow float numbers, that is why we round the number and plot them as integer
            // Avoid using measurements from an unstable heating setup
            DEBUG_MESSAGE("<T%.2f><P%.2f><H%.2f><G%d>\r\n", ( data.temperature/100.0f ), ( data.pressure / 100.0f ), ( data.humidity / 1000.0f ), data.gas_resistance );
                //DEBUG_MESSAGE("temperature  %d C.\r\n", data.temperature);
                //DEBUG_MESSAGE("humidity %d C.\r\n", data.humidity);
                //DEBUG_MESSAGE("gas %d C.\r\n", data.gas_resistance);
 			   // Delay till the measurement is ready
 			   user_delay_ms ( meas_period );


            // Trigger the next measurement if you would like to read data out continuously
            if ( gas_sensor.power_mode == BME680_FORCED_MODE ) {
                rslt = bme680_set_sensor_mode ( &gas_sensor );
                //DEBUG_MESSAGE("%d \n",rslt);
            }

                                                       // Reset the variable
        }


    }




/*!
 * @brief      Initializes the system
 *
 * @details    This function is responsible for initializing the pinmuxing, power service
 *             and bluetooth subsystem. It also initializes the realtime clock for to timestamp
 *             the outgoing sensor data packets.
 */
static void InitSystem(void)
{
    ADI_PWR_RESULT  ePwr;

    /* Explicitly disable the watchdog timer */
    *pREG_WDT0_CTL = 0x0u;

    /* Pinmux */
    adi_initpinmux();

    /* Initialize clocks */
    ePwr = adi_pwr_Init();
    DEBUG_RESULT("Error initializing the power service.\r\n", ePwr, ADI_PWR_SUCCESS);

    ePwr = adi_pwr_SetClockDivider(ADI_CLOCK_HCLK, 1u);
    DEBUG_RESULT("Error configuring the core clock.\r\n", ePwr, ADI_PWR_SUCCESS);

    ePwr = adi_pwr_SetClockDivider(ADI_CLOCK_PCLK, 1u);
    DEBUG_RESULT("Error configuring the peripheral clock.\r\n", ePwr, ADI_PWR_SUCCESS);

    common_Init();

#ifdef __EVCOG__
    /* Unlike the CUP board, the COG board I2C pins are pulled to a GPIO line instead of VDD */
    static uint8_t aGpioMemory[ADI_GPIO_MEMORY_SIZE];
    ADI_GPIO_RESULT eGpioResult = adi_gpio_Init(aGpioMemory, sizeof(aGpioMemory));
    DEBUG_RESULT("adi_gpio_Init", eGpioResult, ADI_GPIO_SUCCESS);
    eGpioResult = adi_gpio_OutputEnable(ADI_GPIO_PORT1, ADI_GPIO_PIN_12, true);
    DEBUG_RESULT("adi_gpio_OutputEnable", eGpioResult, ADI_GPIO_SUCCESS);
    eGpioResult = adi_gpio_SetHigh(ADI_GPIO_PORT1, ADI_GPIO_PIN_12);
    DEBUG_RESULT("adi_gpio_SetHigh", eGpioResult, ADI_GPIO_SUCCESS);
    eGpioResult = adi_gpio_UnInit();
    DEBUG_RESULT("adi_gpio_UnInit", eGpioResult, ADI_GPIO_SUCCESS);
#endif



    //DEBUG_MESSAGE("Starting ADT7420 temperature demo application\r\n");


}

/* General Delay milliseconds */
void user_delay_ms(uint32_t mSec)
{
	uint32_t loop = 0xA28 * mSec;
	while (loop > 0)
		loop--;
}


 int8_t i2c_read(uint8_t devid, uint8_t regaddr, uint8_t *dat, uint16_t leng)
 {
 	ADI_I2C_TRANSACTION sTransfer;
 	ADI_I2C_RESULT eI2cResult;
 	uint32_t nHwErrors;
 	uint8_t aPrologueData[5u];

 	/* Set slave address for ADI M355 gas sensor */
 	eI2cResult = adi_i2c_SetSlaveAddress(bme_i2c_handle,devid);

 	if (eI2cResult != ADI_I2C_SUCCESS)
 		return SET_SENSOR_ERROR(SENSOR_ERROR_I2C, eI2cResult);

 		aPrologueData[0] = regaddr;
 		sTransfer.pPrologue = &aPrologueData[0u];
 		sTransfer.nPrologueSize = 1u;
 		sTransfer.pData = dat ;
 		sTransfer.nDataSize = leng;
 		sTransfer.bReadNotWrite = true;
 		sTransfer.bRepeatStart = true;

 		eI2cResult = adi_i2c_ReadWrite(bme_i2c_handle, &sTransfer,
 					       &nHwErrors);
 		if (eI2cResult == ADI_I2C_SUCCESS) {
 			return BME680_OK;
 		}
 	}

 int8_t i2c_write(uint8_t devidw, uint8_t regaddrw, uint8_t *datw, uint16_t lengw)
 {
	ADI_I2C_TRANSACTION sTransferw;
	ADI_I2C_RESULT eI2cResultw;
	uint32_t nHwErrorsw;
	uint8_t aPrologueDataw[5u];

	/* Set slave address for ADI M355 gas sensor */
	eI2cResultw = adi_i2c_SetSlaveAddress(bme_i2c_handle,devidw);

	if (eI2cResultw != ADI_I2C_SUCCESS)
		return SET_SENSOR_ERROR(SENSOR_ERROR_I2C, eI2cResultw);
 		aPrologueDataw[0] = regaddrw;
 		sTransferw.pPrologue = &aPrologueDataw[0u];
 		sTransferw.nPrologueSize = 1u;
 		sTransferw.pData = datw;
 		sTransferw.nDataSize = lengw;
 		sTransferw.bReadNotWrite = false;
 		sTransferw.bRepeatStart = true;

 		eI2cResultw = adi_i2c_ReadWrite(bme_i2c_handle, &sTransferw,&nHwErrorsw);
 		if (eI2cResultw == ADI_I2C_SUCCESS) {
 			return BME680_OK;
 		}
 	}


 SENSOR_RESULT open()
 {
     ADI_I2C_RESULT eI2cResult = ADI_I2C_SUCCESS;
     pADI_GPIO0->DS |= (1 << 4) | (1 << 	5);

     eI2cResult = adi_i2c_Open(ADI_CFG_I2C_DEV_NUM, &bme_i2c_memory, ADI_I2C_MEMORY_SIZE, &bme_i2c_handle);
     if(eI2cResult == ADI_I2C_SUCCESS) {
         if((eI2cResult = adi_i2c_Reset(bme_i2c_handle)) == ADI_I2C_SUCCESS) {
             if((eI2cResult = adi_i2c_SetBitRate(bme_i2c_handle, ADI_CFG_I2C_BIT_RATE))  == ADI_I2C_SUCCESS) {
                 return (SENSOR_ERROR_NONE);
             }
         }
     }

     return (SET_SENSOR_ERROR(SENSOR_ERROR_I2C, eI2cResult));
 }



