#include<lpc21xx.h>
#include"can_header.h"
#define rs (1<<17)
#define rw (1<<18)
#define en (1<<19)

void lcd_data(unsigned char data)
{
	unsigned int temp;
	IOCLR1=0x00fe0000;
	temp=(data&0xf0)<<16;
	IOSET1=temp;
	IOSET1=rs;
	IOCLR1=rw;
	IOSET1=en;
	delay_ms(2);
	IOCLR1=en;

		IOCLR1=0x00fe0000;
	temp=(data&0x0f)<<20;
	IOSET1=temp;
	IOSET1=rs;
	IOCLR1=rw;
	IOSET1=en;
	delay_ms(2);
	IOCLR1=en;
}

void lcd_cmd(unsigned char cmd)
{
	unsigned int temp;
	IOCLR1=0x00fe0000;
	temp=(cmd&0xf0)<<16;
	IOSET1=temp;							    
	IOCLR1=rs;
	IOCLR1=rw;
	IOSET1=en;
	delay_ms(2);
	IOCLR1=en;

	IOCLR1=0x00fe0000;
	temp=(cmd&0x0f)<<20;
	IOSET1=temp;
	IOCLR1=rs;
	IOCLR1=rw;
	IOSET1=en;
	delay_ms(2);
	IOCLR1=en;
}
void lcd_init()
{
	IODIR1=0x00fe<<16;
	PINSEL2=0x0;
	lcd_cmd(0X03);
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x0e);
	lcd_cmd(0x01);
	//IOCLR1=en;
}

// string functions////////////////////
void lcd_string(signed char *ptr)
{
	while(*ptr!=0)
	{
		lcd_data(*ptr);
		ptr++;
	}
}
/////atoi function////////////////
void lcd_atoi(int num)
{
	char a[10];
	int i=0;
	if(num==0)
	{
		lcd_data('0');
		return;
	}
		if(num<0)
		{
			lcd_data('-');
			num=-num;
		}
	while(num>0)
	{
		a[i]=(num%10)+48;
		num=num/10;
		i++;
	}
		i--;
		for(  ;i>=0;i--)
		{
			lcd_data(a[i]);
		}
	}
//////////atof finction//////////////// 
void lcd_atof(double f)		 
{
	int i=f;
	lcd_atoi(i);
	lcd_data('.');
	i=(f-i)*10000;
	if(i<0)
	i=-i;
	lcd_atoi(i);
}


//CGRAM function

//unsigned char a[10]={0x0,0xA,0XA,0x0,0x0,0x11,0xE,0x0};
unsigned char a[10]={0x0,0x4,0x4,0x4,0xf,0x0f};
void lcd_cgram(void)
{
	int i;
	lcd_cmd(0x40);
	for(i=0;i<=7;i++)
	{
		lcd_data(a[i]);
	}
}

