
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
	s32 i,j,l;
	IODIR0|=led;
	uart0_init(9600);
	config_VIC_for_uart0();
	en_uart0_interrupt();
//	lcd_init();
	while(1)
	{
		IOSET0=led;	  //led off
		delay_ms(100);
		IOCLR0=led;   //led_on
		delay_ms(100);
	
		if(flag)
		{	
			flag=0;
				 
		for(l=0;arr[l];l++);
		for(i=0,j=l-1;i<j;i++,j--)
		{
			if(arr[i]!=arr[j])
			break;
		}
		if(arr[i]==arr[j])
		uart0_tx_string("yes palindroma\r\n");
		else 
		uart0_tx_string("not palindroma\r\n");
   }
}
}
/*#include<lpc21xx.h>
#include "h.h"
#define led (7<<17)
u8 flag
extern s8 arr[20];
int main()
{
  	s32 i,j,l;
	IODIR0|=led;
	uart0_init(9600);
	config_VIC_for_uart0();
	en_uart0_interrupt();
	while(1)
	{
		IOSET0=led;
		delay_ms(100);
		IOCLR0=led;
	`	delay_ms(100);

		if(flag==1)
		{
			flag=0;
				 
		for(l=0;arr[l];l++);
		for(i=0,j=l-1;i<j;i++,j--)
		{
			if(arr[i]!=s[j])
			break;
		}
		if(arr[i]==arr[j])
		uart0_tx_string("yes palindroma\r\n");
		else 
		uart0_tx_string("not palindroma\r\n");
   }
}
}*/
/*string palindrom---------------*/	
//{
//	s8 s[10];
//	s32 i,j,l;
//	uart0_init(9600);
//	while(1)
//	{
//		uart0_tx_string("enter the the string\r\n");
//		uart0_rx_string(s,19);
//		uart0_tx_string(s);
//		uart0_tx_string("\r\n");
//
//		for(l=0;s[l];l++);
//		for(i=0,j=l-1;i<j;i++,j--)
//		{
//			if(s[i]!=s[j])
//			break;
//		}
//		if(s[i]==s[j])
//		uart0_tx_string("yes palindroma\r\n");
//		else 
//		uart0_tx_string("not palindroma\r\n");
//   }
//}
