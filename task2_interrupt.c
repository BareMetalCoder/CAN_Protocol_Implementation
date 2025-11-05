//task-1: led blinking 100 ms delay
//task-2: rx a string of 12 character using uart0& print it on the lcd 
#include<lpc21xx.h>
#include"header.h"
#define led (1<<17)  //p0.17
u8 flag;
s8 arr[13];
//extern u8 temp;
main()
{
	IODIR0|=led;
	uart0_init(9600);
	config_VIC_for_uart0();
	en_uart0_interrupt();
	lcd_init();
	while(1)
	{
		IOSET0=led;	  //led off
		delay_ms(100);
		IOCLR0=led;   //led_on
		delay_ms(100);

		if(flag)
		{	
			flag=0;
			lcd_cmd(0x1);
			lcd_cmd(0x80);
			lcd_string(arr);
		}
	}
}
	