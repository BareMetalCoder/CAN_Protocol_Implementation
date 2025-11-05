#include<lpc21xx.h>
#include"header.h"
int main()
{	
	u8 a,b,c,y;
	uart0_init(9600);
	uart0_tx_string("calc\n\r");
	while(1)
	{
		uart0_tx_string("enter the input \n\r");
		a=uart0_rx();
		uart0_tx(a);

		c=uart0_rx();
		uart0_tx(c);

		b=uart0_rx();
		uart0_tx(b);

		while(uart0_rx()!='\r');
		if(c=='+')
		y=(a-48)+(b-48);
		else if(c=='-')
		{
			if(b>a)
			y=(b-48)-(a-48);
			else
			y=(a-48)-(b-48);
		}
		else if(c=='*')
			y=(a-48)*(b-48);
		else if(c=='/')
			y=(a-48)/(b-48);
		else if(c=='%')
			y=(a-48)%(b-48);

		uart0_tx_string("\r\n result=");
		if(c=='_'&&b>a)
		uart0_tx_string("\r\n");
		uart0_tx((y/10)+48);
		uart0_tx((y%10)+48);
		uart0_tx_string("\n\r");
	}
}
		
			