#define OLED_address  0x3c
#define INTERNAL_I2C_PULLUPS

size_t i2c_read_reg_to_buf(uint8_t add, uint8_t reg, void *buf, size_t size);
size_t i2c_read_to_buf(uint8_t add, void *buf, size_t size);
uint8_t i2c_read(uint8_t ack); 
uint8_t i2c_readAck(); 
uint8_t i2c_readNak(void); 
void  i2c_OLED_init(void);
void SendChar(unsigned char data);
void clear_display(void);
void i2c_OLED_send_byte(uint8_t val);
void i2c_OLED_send_cmd(uint8_t command);
void i2c_init(void);
void i2c_rep_start(uint8_t address);
void i2c_stop(void);
void i2c_write(uint8_t data );	
void i2c_writeReg(uint8_t add, uint8_t reg, uint8_t val);
void init_OLED(void);
void loop();
void print_a_char(unsigned char ascii);
void sendStr(unsigned char *string);
void sendcommand(unsigned char com);
void setXY(unsigned char row,unsigned char col);
void setup();
void swap_endianness(void *buf, size_t size);
void waitTransmissionI2C();


