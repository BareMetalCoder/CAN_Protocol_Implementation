#include<lpc21xx.h>
#include"header.h"
void spi0_init(void)
{
	PINSEL0|=0x1500;   //p0.4 -> sck0
					 //p0.5 -> MISO0
					 //p0.6 -> MOSI
					 
	IODIR0|=cs0;  	//p0.7 is out direction
	IOSET0=cs0;	    //diselct slave
	S0SPCR=0x20;   //CPOL=CPHA=0;
				  //select master mode
				   //select MSB first
	S0SPCCR=15;   //SPI clock is 1 mbps

	/* SPI0 data tx function */
}
	#define SPIF ((S0SPSR>>7)&1)
	u8 spi0(u8 data)
	{
		S0SPDR=data;
		while(SPIF==0);
		return S0SPDR;
	}
				