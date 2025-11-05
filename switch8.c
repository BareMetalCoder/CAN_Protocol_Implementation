//write a pgrm in emb-c implement toggle using push to on switch
// hint step1: wait for switch press
// 		step2: if switch pressed, wait for switch release
//      step3: if switch is released, toggle the led


#include<lpc21xx.h>
#define led 1<<17
#define sw ((IOPIN0>>14)&1)
main()
{
	IODIR0=led;
	IOSET0=led;
	while(1)
	{
		if(sw==0)
		{
			while(sw==0);
			IOCLR0=led;
		}
	}
}