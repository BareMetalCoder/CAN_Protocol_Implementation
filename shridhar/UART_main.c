#include<lpc21xx.h> 
#include"header.h"
#define BULB (1<<17)
#define sw ((IOPIN0>>14)&1)
main()
{	
	u8 temp,E,n;
	uart0_init(9600);
	while(1)
	{	
		uart0_tx_string("\r\nenter key");
		temp=uart0_rx();
		E=uart0_rx();

		if(E=='\r')
		{
			uart0_tx_string("\r\n ASCII\r\n");
			uart0_tx((temp/100)+48);
			uart0_tx(((temp/10)%10)+48);
			uart0_tx((temp%10)+48);

			uart0_tx_string(" ox");
			n=temp&0xf0;
			n=n>>4;
			if(n>9)
			uart0_tx('A'+n-10);
			else
			uart0_tx(48+temp/16);

			n=temp&0x0f;
			if(n>9)
			uart0_tx('A'+n-10);
			else
			uart0_tx(48+temp%16);
		}
	}
}


/*WAP EMB-c to recive a char serilly from the serial terminal 
& transmit its ascii to serial terminal in a 3 digits*/
//	u8 temp;
//	uart0_init(9600);
//	while(1)
//	{
//		uart0_tx_string("\r\nenter the kay:");
//		temp=uart0_rx();
//		uart0_tx_string("\r\nASCII\r\n");
//		uart0_tx((temp/100)+48);
//		uart0_tx(((temp/10)%10)+48);
//		uart0_tx((temp%10)+48);
//	}
//}
/*WAP ECP to recive a char from the serial terminal & send its opposite char
as loopback*/

//	char temp;
//	uart0_init(9600);
//	while(1)
//	{
//		temp=uart0_rx();
//		temp=temp^32;
//		uart0_tx(temp);
//	}
//}

/*WAP ECP to send A-Z character serially using uart0 (one at time)
for every switch press SW connection -> p0.14*/
//  	unsigned int c=0;
//	uart0_init(9600);
//	while(1)
//	{
//		if(c>25)
//		c=0;
//		if(sw==0)
//		{
//			while(sw==0);
//			uart0_tx('A'+c);
//			c++;
//		}
//	}
//}
/*--------pc based home automation------------*/
//	u8 cmd;
//
//	uart0_init(9600);
//	IODIR0|=BULB;
//	uart0_tx_string("\r\n pc based home automation");
//	while(1)
//	{
//		uart0_tx_string("\r\n menu");
//		uart0_tx_string("\r\n a BULB ON");
//		uart0_tx_string("\r\n b BULB OFF");
//		uart0_tx_string("\r\n c for switch");
//		uart0_tx_string("\r\n option...");
//	cmd=uart0_rx();
//	uart0_tx(cmd);//loopback
//	switch(cmd)
//	{	
////		case 'a':IOSET0=BULB;break;
////		case 'b':IOCLR0=BULB;break;
//		case 'a':IOCLR0=BULB;break;
//		case 'b':IOSET0=BULB;break;
//		case 'c':if(sw==0)
//				{	
//					while(sw==0);
//					IOCLR0=BULB;
//				}
//				else
//				IOSET0=BULB;
//				break;
//		
//		default:uart0_tx_string("\r\n wrong option");
//	}
//	}
//}


/************uart string function*****************/
//   u8 temp;
//   uart0_init(9600);
//   while(1)
//   {
//   uart0_tx_string("\r\n enter the char ");
//   temp=uart0_rx();
// 	uart0_tx(temp);	//loopback
//   uart0_tx_string("\r\n ASCII:");
//   uart0_tx((temp/100)+48);
//   uart0_tx(((temp/10)%10)+48);
//   uart0_tx((temp%10)+48);
//   }
//}
// 
////***********************************************
//
//
//
/**************uart string transmit in lcd************/
///	u8 temp ;
//	uart0_init(9600);
//	lcd_init();
//	while(1)
//	{
//	temp=uart0_rx();
//	lcd_data(temp);//loopback method 
//	}
//}
// */
////*****************************************
//
/*------------string-------------*/
//
//u8 i;
//uart0_init(9600);
//uart0_tx_string("vector BLR ");
//}
//
//////////////////////////////////
//
///*	unsigned char i;
//
//	uart0_init(9600);
////	uart0_init(115200);				h
//	while(1)
//	{
//		for(i=0;i<26;i++)
//		{
//			uart0_tx('A'+i); //send A to Z charcters
//			delay_ms(100);
//		}
//		//uart0_tx('0+48');
//	}
//}*/
//
///*
/*	//uart initilaization  */
//
//	PINSEL0|=5; //p0.0->TXD0, p0.1-> RXD0
//	U0LCR=0x83;
//	U0DLL=97; //for 9600bps
//	U0DLM=0; //for 9600bps
//	U0LCR^=(1<<7);  //DLAB=0;
//
////sending 1byte data using UART0;
//	while(1){
//	U0THR='B';
//	while(((U0LSR>>5)&1)==0);
//	}
//} */
//
