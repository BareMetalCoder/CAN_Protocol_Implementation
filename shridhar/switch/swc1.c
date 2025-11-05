//IF the switch is pressed twice in 1sec then turn on the led 
//if switch pressed one time in 1sec then turn off the led
#include<lpc21xx.h>
#include"heder.h"
#define led 1<<17
#define sw ((IOPIN0>>14)&1)
main()
{
int c;
unsigned int pclk;
IODIR0=led;
IOSET0=led;
	while(1)
	{
	c=0;
		if(sw==0)
		{
			c++	;
			pclk=15*1000000-1;
			T0PC=0;
			T0PR=pclk;
			T0TC=0;
			T0TCR=1;
			while(sw==0);
		while(T0TC<1)
		{
		  	if(sw==0)
			{
			while(sw==0);
			c++;
			}
		}
		T0TCR=0;
         if(c==2)
		 IOCLR0=led;
		 if(c==1)
		 IOSET0=led; 
	}
    }
	}

 /* while(1)
	{
	i=0;
		if(sw==0)
		{
			pclk=15*1000000-1;
			T0PC=0;
			T0PR=pclk;
			T0TC=0;
			T0TCR=1;
			c++	;
				
		while(T0TC<1)
		{
		  	if(sw==0)
			{
			while(sw==0);
			i++;
			}
	
		}
		T0TCR=0;

		 if(i==1)
		 IOCLR0=1<<2;
		 else
		 IOSET0=1<<2;
	
		
	}
  }
}*/
	