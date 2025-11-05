/*node_A_main.c*/
#include"header.h"
CAN1 v;
 s32 f1=0,flag=0;			
int main()
{	
u32 i,j,num;
char c[10],t;
PINSEL1 |=0X00000001;
IODIR0=1<<21;
IOSET0=1<<17;			
CAN1_init();
en_sw_intr();
can2_intr();  
lcd_init();

/*data_frame*/
while(1)
{
if(flag==1)	{
flag^=1;
if(v.rtr==0)
{
if(v.id==0x4)
{
num=(v.byteA);
if(num<400&&num>=300)
{
	IOSET0=1<<21;
	delay_ms(250);
	IOCLR0=1<<21;
	delay_sec(1);
}
   if(num<300&&num>=200)
	{
	IOSET0=1<<21;
	delay_ms(350);
	IOCLR0=1<<21;
	delay_ms(500);
	}

if(num<200&&num>=100)
{
IOSET0=1<<21;
delay_ms(500);
IOCLR0=1<<21;
delay_ms(300);
}

if(num<100&&num>=50)
{
IOSET0=1<<21;
delay_ms(700);
IOCLR0=1<<21;
delay_ms(200);
}

if(num<50&&num>0)
IOSET0=1<<21;
if(num>50)
{
IOSET0=1<<17;
IOCLR0=1<<21;
}
if(num<30&&num>0)
IOCLR0=1<<17;


for(i=0;num;num=num/10,i++)
		 c[i]=(num%10)+48;
		 c[i]=0;
		 for(i=0;c[i];i++);
		 for(j=0,i=i-1;j<i;j++,i--)
		 {
		 t=c[i];
		 c[i]=c[j];
		 c[j]=t;
		 }	
lcd_cmd(1);
lcd_cmd(0x80); 
lcd_string("Distance: ");

lcd_string(c);	
delay_sec(1);
}
if(v.id==0x5)
{
lcd_cmd(1);
lcd_string("off: "); 
IOCLR0=1<<21;
IOSET0=1<<17;
delay_sec(1);

}
}


}
}
}
