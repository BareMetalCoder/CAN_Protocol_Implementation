#include<lpc21xx.h>
#include"header.h"
main()
{
    u8 temp;
	lcd_init();
	i2c_init();
	uart0_init(9600);
	uart0_tx_string("i2c test \r\n");
	i2c_byte_write_frame(0xD0,0x2,0x41);   //(sa+w, m/r addr, data)
	delay_ms(10);
	temp=i2c_byte_read_frame(0xD0,0x06);   //(sa+w, m/r Addr)
	lcd_data(temp);
}
