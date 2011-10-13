#ifndef AP_ADC_ADS7844_H
#define AP_ADC_ADS7844_H

#define bit_set(p,m)   ((p) |= ( 1<<m))
#define bit_clear(p,m) ((p) &= ~(1<<m))

// We use Serial Port 2 in SPI Mode
#define ADC_DATAOUT     51    // MOSI
#define ADC_DATAIN      50    // MISO
#define ADC_SPICLOCK    52    // SCK
#define ADC_CHIP_SELECT 33    // PC4   9 // PH6  Puerto:0x08 Bit mask : 0x40
#define ADC_FILTER_SIZE	8

#include "AP_ADC.h"
#include <inttypes.h>

class AP_ADC_ADS7844 : public AP_ADC
{
	public:
	AP_ADC_ADS7844();  // Constructor
	void 	Init();

	// Read 1 sensor value
	int Ch(unsigned char ch_num);

	// Read 6 sensors at once
	uint32_t Ch6(const uint8_t *channel_numbers, int *result);
	bool	filter_result;

	private:
	uint16_t 		_filter[3][ADC_FILTER_SIZE];
	uint8_t			_filter_index;

};

#endif