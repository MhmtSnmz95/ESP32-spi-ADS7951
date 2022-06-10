#ifndef _SPI
#define _SPI
#if (ARDUINO >=100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define VSPI_MISO   19
#define VSPI_MOSI   23
#define VSPI_SCLK   18

#define VSPI_SS1     32 // ads1

#define VSPI_SS2     12 // ads2

void spi_INIT();
uint16_t _sendSpiByte_16(uint16_t _msg);
uint16_t _sendCommand(uint16_t val);
uint16_t _sendCommand1(uint16_t val);
uint16_t _sendSpiByte1_16(uint16_t _msg);

#endif
