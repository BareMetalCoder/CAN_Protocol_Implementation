#include<lpc21xx.h>
#include"header.h"
int main()
{	
	u8 a[2],b[2],c;
	u16 y=0,flag=0;
	uart0_init(9600);
	uart0_tx_string("calc\n\r");
	while(1)
	{
		uart0_tx_string("enter the input \n\r");
		a[0]=uart0_rx();
		uart0_tx(a[0]);
		a[1]=uart0_rx();
		uart0_tx(a[1]);

		c=uart0_rx();
		uart0_tx(c);

		b[0]=uart0_rx();
		uart0_tx(b[0]);
		b[1]=uart0_rx();
		uart0_tx(b[1]);


		while(uart0_rx()!='\r');
		switch (c)
		{
			case '+':
					y=((a[0]-'0') * 10 + (a[1]-'0')) + ((b[0]-'0') * 10 + (b[1]-'0'));
					break;
			case '-':
					if(((a[0]-'0') * 10 + (a[1]-'0'))>((b[0]-'0') * 10 + (b[1]-'0')))
					y=((a[0]-'0') * 10 + (a[1]-'0')) - ((b[0]-'0') * 10 + (b[1]-'0'));
					else
					{
							y=((b[0]-'0') * 10 + (b[1]-'0')) - ((a[0]-'0') * 10 + (a[1]-'0'));
							flag=1;
					}
					break;
			case '*':
					y=((a[0]-'0') * 10 + (a[1]-'0')) * ((b[0]-'0') * 10 + (b[1]-'0'));
					break;
			case '/':
					y=((a[0]-'0') * 10 + (a[1]-'0')) / ((b[0]-'0') * 10 + (b[1]-'0'));
					break;
			case '%':
					y=((a[0]-'0') * 10 + (a[1]-'0')) % ((b[0]-'0') * 10 + (b[1]-'0'));
					break;
		}
		uart0_tx_string("\r\n result=");
		if(flag==1)
		{
			uart0_tx('-');
		}
		if(y>999)
		{
		
			uart0_tx((y/1000)+48);
			uart0_tx(((y/100)%10)+48);
			uart0_tx(((y/10)%10)+48);
			uart0_tx((y%10)+48);
			uart0_tx_string("\n\r");
		}
		else if(y>99)
		{
	
			uart0_tx((y/100)+48);
			uart0_tx(((y/100)%10)+48);
			uart0_tx(((y/10)%10)+48);
			uart0_tx((y%10)+48);
			uart0_tx_string("\n\r");
		}
		else
		{

			uart0_tx(((y/10)%10)+48);
			uart0_tx((y%10)+48);
			uart0_tx_string("\n\r");
		}
	}
}
		
			