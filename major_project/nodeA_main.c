#include<lpc21xx.h>
#include"header.h"
CAN1 V1;
u32 flag;
main()
{
	can1_init();
	uart0_init(9600);
	config_vic_for_can1();
	en_can1_interrupt();
//	ultrasonic_init();
//	send_pulse();
//	get_range();
	uart0_tx_string("nodeB\r\n");
	while(1)
	{
		//can1 rx(&v1)
		if(flag==1)
		flag=0;
		uart0_tx_hex(V1.id);
		uart0_tx(' ');
		uart0_tx_hex(V1.rtr);
		uart0_tx_string("\r\n");
	}
}

