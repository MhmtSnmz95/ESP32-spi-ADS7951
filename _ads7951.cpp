#include "_ads7951.h"
#include "_spi.h"

void ADS7951_INIT(){
  setADS7951Mode(1);
}

void ADS7951_INIT1(){
  setADS7951Mode1(1);
}

uint16_t maskADS795xVal(uint16_t val){
  uint16_t retVal = 0;
  retVal = 0x0FFF & val;
  return retVal;
}
uint16_t maskADS795xChannelID(uint16_t val){
  uint16_t retVal = 0;
  retVal = ((0xF000&val)>>12) ;
    return retVal;
}

void setADS7951Mode(int _mode){
    switch (_mode) {
        case 1:            // auto -1 mode
           _sendCommand(0x1000);
           _sendCommand(0x2800);
           _sendCommand(0x00FF);
            break;
        case 2:            // auto -2 mode
            /**     dont use **/
            break;
        case 3:            // manual mode
            /**     dont use **/
            break;
        default:
            break;
    }
}
void setADS7951Mode1(int _mode){
    switch (_mode) {
        case 1:            // auto -1 mode
           _sendCommand1(0x1000);
           _sendCommand1(0x2800);
           _sendCommand1(0x00FF);
            break;
        case 2:            // auto -2 mode
            /**     dont use **/
            break;
        case 3:            // manual mode
            /**     dont use **/
            break;
        default:
            break;
    }
}

/*
 * burda spı moduna dıkkat et olması gereken 01
 */
uint16_t* readAdcAllChannel(){
    uint16_t ret=0;
    uint16_t maskRet=0;
    static uint16_t adcValArray[8];
    for(;;){
        ret =_sendCommand(0x0000);
        maskRet = maskADS795xChannelID(ret);
       
        if(maskRet == 0)
            break;
    }
    adcValArray[0] = maskADS795xVal(ret);

    ret =_sendCommand(0x0000);
    adcValArray[1] = maskADS795xVal(ret); 

    ret =_sendCommand(0x0000);
    adcValArray[2] = maskADS795xVal(ret); 

    ret =_sendCommand(0x0000);
    adcValArray[3] = maskADS795xVal(ret); 

    ret =_sendCommand(0x0000);
    adcValArray[4] = maskADS795xVal(ret);  

    ret =_sendCommand(0x0000);
    adcValArray[5] = maskADS795xVal(ret); 

    ret =_sendCommand(0x0000);
    adcValArray[6] = maskADS795xVal(ret);   

    ret =_sendCommand(0x0000);
    adcValArray[7] = maskADS795xVal(ret); 


    return &adcValArray[0];

}
uint16_t* readAdcAllChannel1(){
    uint16_t ret=0;
    uint16_t maskRet=0;
    static uint16_t adcValArray[8];
    for(;;){
        ret =_sendCommand1(0x0000);
        maskRet = maskADS795xChannelID(ret);
        if(maskRet == 0)
            break;
    }
    adcValArray[0] = maskADS795xVal(ret);

    ret =_sendCommand1(0x0000);
    adcValArray[1] = maskADS795xVal(ret); 

    ret =_sendCommand1(0x0000);
    adcValArray[2] = maskADS795xVal(ret); 

    ret =_sendCommand1(0x0000);
    adcValArray[3] = maskADS795xVal(ret); 

    ret =_sendCommand1(0x0000);
    adcValArray[4] = maskADS795xVal(ret);  

    ret =_sendCommand1(0x0000);
    adcValArray[5] = maskADS795xVal(ret); 

    ret =_sendCommand1(0x0000);
    adcValArray[6] = maskADS795xVal(ret);   

    ret =_sendCommand1(0x0000);
    adcValArray[7] = maskADS795xVal(ret); 
    return &adcValArray[0];

}
uint16_t _sendCommand(uint16_t val){
    uint16_t ret;
    ret = _sendSpiByte_16(val);
    return ret;
}
uint16_t _sendCommand1(uint16_t val){
    uint16_t ret;
    ret = _sendSpiByte1_16(val);
    return ret;
}
float readAdcChannel_mV(int _channel){
  float mV=0;
  uint16_t retVal=0;
  uint16_t * adcArray = readAdcAllChannel();
  retVal = adcArray[_channel];
  mV = ((retVal * 2500 )/4095);
  if(mV<0){
    mV=0;
  }
  return mV;
}
float readAdcChannel_mV1(int _channel){
  float mV=0;
  uint16_t retVal=0;
  uint16_t * adcArray = readAdcAllChannel1();
  retVal = adcArray[_channel];
  mV = ((retVal * 2500 )/4095);
  if(mV<0){
    mV=0;
  }
  return mV;
}
