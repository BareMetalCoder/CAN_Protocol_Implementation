#include<lpc21xx.h>
#include "header.h"
#define LED 0xFF
main()
{
 ///////////////assignment/////////////////////////////
/* int i;
IODIR0=LED; //setting p0.0 to p0.2 as o/p direction
//turn off the all theb leds in active low led
while(1)
{
//////////even led on//////////////////////////	 
	for(i=0;i<=7;i=i+2)
	{
		IOSET0=1<<i;// p0.0 to p0.2 tuen off leds
	delay_ms(100);
	IOCLR0=1<<i;// p0.0 to p0.2 turn on leds
	delay_ms(100);
	//IOSET0=1<<i;// p0.0 to p0.2 tuen off leds
	//delay_ms(100);
	}
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


















	/*IODIR0=1<<17|1<<18|1<<19;
	IOSET0=1<<17|1<<18|601<<19;//turn off led for active low led //IF YOU USING ACTIVR HIGH LED THEN NOT USE THIS IOSET=1
	
	while(1)
	{
		delay_ms(100);
			IOCLR0=1<<17;
		delay_ms(500);
			IOSET0=1<<17;
		delay_ms(500);
			IOCLR0=1<<18;
		delay_ms(500);
			IOSET0=1<<18;
		delay_ms(500);
			IOCLR0=1<<19;
		delay_ms(500);
			IOSET0=1<<19;

}
}
	 */
////////////// 3 led blink use 1sec delay////////////////////////


/*IODIR0=7<<0; //setting p0.0 to p0.2 as o/p direction
IOSET0=7<<0;//turn off the all theb leds in active low led
while(1)
{
	IOCLR0=7<<0;// p0.0 to p0.2 turn on leds
	delay_ms(100);
	IOSET0=7<<0;// p0.0 to p0.2 tuen off leds
	delay_ms(100);
}
} */

//////////using MACRO ////////////////////////////////////////

/*IODIR0=LED; //setting p0.0 to p0.2 as o/p direction
IOSET0=LED;//turn off the all theb leds in active low led
while(1)
{
	IOCLR0=LED;// p0.0 to p0.2 turn on leds
	delay_ms(100);
	IOSET0=LED;// p0.0 to p0.2 tuen off leds
	delay_ms(100);

} */

//////////////shift 8 AL led using macro////////////////////
/*int i;
IODIR0=LED; //setting p0.0 to p0.2 as o/p direction
//IOSET0=LED;//turn off the all theb leds in active low led
while(1)
{
	for(i=0;i<=LED;i++)// rotatig loop for all 8 leds 
	{
		IOCLR0=i;// p0.0 to p0.2 turn on leds
	delay_ms(1);
		IOSET0=i;// p0.0 to p0.2 tuen off leds
	delay_ms(1);
	}
} 
}*/

////////////////display binary format of 3 leds/////////////


int i;
IODIR0=LED; //setting p0.0 to p0.2 as o/p direction
IOSET0=LED;//turn off the all theb leds in active low led
while(1)
{
	for(i=0;i<=8;i++)// rotatig loop for all 8 leds 
	{
		IOCLR0=i<<0;// p0.0 to p0.2 turn on leds
	delay_ms(100);
		IOSET0=i<<0;// p0.0 to p0.2 tuen off leds
	delay_ms(100);
	}
}
}


