#include<lpc21xx.h>
#include"header.h"
main()
{
	u8 h,m,s,dow,mo,y,h1;
	i2c_init();
	lcd_init();

/*	/*set RTC time to 11:59:50pm*
	i2c_byte_write_frame(0xD0,0x02,0x23); //set hrs
	i2c_byte_write_frame(0xD0,0x01,0x59); //set mins
	i2c_byte_write_frame(0xD0,0x0,0x58);  //set sec
										 
		/*set day date time and year */
		i2c_byte_write_frame(0xD0,0x3,0x01);
		i2c_byte_write_frmae(0xD0,0x4,0x7);
		i2c_byte_write_frame(0xD0,0x5,0x4);
		i2c_byte_write_frame(0xD0,0x6,0x24);
		 
/*	/* read RTC frame & dump it on the lcd*/
	while(1)
	{
		lcd_cmd(0x80);
		h=i2c_byte_read_frame(0xD0,0x2);  //read hrs
		h1=h&0xf;
		m=i2c_byte_read_frame(0xD0,0x1);  //read min
		s=i2c_byte_read_frame(0xD0,0x0);  //read sec
		dow=i2c_byte_read_frame(0xD0,0x3);
		d=i2c_byte_read_frame(0xD0,0x04);
		mo=i2c_byte_read_frmae(0xD0,0x5);
		y=i2c_byte_read_frame(0xD0,0x6);

		//lcd_cmd(0x80);
		lcd_data((h/0x10)+48);
		lcd_data((h%0x10)+48);
		lcd_data(':');
		lcd_data((m/0x10)+48);
		lcd_data((m%0x10)+48);
		lcd_data(':');
		lcd_data((s/0x10)+48);
		lcd_data((s%0x10)+48);
	}
}
