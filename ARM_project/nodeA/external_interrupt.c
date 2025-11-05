#include<lpc21xx.h>
#include"can_header.h"
extern u32 gear;
CAN2 V1;
#define LED2 (1<<18)
void EINT0_handler(void) __irq
	{
		
		gear^=1;      //toggle the flag vcalue
		if(gear==1)
		{
		  V1.rtr=1;
		  V1.dlc=4;
		  V1.id=0x11;
		  can2_tx(); 
		}
		if(gear==0)
		{
		  V1.rtr=1;
		  V1.dlc=4;
		  V1.id=0x12;
		  can2_tx();  
		}
		EXTINT=0x1;
		VICVectAddr=0;
	}
void config_VIC_for_extern(void)
{
	VICIntSelect=0;
	VICIntEnable|=(1<<14);
	VICVectCntl0=14|(1<<5);
	VICVectAddr0=(u32) EINT0_handler;
	
}
void en_extern_interrupt(void)
{
	PINSEL1|=0X1;
	EXTMODE=0x1;
	EXTPOLAR=0x0;
}
