//write ECP, press sw1 5times,to set 5min time,
// press sw2 to change the option 
// press sw1 10times to set 10sec 
// after that clear the screen and print minutes and sec on the lcd loke(05:10)



#include<lpc21xx.h>
#include "lcd_header.h"
#define sw1 ((IOPIN0>>14)&1)
#define sw2 ((IOPIN0>>15)&1)
 main()
{
	int m,s,c;
	while(1)
	{
	if(sw1==0)
	{
		while(sw1==0);
		m=1;
		s=0;
		while(1)
		{
			if(sw1==0)
			{
				while(sw1==0);
				m++;
		    }
			if(sw2==0)
			{
				while(sw2==0);
				c++;
				break;
			}	
	    }
			
	
	while(1)
	{
	if(sw1==0)
	{
		while(sw1==0);
		s++;
	}
		if(sw2==0)
		{
			while(sw2==0);
		    c++;
			break;
		}
	}
}
if(c==2)
{
lcd_init();
lcd_data(m/10+48);
lcd_data(m%10+48);
lcd_data(':');
lcd_data(m/10+48);
lcd_data(m%10+48);
c=0;
}
}
}