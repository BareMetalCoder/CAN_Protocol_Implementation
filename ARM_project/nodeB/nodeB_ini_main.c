#include<lpc21xx.h>
#include"can_header.h"
CAN1 V1;
main()
{
can1_init();
uart0_init(9600);
uart0_tx_string("nodeB\r\n");
while(1)
{
	can1_rx();
	uart0_tx_hex(V1.id);
	uart0_tx(' ');        //space
	uart0_tx_hex((unsigned int)V1.dlc);
	uart0_tx(' ');
	uart0_tx_hex((unsigned int)V1.rtr);
	uart0_tx(' ');
	if(V1.rtr==0)
	{
		uart0_tx_hex(V1.byteA);
		uart0_tx(' ');
		uart0_tx_hex(V1.byteB);
	}
	uart0_tx_string("\r\n");
}
}

