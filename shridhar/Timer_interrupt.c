#include<lpc21xx.h>
#include"header.h"
#define led (3<<17)
#define led1 (1<<17)
extern u8 temp,flag;
int main()
{
	config_VIC_for_timer1();
	en_timer1_interrupt();
	IODIR0=led;
	IOSET0=led;
	while(1)
	{
	IOCLR0=led1;
	delay_sec(1);
	IOSET0=led1;
	delay_sec(1);
	}
}
	