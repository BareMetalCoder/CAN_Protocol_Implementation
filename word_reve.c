#include<lpc21xx.h>
#include "h.h"
int main()	
{
	int i=0,j,l,t;
	char k[20];
	uart0_init(9600);
	while(1)
	{
		uart0_tx_string("\r\nenter the the string\r\n");
		uart0_rx_string(k,20);
		for(i=0;k[i];i++)
		uart0_tx(k[i]);
		//uart0_tx_string(k[i]);
		uart0_tx_string("\r\n");

		for(l=0;k[l];l++);
		for(i=0,j=l-1;i<j;i++,j--)
		{
			{
				t=k[i];
				k[i]=k[j];
				k[j]=t;
				}
			//	k=i+1;
		}
		uart0_tx_string("reverse \r\n");
		uart0_tx_string(k);
   }
 }
//	s8 s[10];
//	s32 i,j,l,k,t;
//	uart0_init(9600);
//	while(1)
//	{
//		uart0_tx_string("enter the the string\r\n");
//		uart0_rx_string(s,19);
//		uart0_tx_string(s);
//		uart0_tx_string("\r\n");
//
//		for(l=0;s[l];l++);
//		for(i=0,k=i;i<=l;i++)
//		{
//			if(s[i]==' '&& s[i]=='\0')
//			{
//				j=l-1;
//				for(k;k<j;k++,j--)
//				{
//					t=s[k];
//					s[k]=s[j];
//					s[j]=t;
//				}
//			//	k=i+1;
//		}
//		uart0_tx_string("reverse \r\n");
//		uart0_tx_string(s);
//   }
//}
//}
