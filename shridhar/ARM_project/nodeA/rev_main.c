#include<lpc21xx.h>
#include"header.h"
#define sw ((IOPIN>>14)&1)
#define led (1<<17)
#define BUZ	(1<<24)
main()
{
	if(sw==0)
	{
		while(sw==0);
		IOCLR0=led;
		IOCLR0=BUZ;
	}
}

