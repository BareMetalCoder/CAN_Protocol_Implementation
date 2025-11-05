#include<lpc21xx.h>
#include "header.h"
#define LED 0xFF
main()
{
/*
////////////assignment 2//////////////////////////
IODIR0=LED;
IOSET0=LED;
	while(1)
	{
		int i,j;
		for(i=0,j=7;i<=7;i++,j--)
		{
			IOCLR0=1<<i;
			IOCLR0=1<<j;
			delay_ms(200);
			IOSET0=1<<i;
			IOSET0=1<<j;
			delay_ms(25);
		}
	}
} 
  */
/*
#include<lpc21xx.h>
#include "header.h"
#define LED 0xFF
main()
{
////////////assignment 2//////////////////////////
int i=0,j=1;
IODIR0=LED;
IOSET0=LED;
	//while(1)
//	{		
		for( ; ;i++,j++)
		{
			//if (k>7)
		//k=0;
		if (j>7)
		j=0;
		if (i>7)
		i=0;
			IOCLR0=1<<i;
			IOCLR0=1<<j;
		//	IOCLR0=1<<k;
			delay_ms(100);
			IOSET0=1<<i;
			IOSET0=1<<j;
		//	IOSET0=1<<k;
			delay_ms(100);
		}
		
	//}
}
 */

















 ///////////////assignment/////////////////////////////
int i;
IODIR0=LED; //setting p0.0 to p0.2 as o/p direction
//turn off the all theb leds in active low led
while(1)
{
//////////even led on//////////////////////////
/*	for(i=0;i<=7;i=i+2)
	{
		IOSET0=1<<i;// p0.0 to p0.2 tuen off leds
	delay_ms(100);
	IOCLR0=1<<i;// p0.0 to p0.2 turn on leds
	delay_ms(100);
	//IOSET0=1<<i;// p0.0 to p0.2 tuen off leds
	//delay_ms(100);
	}
  */
/////////////////////odd even led on /////////////////////////
		for(i=1;i<=7;i=i+2)
	{
		IOSET0=1<<i;// p0.0 to p0.2 tuen off leds
	delay_ms(100);
	IOCLR0=1<<i;// p0.0 to p0.2 turn on leds
	delay_ms(100);
	//IOSET0=1<<i;// p0.0 to p0.2 tuen off leds
	//delay_ms(100);
	}
}
}

