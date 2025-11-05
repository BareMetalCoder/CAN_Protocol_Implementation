
/////////////////////////////////////////////////////////////////////////
#include"header.h"

/*void integer(unsigned int num)
{

 unsigned int num1=num,i,c,div;
 for(i=0;num1;num1/=10)
 
 for(i=1,div=1;i<c;i++)
 div=div*10;

 for(;div;div/=10)
 {
 lcd_data((num/div)+48);
 num=num%div;
 
 }
}  	 */

   u32 ultrasonic(void)
 {
s32 b,d;
 PINSEL0=0;
IODIR0=(1<<0)|(0<<1);

 T1TC=0;
 T1PC=0;
 T1PR=32;
 T1TCR=0;
 IOSET0=1<<0;
 delay_ms(100);
 IOCLR0=1<<0;

 while(!(IOPIN0&(1<<1)));
 T1TCR=1;
 d=T1TC;
 while(IOPIN0&(1<<1));
 T1TCR=0;
  b=T1TC;

  return (b-d);
 }

 /////////////////////////////////////////////////////
/* void lcd_ultra(void)
 {
 
unsigned int a;
PINSEL0=0;


IODIR0=(1<<0)|(0<<1);
lcd_init();
while(1)
{
lcd_cmd(0x80);

a=ultrasonic();
integer((a/59));
delay(500);
lcd_cmd(0x01);

 
 }

 }	


 /////////////////////////////////////////////////////
void lcd_ultra(void)
 {
  
unsigned int a;
PINSEL0=0;


IODIR0=(1<<0)|(0<<1);
lcd_init();
while(1)
{
lcd_cmd(0x80);

a=ultrasonic();
integer((a/59));
delay(500);
lcd_cmd(0x01);

 
 }

 } */
