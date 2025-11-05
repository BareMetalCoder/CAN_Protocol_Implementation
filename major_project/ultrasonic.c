#include<lpc21xx.h>
#include"header.h"
#define trig (1<<8)						//P0.8
#define echo (IO0PIN&(1<<9))			//P0.9 as EINT3
void ultrasonic_init()
{
	IO0DIR|=(1<<8);
	T0TCR=0;
	T0PR=59;
}
void send_pulse()
{
	T0TC=0;
	T0PC=0;
	IOSET0=trig;							//trig=1
	delay_ms(10);						//10us delay
	IOCLR0=trig;							//trig=0
}
unsigned int get_range()
{
	unsigned int get=0;
	send_pulse();
	while(!echo);
	T0TCR=0x01;
	while(echo);
	T0TCR=0;
	get=T0TC;
	if(get<38000)
	get=get/59;
	else
	get=0;
	return get;
}

