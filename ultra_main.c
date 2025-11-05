#include<LPC21xx.h>
#include"header.h"
#define	sw ((IOPIN0>>16)&1)
#define trigger (1<<5)
#define echo ((IOPIN0>>6)&1)
main()
{
		int r;
	void ultrasonic_init();


	while(1)
	{
		if(sw==0)
		{
			while(sw==0);
	r=ultrasonic_sensor();
	uart0_tx_integer(r);
	}
	}
}