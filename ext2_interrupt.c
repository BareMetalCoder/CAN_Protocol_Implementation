#include<lpc21xx.h>
#include"header.h"

#define LED2 (1<<18)
void EINT0_handler(void) __irq
	{
	static int f1;
		f1^=1;      //toggle the flag vcalue
	   if(f1)
	   IOCLR0=LED2; 
	    else 
	   IOSET0=LED2;

		EXTINT=0x1;
		VICVectAddr=0;
	}
void config_VIC_for_extern(void)
{
	VICIntSelect=0;
	VICVectCntl0=14|(1<<5);
	VICVectAddr0=(u32) EINT0_handler;
	VICIntEnable|=(1<<14);
}
void en_extern_interrupt(void)
{
	PINSEL1|=0X1;
	EXTMODE=0x1;
	EXTPOLAR=0x0;
}
