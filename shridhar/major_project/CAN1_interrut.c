#include<lpc21xx.h>
#include"header.h"
extern u32 flag;
extern CAN1 V1;
void CAN1_rx_handler(void) __irq
{
	V1.id=C1RID;
	V1.dlc=(C1RFS>>16)&0x0f;
	V1.rtr=(C1RFS>>30)&1;
	if(V1.rtr==0)
	{
		V1.byteA=C1RDA;
		V1.byteB=C1RDB;
	}
	C1CMR=(1<<2);	   //release rx buf(vimp)
	flag=1;
	VICVectAddr=0;	   //to finish the isr
}
void config_vic_for_can1(void)
{
	VICIntSelect=0;
	VICVectCntl12=26|(1<<5);
	VICVectAddr12=(u32)CAN1_rx_handler;
	VICIntEnable|=(1<<26);
}
void en_can1_interrupt(void)
{
	C1IER=1;
}                     //EN CAN1 rx integer
