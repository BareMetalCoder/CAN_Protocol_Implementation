
//****************** assignements************************************
 #include"header.h"
int main()
{
////WAP to rx a char serially from the serial terminal & send its opposite char as a loopback
//
//	u8 temp;
//	uart0_init(9600);
//	while(1)
//	{
//		temp=uart0_rx();
//		temp^=32;
//		uart0_tx(temp);
//	}
//}
 //*******************************************************************

 //WAP to scan a char serially from serial terminal & loopback its aschii in decimal format 
 //NOTE: send ascii value upon pressing anter key serial terminal
 //eg:A[enster key]
 //    ASCII: 65 0x41
		
	u8 temp,enterkey;
	uart0_init(9600);
	while(1)
	{
		uart0_tx_string("\r\n enter char");
		temp=uart0_rx();
		enterkey=uart0_rx();

		if(enterkey=='\r')
		{
			uart0_tx_string("\r\n ASCII ");
			uart0_tx((temp/100)+48);
			uart0_tx(((temp/10)%10)+48);
			uart0_tx((temp%10)+48);
		
			uart0_tx_string("hex");
			uart0_tx(48+temp/16);
			uart0_tx(48+temp%16);
		}
	}
}
