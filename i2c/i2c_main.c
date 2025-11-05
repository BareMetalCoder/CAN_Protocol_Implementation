#include"header.h"
main()
{
	u8 h,m,s,dow,d,mo,y,h1;
	i2c_init();
	lcd_init();
	
	/*set the time 11:59:50 pm*/
//	i2c_byte_write_frame(0xD0,0x2,0x48);
//  i2c_byte_write_frame(0xD0,0x1,0x59);
//i2c_byte_write_frame(0xD0,0x0,0x57);
//	i2c_byte_write_frame(0xD0,0x2,0xff);

	/*set day,date,month and year*/
	i2c_byte_write_frame(0xD0,0x3,0x1);
	i2c_byte_write_frame(0xD0,0x4,0x7);
	i2c_byte_write_frame(0xD0,0x5,0x4);
	i2c_byte_write_frame(0xD0,0x6,0x24);

   
	/*read rtc time and dump it on the lcd*/

	while(1)
	{	lcd_cmd(0x80);
		h=i2c_byte_read_frame(0xD0,0x2);
		h1=h&0x0f;
		m=i2c_byte_read_frame(0xD0,0x1);
		s=i2c_byte_read_frame(0xD0,0x0);
		dow=i2c_byte_read_frame(0xD0,0x3);
		d=i2c_byte_read_frame(0xD0,0x4);
		mo=i2c_byte_read_frame(0xD0,0x5);
		y=i2c_byte_read_frame(0xD0,0x6);
		
	
		lcd_data((h1/0x10)+48);
		lcd_data((h1%0x10)+48);
		lcd_data(':');


		lcd_data((m/0x10)+48);
		lcd_data((m%0x10)+48);
		lcd_data(':');

		lcd_data((s/0x10)+48);
		lcd_data((s%0x10)+48);

		if((h>>5)&1)
		lcd_string( "PM");
		else
		lcd_string( "AM");

		lcd_cmd(0xc0);
		lcd_data((d/0x10)+48);
		lcd_data((d%0x10)+48);
		lcd_data(':');


		lcd_data((mo/0x10)+48);
		lcd_data((mo%0x10)+48);
		lcd_data(':');
		lcd_string("20");
		lcd_data((y/0x10)+48);
		lcd_data((y%0x10)+48);
	   	lcd_cmd(0xc15);
		if(dow==1)
		{
		lcd_string("SUN");
		}
		if(dow==2)
		{
		lcd_string("MON");
		}
		if(dow==3)
		{
		lcd_string("TUE");
		}
		 if(dow==4)
		{
		lcd_string("WED");
		}
		if(dow==5)
		{
		lcd_string("THU");
		}
		 if(dow==6)
		{
		lcd_string("FRI");
		}
		if(dow==7)
		{
		lcd_string("SAT");
		}
		}
}
