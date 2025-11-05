#include<lpc21xx.h>
#include "lcd_header.h"
 main()
{
/////////scrolling function///////////////
	int i,l,t;
	char s[20]="VECTOR INDIA",*p,*q;
	lcd_init();
	for(l=0;s[l];l++);
	l--;																											
	for( ;l>=0;l--){
	lcd_string(&s[l]);
	delay_ms(200);
	lcd_cmd(0x01);
	}
		while(1)
		{
			for(t=0;s[t];t++);
			t--;
			p=s;
			q=p+t;
			lcd_cmd(0x80);
			for(i=0;i<16;i++)
			{
				lcd_cmd(0x80+i);
				lcd_string(p);
				delay_ms(200);
				lcd_cmd(0x01);
				if(i>=15-t)
				{
					lcd_cmd(0x80);
					lcd_string(q);
					q--;
				}
			}
		}
	}

////////atof function//////////////////
/*
	lcd_init();
	lcd_atof(12.33);
	while(1);
} */
///////atoi function////////////////////
/*	lcd_init();
	lcd_atoi(-1234);
	while(1);
}*/
																											
//	CGRAM function//////////////////
/*lcd_init();
		lcd_cgram();
		lcd_cmd(0x80);
		lcd_data(0);//page 0
		while(1);
}*/


//////scrolling//////////////
/*int i;
	lcd_init()
	for(l=0;i<16;i++)
	{
		lcd_cmd(0x80+i);
		lcd_string("VECTOR");
		delay_ms(100);
		lcd_cmd(0x01);
		
	}*/
/////5 time print vector after india ////////////////////
		/*lcd_init();
		//while(1)
		//{
		for(i=0;i<5;i++)
		{
				lcd_cmd(0x80);
				lcd_string("vector");
				delay_ms(100);
				lcd_cmd(0x01);
				delay_ms(100);
			}
			lcd_cmd(0xc0);
			lcd_string("india");
			while(1);	
}*/
