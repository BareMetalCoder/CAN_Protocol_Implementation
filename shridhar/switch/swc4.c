//If the pressed switch twice 8sec, then turn on the led 
//if the switch is pressed one time in 5sec,then turn off led 
// if the switch pressed more than 2 times in 1 sec then no changes on last state

#include<lpc21xx.h>
//#include"header.h
#define led 7<<17
#define sw ((IOPIN0>>14)&1)
main()
{
	int c;
	IODIR0=led;
	IOSET0=led;
		while(1)
		{
 			if(sw==0)
			{
				while(sw==0);
				c=1;
				T0PC=0;
				T0PR=15000000-1;
				T0TC=0;
				T0TCR=1;
				while(T0TC<8)
				{
					if(sw==0)
					{
						while(sw==0);
						c++;
					}
					 if(c>2 && T0TC<=1)
					 break;
					 else if(c==1 && T0TC==5)
					 break;
				}
				T0TCR=0;
				if(c==2)
				IOCLR0=led;
				else if(c==1)
				IOSET0=led;
			}
		}
	}
