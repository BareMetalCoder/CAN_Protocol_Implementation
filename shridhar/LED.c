#include<lpc21xx.h>
main()
{
	IODIR0=255;
	IOSET0=0;
	delay(1000);
	IOCLR0=1;
	delay(1);
}


