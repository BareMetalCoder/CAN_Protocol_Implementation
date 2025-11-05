 #include"header.h"
 CAN1 V1;
 main()
 {
 	can1_init();
	uart0_init(9600);
	uart0_tx_string("nodeB\r\n");
	while(1)
	{								   
		can1_rx(&V1);
		if(V1.rtr==0)
		uart0_tx_string("data_frame\r\n");
		else
		uart0_tx_string("remote frame\r\n");
	}
}
