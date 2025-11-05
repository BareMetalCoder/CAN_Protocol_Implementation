#include<lpc21xx.h>
#include"can_header.h"
extern u32 flag;
extern CAN2 V2;
void CAN2_rx_handler(void) __irq
{
	flag=1;
	V2.id=C2RID;
	V2.dlc=(C2RFS>>16)&0x0f;
	V2.rtr=(C2RFS>>30)&1;
	if(V2.rtr==0)
	{
		V2.byteA=C2RDA;
		V2.byteB=C2RDB;
	}
	C2CMR=(1<<2);	   //release rx buf(vimp)
	
	VICVectAddr=0;	   //to finish the isr
}

void config_vic_for_can2(void)
{
	VICIntSelect=0;
	VICIntEnable|=(1<<27);
	VICVectCntl12=27|(1<<5);
	VICVectAddr12=(u32)CAN2_rx_handler;

}
void en_can2_interrupt(void)
{
	C2IER=1;
}                     //EN CAN1 rx integer
