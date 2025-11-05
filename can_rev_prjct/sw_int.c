#include"header.h" 
  extern int f1;
 
 void sw_handler(void)__irq
{
CAN1 v1;
	f1^=1;
if(f1)
 {
	v1.id=0x2;                                                                            
	v1.dlc=4;
	v1.rtr=1;
	CAN1_tx(v1);

	}
	if(f1==0)
	{
	v1.id=0x3;                                                                            
	v1.dlc=4;
	v1.rtr=1;
	CAN1_tx(v1);
	}
	EXTINT=1;
	VICVectAddr=0;
}



//switch int_enable
   void en_sw_intr(void)
   {
    PINSEL1 |=0X00000001;
    
   	EXTMODE=1 ;
	EXTPOLAR=0;
	VICIntSelect=0;
VICVectAddr1=(u32)sw_handler;
VICVectCntl1= 14|(1<<5);
VICIntEnable |=(1<<14);
}
