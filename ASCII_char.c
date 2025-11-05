#include<lpc21xx.h>
#include"header.h"
main()
 {
	u32 i,n;
	s8 s[20];
	uart0_init(9600);
	while(1)
	{	
		uart0_tx_string("enter the ASCII number\r\n");
		uart0_rx_string(s,19);
		uart0_tx_string(s);
		uart0_tx_string("\r\n");
		for(i=0,n=0;s[i];i++)
		n=n*10+(s[i]-48);

		uart0_tx_string("character is :");
		uart0_tx(n);
		uart0_tx_string("\r\n");
	}
}