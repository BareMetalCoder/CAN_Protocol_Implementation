#include<lpc21xx.h>
#include"heder.h"
#define LED 0xFF
main()
{
 
 int i;
IODIR0=LED; //setting p0.0 to p0.2 as o/p direction
//turn off the all theb leds in active low led
IOSET0=LED;
while(1)
{
//////////even led on//////////////////////////	 
	for(i=0;i<=7;i=i+2)
	{
		IOSET0=1<<i;// p0.0 to p0.2 tuen off leds
	delay_ms(100);
	IOCLR0=1<<i;// p0.0 to p0.2 turn on leds
	delay_ms(100);
	IOSET0=1<<i;// p0.0 to p0.2 tuen off leds
	delay_ms(100);
	}
/////////////////////odd even led on /////////////////////////
		for(i=1;i<=7;i=i+2)
	{
		IOSET0=1<<i;// p0.0 to p0.2 tuen off leds
	delay_ms(100);
	IOCLR0=1<<i;// p0.0 to p0.2 turn on leds
	delay_ms(100);
	IOSET0=1<<i;// p0.0 to p0.2 tuen off leds
	delay_ms(100);
	}
}
}
