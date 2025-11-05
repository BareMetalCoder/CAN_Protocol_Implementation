#include"header.h"
main()
{
//	u16 temp;
//	uart0_init(9600);//after->adc_init();
//	adc_init();
//	uart0_tx_string("ADC\r\n");
//
//	while(1)
//	{
//		temp=adc_read(2);//read ain2
//		uart0_tx_integer(temp);
//		uart0_tx_string("\r\n");//new line 
//		delay_ms(500);//optional
//	}
//}
/*-------------temprature-----------------------*/

//	u16 temp; 
//	float vout,temprature;
//	uart0_init(9600);
//	adc_init();
//	uart0_tx_string("mcp9700\r\n");
//	while(1)
//	{
//		temp=adc_read(1);     //read Ain 1
//			vout=((temp*3.3)/1023); //formulla to convert ADC output into vtg
//			temprature=((vout-0.5)/0.01);    //formulla to convert ADC output pin
//			uart0_tx_float(temprature);
//			uart0_tx_string("\r\n");
//			delay_ms(100);
//		}
//}
//		



//
	u16 temp; 
	float vout,temprature;
	float a[10];
	int i;
	uart0_init(9600);
	adc_init();
	uart0_tx_string("mcp9700\r\n");
	while(1)
	{
		for(i=0;i<10;i++)
		{
			temp=adc_read(1);     //read Ain 1
			vout=(temp*3.3)/1023; //formulla to convert ADC output into vtg
			temprature=(vout-0.5)/0.01;    //formulla to convert ADC output pin
//			uart_tx_float(temprature);
//			uart0_tx_string("\r\n");
//			delay_ms(100);
			a[i]=temprature;	
			//uart0_tx_float(temprature);
//			uart0_tx_string("\r\n");       //new line
//			delay_ms(100);
		}
		temprature=0;
		for(i=0;i<10;i++)
		{
			temprature=temprature+a[i];
		}
		temprature=temprature/10;
		uart0_tx_string("temprature is");
		uart0_tx_float(temprature);
		uart0_tx_string("\r\n");
		delay_sec(5);
}
}


