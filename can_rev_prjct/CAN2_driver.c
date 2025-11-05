/*driver_node_CONTROL_UNIT*/
#include"header.h"
void CAN1_init(void)
{
	PINSEL1 |=0X00014000;
	VPBDIV =1;
	C2MOD =1;
	AFMR=0X02;
	C2BTR =0X001C001D;
	C2MOD=0;
}
						//trtansmitter
#define TCS ((C2GSR>>3)&1)
void CAN1_tx(CAN1 v)
{
	C2TID1 =v.id;
	C2TFI1 =(v.dlc)<<16;
	if(v.rtr==0)
		{
		C2TDA1=v.byteA;
		C2TDB1=v.byteB;
		}
	else
		C2TFI1 |=(1<<30);	//RTR BIT ==1
C2CMR=0X21;	 //to set STB & TR
while(TCS==0);
}
				//receiver 
/*#define RBS (C2GSR&1)
void CAN1_rx(CAN1 *p)
{
	while(RBS==0);
	p->id=C2RID;
	p->dlc=(C2RFS>>16)&0XF;		   
	p->rtr=(C2RFS>>30)&1;
	if(p->rtr==0)
		{
		p->byteA=C2RDA;
		p->byteB=C2RDB;
		}
C2CMR=(1<<2); //RRB RCVR BUFFER RELEASE	

} */



