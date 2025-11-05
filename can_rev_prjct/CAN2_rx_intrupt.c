	#include"header.h"

extern CAN1 v;
extern s32 flag;
void can2_rx_handler(void)__irq
{
flag=1;
v.id=C2RID;
v.dlc=(C2RFS>>16)&0XF;
v.rtr=(C2RFS>>30)&1;
if(v.rtr==0)
{
v.byteA=C2RDA;
v.byteB=C2RDB;
}

 C2CMR=(1<<2);
 VICVectAddr=0;
 }
 void can2_intr(void)
{
VICIntSelect=0;
VICVectAddr0=(u32)can2_rx_handler;
VICVectCntl0= 27|(1<<5);
VICIntEnable |=(1<<27);
C2IER=1;

}
