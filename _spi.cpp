#include "_spi.h"  
#include <SPI.h>

union {
  uint16_t val;
  struct {
    uint8_t msb;
    uint8_t lsb;
    };
} in, out,in1, out1;

//SPIClass * vspi = NULL;
SPIClass* _spi;
static const int spiClk = 1000000; //1 MHz
/*
 * //SCLK = 18, MISO = 19, MOSI = 23, SS = 5
  vspi->begin();
#else
  //alternatively route through GPIO pins of your choice
  vspi->begin(VSPI_SCLK, VSPI_MISO, VSPI_MOSI, VSPI_SS); //SCLK, MISO, MOSI, SS
  
 */
void spi_INIT(){
  _spi = new SPIClass(VSPI);
  _spi->begin(18,19,23); // spi 18 pini spi clk hattı ,19. pin spi_miso ,23. pin  spi_mosi
  pinMode(VSPI_SS1, OUTPUT); //HSPI_SS SS
  digitalWrite(VSPI_SS1, HIGH);
  pinMode(VSPI_SS2, OUTPUT); //HSPI_SS SS
  digitalWrite(VSPI_SS2, HIGH);         
}  
uint16_t _sendSpiByte_16(uint16_t _msg){
  //_spi->begin(18,19,23);
  in.val = _msg;
  uint16_t retVal = 0;
  _spi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE1));
  digitalWrite(VSPI_SS1, LOW); //pull SS slow to prep other end for transfer  
  out.lsb = _spi->transfer(in.lsb);
  out.msb = _spi->transfer(in.msb); 
  digitalWrite(VSPI_SS1, HIGH); //pull ss high to signify end of data transfer
  _spi->endTransaction();
//  _spi->end();
  return out.val;
}
uint16_t _sendSpiByte1_16(uint16_t _msg){
 // _spi->begin(18,19,23);
  in1.val = _msg;
  uint16_t retVal = 0;
  _spi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE1));
  digitalWrite(VSPI_SS2, LOW); //pull SS slow to prep other end for transfer  
  out1.lsb = _spi->transfer(in1.lsb);
  out1.msb = _spi->transfer(in1.msb); 
  digitalWrite(VSPI_SS2, HIGH); //pull ss high to signify end of data transfer
  _spi->endTransaction();
//  _spi->end();
  return out1.val;
}
