#include<lpc21xx.h>
#include"header.h"
#define THRE1 ((U1LSR>>5)&1)
#define RDR1 (U1LSR&1)

void uart1_init(unsigned int baud)
{
	unsigned int result=0;
	int a[]={15,60,30,0,15};
	unsigned int pclk=0;

	pclk=a[VPBDIV]*1000000;
	result=pclk/(16*baud);

	PINSEL0|=0x50000; //p0.0->TXD0, p0.1-> RXD0
	U1LCR=0x83;
	U1DLL=result&0xff;
	U1DLM=(result>>8)&0xff; //for 9600bps
	U1LCR^=(1<<7);  //DLAB=0;
}

void uart1_tx(unsigned char data)
{
	U1THR=data;
	while(THRE1==0);
}
//*********uart reciving function***************
u8 uart1_rx(void)
{
	while(RDR1==0);
	return U1RBR;
}
//*************************************************

//**********uart string function***************
void uart1_tx_string(s8 *ptr)
{
	while(*ptr)
	{
		U1THR=*ptr;
		while(THRE1==0);
		ptr++;
	}
}
//**************uart string reciving function
void uart1_rx_string(s8 *ptr , u8 len)
{
	u8 i;
	for(i=0;i<len;i++)
	{	
		while(RDR1==0);
		ptr[i]=U1RBR;
		if(ptr[i]=='\r')//if enter key
		break;
	}
	ptr[i]='\0';//null
}
