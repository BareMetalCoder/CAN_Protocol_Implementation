/*node B_can1_rx_main.c*/
#include"header.h"
CAN1 v,v1;
s32 flag=0;

int main()
{
char c[10],t;
u32 r=0;

CAN1_init();
 can2_intr();
 lcd_init();
while(1)
{		 	
if(flag==1)
	{
			if(v.rtr==1)
				{

				 if(v.id==0x2)
				 {
					r=ultrasonic();		 
					v1.id=0x4;                                                                            
					v1.dlc=4;
					v1.rtr=0;
					v1.byteA=r/59;
					v1.byteB=0;
					CAN1_tx(v1);
					delay_ms(500);
				
			 	}
			
					if(v.id==0x3)
					 {
						v1.id=0x5;                                                                            
						v1.dlc=4;
						v1.rtr=0;
						v1.byteA='A';
						v1.byteB=0;
						CAN1_tx(v1);
						delay_ms(20);
						flag^=1;
					}
			}
		} 
	}
}
