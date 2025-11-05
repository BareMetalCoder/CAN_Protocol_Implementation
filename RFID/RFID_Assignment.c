


#include"header.h"
main()
{

/*scan RFID card num from uart1 & send RFID card num serial terminal through uart0*/
	s8 arr[13];
	 uart0_init(9600);
	 uart1_init(9600);
	 while(1)
	 {
	 	uart1_rx_string(arr,12);
		uart0_tx_string(arr);
		uart0_tx_string("\r\n");
	}

}


///*scan RFID card number from UART1 and send RFID card number to serial terminal through UART0*/
//	s8 arr[13];
//	uart0_init(9600);
//	lcd_init();
//	while(1)
//	{
//		uart0_rx_string(arr,12);
//		uart0_tx_string(arr);
//		lcd_cmd(0x01);
//		lcd_string(arr);
//		uart0_tx_string("\r\n");
//		}
//}
