#include<lpc21xx.h>
#include"header.h"
#define LED (3<<17)
#define LED1 (1<<17)
u8 temp,flag;
main()
{
	IODIR0=LED;
	//IOSET0=LED;  

		config_VIC_for_extern();
		en_extern_interrupt();
		while(1)
		{
			IOSET0=LED1;
			delay_ms(100);
			IOCLR0=LED1;
			delay_ms(100);
		}
}

			