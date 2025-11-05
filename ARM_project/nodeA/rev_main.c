#include"can_header.h"
u32 gear,flag;
CAN2 V2;
main()
 {
 	  int dis;
	  IODIR0=1<<21;
	  IOCLR0=1<<21;

	  can2_init();
	  en_can2_interrupt();
	  en_extern_interrupt();

		config_vic_for_can2();
	  	config_VIC_for_extern();
		 uart0_init(9600);
		//lcd_init();
	  	while(1)
		{
			if(flag)
			{
				flag^=1;
				if(V2.id==0x13)
				uart0_tx_string("revrse parking mode\r\n");
				dis=(V2.byteA);
				uart0_tx_integer(dis);
				if(dis>=301 && dis<=428)
				{
					IOCLR0=1<<21;
//					delay_ms(1000);
//					IOSET0=1<<21;
//					delay_ms(1000);
//					IOCLR0=1<<21;
				}
				else if(dis>=51 && dis<=100)
				{
					delay_ms(500);
					IOSET0=1<<21;
					delay_ms(500);
					IOCLR0=1<<21;
				}
				else if(dis>=0 && dis<=50)
				{
					delay_ms(100);
					IOSET0=1<<21;
					delay_ms(100);
					IOCLR0=1<<21;
				}
				uart0_tx_string("\r\n");
				IOCLR0=1<<21;
				if(V2.id==0x14)
				{
					uart0_tx_integer(V2.byteA);
					uart0_tx_string("reverse parking stopped\r\n");
				}
			}
		}
	}						 
				
