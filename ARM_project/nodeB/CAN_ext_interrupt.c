#include<lpc21xx.h>
#include"can_header.h"
extern u32 flag;
extern CAN2 V1;
void CAN2_rx_handler(void) __irq
{
	V1.id=C2RID;
	V1.dlc=(C2RFS>>16)&0x0f;
	V1.rtr=(C2RFS>>30)&1;
	if(V1.rtr==0)
	{
		V1.byteA=C2RDA;
		V1.byteB=C2RDB;
	}
	C2CMR=(1<<2);	   //release rx buf(vimp)
	flag=1;
	VICVectAddr=0;	   //to finish the isr
}
void config_vic_for_can2(void)
{
	VICIntSelect=0;
	VICVectCntl12=27|(1<<5);
	VICVectAddr12=(u32)CAN2_rx_handler;
	VICIntEnable|=(1<<27);
}
void en_can2_interrupt(void)
{
	C2IER=1;
}                     //EN CAN1 rx integer
