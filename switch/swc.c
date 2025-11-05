#include<lpc21xx.h>
//#include"header.h"
#define led 1<<17
#define sw ((IOPIN0>>14)&1)
main()
{
	/*IODIR0=led;
	while(1)
	{
		if(sw==0)
		IOCLR0=led;
		else
		IOSET0=led;
	}*/

///////////////led on off with switch//////////////////
	/*IODIR0=led;
	while(1)
	{
 		while(sw==0);
		IOCLR0=led;
		while(sw==1);
		IOSET0=led;
	 }*/

/*int c=0;
IODIR0=led;

while(1)
{
	for(c=0;c<=5;  )
	{
		if(sw==0)
		{
			while(sw==0);
			{
			c++;
			}
			if(c==5){

			IOSET0=1<<17;
			IOSET0=1<<21;		
			 }
			
		}
		//	IOSET0=1<<21;
	
}
} */
























}

