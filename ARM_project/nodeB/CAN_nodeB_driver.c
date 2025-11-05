#include<lpc21xx.h>
#include"can_header.h"
extern CAN2 V2;
void can2_init(void)
{
	//PINSEL1|=0x00040000;
	PINSEL1|=0x00014000;
	VPBDIV=1;                      //PCLK =60mhz
	C2MOD=1;                       //select reset mode
	C2BTR=0x001C001D;              //25kbps baudrate
	AFMR=2;               		   //accepatnce all combined data
	C2MOD=0;
}
#define TCS ((C2GSR>>3)&1)
void can2_tx(void)
{
	C2TFI1=(V2.dlc<<16);            //set dlc
	C2TID1=V2.id;
	if(V2.rtr==0)
	{
		C2TDA1=V2.byteA;
		C2TDB1=V2.byteB;
	}
	else                          //remote mode
		C2TFI1|=(1<<30);
	C2CMR=1|(1<<5);			  //start tx
	while(TCS==0);
}  
//#define RBS (C2GSR&1)
////void can1_rx(CAN1 *ptr)
//void can2_rx(void)
//{
//	while(RBS==0);
//	V1.id=C2RID;
//	V1.dlc=(C2RFS>>16)&0x0f;
//	V1.rtr=(C2RFS>>30)&1;
//	if(V1.rtr==0)
//	{
//		V1.byteA=C2RDA;
//		V1.byteB=C2RDB;
//	}
//	C2CMR=(1<<2);
//}
//
//
//
