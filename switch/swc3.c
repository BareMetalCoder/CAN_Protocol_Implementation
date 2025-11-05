#include<lpc21xx.h>
//#include"header.h
#define led (7<<17)
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
				while(T0TC<8)
				{
					if(sw==0)
					{
						while(sw==0);
						c++;
					}
				
				if(T0TC<5);
				{
					if(sw==0)
						{
							while(sw==0);
							c++;
						}
				}
				if(T0TC<1)
				{
					if(sw==0)
					{
						while(sw==0);
						c++;
					}
				}
			}
			T0TCR=0;
			if(c==4)
			{
				c=0;
			}
			if(c==3)
			{
				IOSET0=led;
			}
			if(c==2)
			{
				IOCLR0=led;
			}
		}
	}

}

