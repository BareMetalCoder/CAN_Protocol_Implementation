	unsigned int i;
	uart0_init(9600);
	uart0_tx_string("vector BLR\r\n");
}




 #include"HEADER.H"
#define BULB (1<<17)
#define FAN (1<<18)
#define TV (1<<19)
main()
{

  while(1)
	 {



 switch(OP)
 	{
 	 case '1':IOSET0=BULB;
			 		break:
 	 case '2':IOSET0=FAN;
				 	break:	   
	 case '3':IOSET0=TV;
	 				break:
	 case '4':IOCLR0=BULB;
			 		break:
 	 case '5':IOLCR0=FAN;
				 	break:	   
	 case '6':IOCLR0=TV;
	 				break:
	 case '7': IOSET0=BULB;  IOSET0=FAN; IOSET0=TV; 
			 		break:
 	 case '8': IOCLR0=BULB;  IOCLR0=FAN; IOCLR0=TV; 
				 	break:	   
	 default:UART0_STRING("NOT VALID OPTION\r\n");
	 				break:

		}


	  }
}

   //*****************************CHAR CONVERT INTO ASCII****************************************************************************

 /*
 #include"HEADER.H"
 main()
 {
 unsigned char TEMP;

 UART0_INIT(9600);
 while(1)
 {
 UART0_STRING("\r\nENTER CHAR:");
 TEMP=UART0_RX();
 UART0_TX(TEMP);     //LOOPBACK

 UART0_STRING("\r\nASCII:");

 //PRINT CHAR IN 3 DIGIT ASCII

 UART0_TX(((TEMP/100)+48));
 UART0_TX((((TEMP/10)%10)+48));
 UART0_TX(((TEMP%10)+48));
 
 	 UART0_STRING("\r\n");
 
  }
 
 }
*/

  //*****************************STRING PRINT****************************************************************************
/*
#include"header.h"
main()
{
unsigned int I;
UART0_INIT(9600);

while(1)
{
for(I=0;I<26;I++)
UART0_TX('A'+I);

UART0_STRING("HI SUMIT MORI\r\n");
DELAY_MS(10);

 }

}
*/
