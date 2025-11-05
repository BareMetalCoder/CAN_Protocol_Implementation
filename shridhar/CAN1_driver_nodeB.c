#include<lpc21xx.h>
#include"header.h"
void can1_init(void)
{
	PINSEL1|0x00040000;
	VPBDIV=1;                      //PCLK =60mhz
	C1MOD=1;                       //select reset mode
	C1BTR=0x001C001D;              //25kbps baudrate
	AFMR=2;               		   //accepatnce all combined data
	C1MOD=0;
}
#define TCS ((C1GSR>>3)&1)
void can1_tx(CAN1 V)
{
	C1TFI1=(V.dlc<<16);            //set dlc
	C1TID1=V.id;
	if(V.rtr==0)
	{
		C1TDA1=V.byteA;
		C1TDB1=V.byteB;
	}
	else                          //remote mode
		C1TFI1|=(1<<30);
	C1CMR=1|(1<<5);			  //start tx
	while(TCS==0);
}
#define RBS (C1GSR&1)
void can1_rx(CAN1 *ptr)
{
   	while(RBS==0);
	ptr->id=C1RID;
	ptr->dlc=(C1RFS>>16)&0x0f;
	ptr->rtr=(C1RFS>>30)&1;
	if(ptr->rtr==0)
	{
		ptr->byteA=C1RDA;
		ptr->byteB=C1RDB;
	}
	C1CMR=(1<<2);
}



