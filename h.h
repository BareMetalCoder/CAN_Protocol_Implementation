			//header .h//
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef signed char s8;
typedef unsigned short int u16;

extern void delay_sec(unsigned int);
extern void delay_ms(unsigned int);

extern void uart0_init(unsigned int);
extern void uart0_tx(unsigned char);
extern void uart0_tx_string(s8 *);
extern void uart0_rx_string(s8 *ptr , u8 len);
extern u8 uart0_rx(void);
extern void uart0_tx_integer(s32);
extern void uart0_tx_float(float);


/*----------I2C---------------------*/
extern void i2c_init(void);
extern void i2c_byte_write_frame(u8 sa,u8 mr,u8 data);
extern u8 i2c_byte_read_frame(u8 sa,u8 mr);

/*-------------------UART1---------------------*/
extern void delay_sec(unsigned int);
extern void delay_ms(unsigned int);
extern void uart1_init(unsigned int);
extern void uart1_tx(unsigned char);
extern void uart0_tx_string(s8 *);
extern void uart1_rx_string(s8 * , u8 );
extern u8 uart1_rx(void);

//---------ADC------------------------
extern void adc_init(void);
extern u16 adc_read(u8 ch_num);

//---------SPI--------------------
#define cs0 (1<<7)
extern void spi0_init(void);
extern u8 spi0(u8 data);
extern u16 read_mcp3204(u8 ch_num);

//-----------lcd -----------------

extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init(void);
extern void lcd_string(signed char *);

//------------interrupt---------------
//extern void uart0_handle(void)__irq;
extern void config_VIC_for_uart0(void);
extern void en_uart0_interrupt(void);
//extern void uart0_handl(void)__irq;
//------Timer interrupt------------
extern void en_timer1_interrupt(void);
extern void config_VIC_for_timer1(void);
//-----------external interrupt----------------
extern void	config_VIC_for_extern(void);
extern void en_extern_interrupt(void);

//----------CAN1--------------------------
typedef struct CAN1_MSG
{
	u32 id;
	u32 byteA;
	u32 byteB;
	u8 dlc;
	u8 rtr;
}CAN1;
extern void can1_rx(CAN1 *ptr);
extern void can1_tx(CAN1 v);
extern void can1_init(void);
extern void uart0_tx_hex(u32 n);
extern void uart0_hex(u8 data);
extern void config_vic_for_can1(void);
extern void en_can1_interrupt(void);;


/*void UART0_INIT(unsigned int );
void UART0_TX(unsigned char );
unsigned char UART0_RX(void);
 void UART0_STRING(s8 *);
 */
