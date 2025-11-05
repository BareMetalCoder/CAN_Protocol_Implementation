#include<lpc21xx.h>
#include"header.h"
#define led 0xff;
main()
{
//	u8 temp;
	int i;
	char t;
	uart0_init(9600);
	IODIR0=led;
	while(1)
	{
		uart0_tx_string("a) blink led\r\n");
		uart0_tx_string("b) 8 blink led");
		uart0_tx_string("enter the option\r\n");
		t=uart0_rx();
		uart0_tx(t);
		switch (t)
		{
			case 'a':IOSET0=led;
					break;
			case 'b':IOCLR0=led;
					for(i=0;i<8;i++)
					{
						IOSET0=1<<i;
						delay_ms(200);
						IOCLR0=1<<i;
					}
					break;
		}
	}
}
