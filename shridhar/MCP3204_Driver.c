#include<lpc21xx.h>
#include"header.h"

u16 read_mcp3204(u8 ch_num)
{
	u8 byteL=0,byteH=0;
	u16 result=0;
	ch_num<<=6;    //set the ch_number

	IOCLR0=cs0; //select slave
	spi0(0x06);	//start bit SGL mnode D2
	byteH=spi0(ch_num);  //CH select
	byteL=spi0(0x00);
	IOSET0=cs0; //diselect slave

	byteH&=0x0f;  //mask higher nibble
	result=(byteH<<8)|byteL;  // merg result
	return result;
}
	