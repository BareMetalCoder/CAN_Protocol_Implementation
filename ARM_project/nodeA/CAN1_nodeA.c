#include<lpc21xx.h>
#include"can_header.h"
extern CAN2 V1;
void can2_init(void)
{
	PINSEL1|=0x00014000;
	VPBDIV=1;                      //PCLK =60mhz
	C2MOD=1;                       //select reset mode
	C2BTR=0x001C001D;               //25kbps baudrate
	AFMR=2;               		   //accepatnce all combined data
	C2MOD=0;
}
#define TCS ((C2GSR>>3)&1)
void can2_tx(void)
{
	C2TFI1=(V1.dlc<<16);            //set dlc
	C2TID1=V1.id;
	if(V1.rtr==0)
	{
		C2TDA1=V1.byteA;
		C2TDB1=V1.byteB;
	}
	else                          //remote mode
		C2TFI1|=(1<<30);
		C2CMR=1|(1<<5);			  //start tx
		while(TCS==0);
}
/*#define RBS (C2GSR&1)
void can2_rx(CAN2 *ptr)
{
	while(RBS==0);
	ptr->id=C2RID;
	ptr->dlc=(C2RFS>>16)&0x0f;
	ptr->rtr=(C2RFS>>30)&1;
	if(ptr->rtr==0)
	{
		ptr->byteA=C2RDA;
		ptr->byteB=C2RDB;
	}
	C2CMR=(1<<2);
}  */



