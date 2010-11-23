void uart_init(void);         /* Initialize UART */
uint8_t uart_get (void);      /* Get a byte from UART Rx */
uint8_t uart_test(void);      /* Check number of data in UART Rx FIFO */
void uart_put_test(uint8_t device, unsigned char data);   /* Transmit a byte*/
void uart_put(unsigned char);   /* Transmit a byte*/
void uart_puts(const char *s);   /* Transmit a string of bytes*/ 
void uart1_put(unsigned char);
