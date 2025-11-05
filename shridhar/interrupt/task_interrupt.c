//task1: if sw  is pressed then toggle the led (polling method)
//task: if data rx in the uart0 then print it on the LCD (interrupt method)
#include<lpc21xx.h>
#include"header.h"
//u32 main_cnt;
#define sw ((IOPIN0>>14)&1)
#define LED (7<<17)
u8 temp,flag;

main()
{
	u8 f1=0;
	IODIR0=LED;
	IOSET0=LED;  

		lcd_init();
		uart0_init(9600);
		config_VIC_for_uart0();
		en_uart0_interrupt();
		lcd_cmd(0x01);
while(1)
{
	if(sw==0)
	{
	   while(sw==0); // wait for sw release
	   f1^=1;      //toggle the flag vcalue
	   if(f1)
	   IOCLR0=LED; 
	    else 
	   IOSET0=LED;   //led off  
	}
		//task 2
	if(flag)
	{
		flag=0;
		lcd_data(temp);
//     	delay_ms(2);
	}
}
}
