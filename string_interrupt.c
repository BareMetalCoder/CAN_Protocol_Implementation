#include<lpc21xx.h>
#include"header.h"
extern u8 temp,flag,arr[13];
u32 tx_cnt,rx_cnt;
//extern u32 ;

void uart0_handle(void) __irq
{
	int r=U0IIR;
	static int i;
	if(((r>>1)&7)==2)
	{
		arr[i]=U0RBR;
		i++;
		if((arr[i-1]=='\r')||(i==12))
		{
			if(arr[i-1]=='\r')
			arr[i-1]='\0';
			else
			arr[i]='\0';
			flag=1;
			i=0;
		}
	}
	VICVectAddr=0;
}
void config_VIC_for_uart0(void)
{
	VICIntSelect=0;
	VICVectCntl0=6|(1<<5);
	VICVectAddr0=(u32) uart0_handle;
	VICIntEnable|=(1<<6);
}
void en_uart0_interrupt(void)
{
	U0IER=3;
} 



 