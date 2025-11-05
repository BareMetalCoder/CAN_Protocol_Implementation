//WAP in emb-c 
//if you press sw1 turn on the led 
//if you press sw2 turn off the led
//if you press sw2 turn on the led 
//and again if you press the sw1 turn off the led and continue 


#include<lpc21xx.h>
#define led 7<<17
#define sw1 ((IOPIN0>>14)&1)
#define sw2 ((IOPIN0>>15)&1)
main()
{
	int flag=0;
	IODIR0=led;				   
	IOSET0=led; 
	while(1)
	{
		if(sw1==0)
		{
 			while(sw1==0);
			if(flag)
			{
				IOSET0=led;
			}
			else
			IOCLR0=led;
			flag=!flag;
		  }
			if(sw2==0)
			{
				while(sw2==0);
				if(flag)
				{
					IOSET0=led;
				}
				else
				IOCLR0=led;
				flag=!flag;
			}
		}
		
	}
	 