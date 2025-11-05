//Q1

#include<lpc21xx.h>
#define led 7<<17
#define sw ((IOPIN0>>14)&1)
main()
{
	int c=0;
	IODIR0=led;
	IOSET0=led;
		while(1)
		{
			if(sw==0)
			{
				while(sw==0);
				T0PC=0;
				T0PR=15000000-1;
				T0TC=0;
				T0TCR=1;
				c++;
				while(T0TC<1)
				{
					if(sw==0)
					{
						while(sw==0);
						c++;
					}
				}
				T0TCR=0;
			}
			if(c==1)
			{
				IOSET0=led;
				c=0;
			}
			else if(c==2)
			{
				IOCLR0=led;
				c=0;
			}
			else
			c=0;
		}
	}
