#ifndef _ADS7951
#define _ADS7951
#if (ARDUINO >=100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


void ADS7951_INIT();
void ADS7951_INIT1();

uint16_t maskADS795xVal(uint16_t val);
uint16_t maskADS795xChannelID(uint16_t val);
void setADS7951Mode(int _mode);
void setADS7951Mode1(int _mode);

uint16_t* readAdcAllChannel();
uint16_t* readAdcAllChannel1();

float readAdcChannel_mV(int _channel);
float readAdcChannel_mV1(int _channel);


#endif
