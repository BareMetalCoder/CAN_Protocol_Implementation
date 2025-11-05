#include"can_header.h"
CAN2 V1,V2;
u32 flag;
main()
{
	IODIR0=3<<17;
	IOSET0=3<<17;
		 
	can2_init();
	ultrasonic_init();
	en_can2_interrupt();
	config_vic_for_can2();

 	while(1)
	{
		if(flag)
		{

		IOCLR0=1<<17;	
			if(V1.rtr==1)
			{
				if(V1.id==0x11)
				{
					V2.id=0x13;
					V2.dlc=4;
					V2.rtr=0;
					V2.byteA=ultrasonic_sensor();
					V2.byteB=0;
					can2_tx();	
					delay_ms(100);
					IOCLR0=2<<17;
				}
				if(V1.id==0x12)
				{
					flag^=1;
				
					V2.id=0x14;
					V2.dlc=4;
					V2.rtr=0;
					V2.byteA=100;
					V2.byteB=0;
					can2_tx();
					delay_ms(100);
					IOSET0=2<<17;
				
				}
			}
		}
	}
}
