#include<lpc21xx.h>
#include"can_header.h"
//#include"TIMER.H"
//#include"ULTRASONIC.H"
//#include"LCD.H"



unsigned int range=0,i;

int main()
{
	uart0_init(9600);
	ultrasonic_init();
	uart0_tx_string("Distance : ");
	while(1) 
	{
		range=get_range();
		uart0_tx((range/100)+48);
		uart0_tx(((range/10)%10)+48);
		uart0_tx((range%10)+48);
  		uart0_tx_string("cm\r\n");
	}
}
