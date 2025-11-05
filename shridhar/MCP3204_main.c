#include"header.h"
main()
{
	u16 temp;
	uart0_init(9600);
	spi0_init();
	uart0_tx_string("MCP3204 teseting\r\n");
	while(1)
	{
		temp=read_mcp3204(0); //read CH0
		uart0_tx_integer(temp);
		uart0_tx_string("\r\n");
		delay_ms(500);
	}
}
