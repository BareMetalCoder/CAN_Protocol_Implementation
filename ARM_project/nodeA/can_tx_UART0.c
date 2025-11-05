#include<lpc21xx.h>
#include"can_header.h"
#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR&1)
void uart0_init(u32 baud)
{
		u32 result;
		int a[]={15,60,30,15,15};
		u32 pclk=0;
		pclk=a[VPBDIV]*1000000;
		result=pclk/(16*baud);
		
		PINSEL0|=0x05;           //p0.0->TXD0, p0.1-> RXD0
		U0LCR=0x83;
		U0DLL=result&0xff;
		U0DLM=(result>>8)&0xff;     //for 9600
		U0LCR^=(1<<7);
	}
void uart0_tx(u8 data)
{
		U0THR=data;
		while(THRE==0);
}
u8 uart0_rx(void)
{
		while(RDR==0);
		return U0RBR;
}
void uart0_tx_string(s8 *ptr)
{
		while(*ptr!=0)
		{
				U0THR=*ptr;
				while(THRE==0);
				ptr++;
		}
	}
void uart0_rx_string(s8 *ptr,u8 len)
{	
		int i;
		for(i=0;i<len;i++)
		{
			while(RDR==0);
			ptr[i]=U0RBR;
			if(ptr[i]=='\r')
				break;
		}
		ptr[i]='\0';
	}
void uart0_tx_integer(s32 num)
{
	char a[10];
	int i=0;
	if(num==0)
	{
		uart0_tx('0');
		return;
	}
		if(num<0)
		{
			num=-num;
			uart0_tx('-');
		
		}
	while(num>0)
	{
		a[i]=(num%10)+48;
		num=num/10;
		i++;
	}
	
		for(i--;i>=0;i--)
		{
			uart0_tx(a[i]);
		}
	}

//-------------uarat float-----------------------

void uart0_tx_float(float f)
{
	int i=f;
	uart0_tx_integer(i);
	uart0_tx('.');
	i=(f-i)*100;
	uart0_tx_integer(i);
}
//void uart0_tx_float(float f)		 
//{
//	int i=0,num;
//	char a[10];
//	
//	if(f==0)
//	{
//		uart0_tx_string("0.00000'");
//		return;
//	}
//		if(f<0)
//		{
//			uart0_tx('-');
//			f=-f;
//		}
//		num=f;
//		if(num==0)
//		{
//			uart0_tx('0');
//		}
//		else
//		{
//			while(num>0)
//			{
//				a[i]=(num%10)+48;
//				i++;
//				num=num/10;
//			}
//			for(--i;i>=0;i--)
//			uart0_tx(a[i]);
//		}
//	uart0_tx('.');
//	i=0;
//	num=(f-num)*1000000;
//	if(num==0)
//	{
//		uart0_tx_string("000000");
//	}
//	else
//	{
//		while(i<2)
//		{
//			a[i]=(num%10)+48;
//			i++;
//			num/=10;
//		}
//		for(--i;i>=0;i--)
//		uart0_tx(a[i]);
//	}
//}
//
void uart0_hex(u8 data)
{
	u8 temp;
	uart0_tx_string("0x0");
	temp=(data&0xf0)>>4;
	uart0_tx(temp+48);

	temp=data&0x0f;
	if(temp>9)
	uart0_tx('A'+(temp-10));
	else
	uart0_tx('0'+temp);
}

void uart0_tx_hex(u32 n)
{
	int i,f=1,l;
	u8 t;
	for(i=0;i<8;i++)
	{
		l=4*(7-i);
		t=(n>>l)&0x0f;
		if(f)
			if(t)
				f=0;
		if(f==0)
		{
			if(t>9)
				uart0_tx('A'+(t-10));
			else
				uart0_tx(t+48);
		}
	}
}
