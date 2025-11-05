#include<LPC21xx.h>
#include"header.h"

#define trigger (1<<5)
#define echo ((IOPIN0>>6)&1)
void ultrasonic_init()
{
	IODIR0|=trigger;
	IOCLR0|=trigger;
}
u32 ultrasonic_sensor()
{
	u32 echotime=0;
	float distance=0;
	
	IOSET0|=trigger;
	delay_us(10);
	IOCLR0|=trigger;
	
		while(echo==0);				 
			T1PC=0;
			T1PR=15-1;
			T1TC=0;
			T1TCR=1;
			while(echo)
			{
				if(T1TC>25000)
				break;
			}
			T1TCR=0;

			echotime=T1TC;

			distance=(0.0343*echotime)/2;
			return distance;
		}
