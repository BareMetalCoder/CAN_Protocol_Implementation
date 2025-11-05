#include<lpc21xx.h>
#include"header.h"
#define led2 (1<<18)
u8 temp,flag;
void timer1_handle(void) __irq
{
	if(flag)
	{
		IOSET0=led2;
		flag=0;
	}
	else 
	{
		IOCLR0=led2;
		flag=1;
	}
	T1IR=1;
	VICVectAddr=0;
}
void config_VIC_for_timer1(void)
{
	VICIntSelect=0;
	VICVectCntl0=5|(1<<5);
	VICVectAddr0=(u32) timer1_handle;
	VICIntEnable|=(1<<5);
}
void en_timer1_interrupt(void)
{
	T1TC=0;
	T1PC=0;
	T1PR=15000-1;
	T1MR0=100;
	T1MCR=3;
	T1TCR=1;
}
