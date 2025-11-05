//WAP in EMC-c 
// if you press sw1 inc the counter form 0 to 59
//and sw2 press to dec the counter based on switch press
// and consider counter value and press sw3 for sudeden dec based on current counter value upto 0 and contiune.

#include<lpc21xx.h>
#define sw1 ((IOPIN0>>13)&1)
#define sw2 ((IOPIN0>>14)&1)
#define sw3 ((IOPIN0>>15)&1)
main()
{
	
	int count=0;
while(1)
{
		if(sw1==0)
		{
			while(sw1==0);
			count++;
			if(count>59)
			count=1;	
		}
		if(sw2==0)
		{
			while(sw2==0);	
				count--;
				if(count<0)
				count=59;	
		}	
		if(sw3==0)
		{
			while(sw3==0);			    
				 count=0;
	 	}
 	}
}
	


