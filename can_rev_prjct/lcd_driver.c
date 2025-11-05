/*lcd_driver*/
#include"header.h"
   					//LCD DATA
void lcd_data(u8 data)
{

	
	IOCLR1=0X00FE0000;
	IOSET1=(data&0XF0)<<16;
	  IOSET1=1<<17;
	  IOCLR1=1<<18;
	  IOSET1=1<<19;
	  delay_ms(2);
	  IOCLR1=1<<19;
	
	IOCLR1=0X00FE0000;
	IOSET1=(data&0X0F)<<20;
	  IOSET1=1<<17;
	  IOCLR1=1<<18;
	  IOSET1=1<<19;
	  delay_ms(2);
	  IOCLR1=1<<19;
 }			

  					//cmd		
  void lcd_cmd(u8 cmd)
  {

	 	IOCLR1=0X00FE0000;
	IOSET1=(cmd&0XF0)<<16;
	  IOCLR1=1<<17;//RS
	  IOCLR1=1<<18;//RW
	  IOSET1=1<<19;//EN
	  delay_ms(2);
	  IOCLR1=1<<19;	//EN
	
	IOCLR1=0X00FE0000;
	IOSET1=(cmd&0X0F)<<20;
	  IOCLR1=1<<17;
	  IOCLR1=1<<18;
	  IOSET1=1<<19;
	  delay_ms(2);
	  IOCLR1=1<<19;
 }


  				//LCD INIT
  void lcd_init(void)
  {	   PINSEL2 =0;
  	  IODIR1=0X00FE0000;
	
	  lcd_cmd(0x03);
	  lcd_cmd(0x02);
	  lcd_cmd(0x28);
	  lcd_cmd(0xe);
	  lcd_cmd(0x01);
	  lcd_cmd(0x80);
  }


  				//LCD STRING
  void lcd_string( s8 *ptr)
  {
  while(*ptr)
	  {
	  lcd_data(*ptr);
	  ptr++;
	  }
  }


  

 /* void integer(unsigned int num)
{

 unsigned int num1=num,i,c=0,div;
 for(i=0;num1;num1/=10)
  c++;
 for(i=1,div=1;i<c;i++)
 div=div*10;

 for(;div;div/=10)
 {
 lcd_data((num/div)+48);
 num=num%div;
 
 }
} */ 
