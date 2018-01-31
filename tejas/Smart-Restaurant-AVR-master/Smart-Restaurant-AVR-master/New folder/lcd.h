#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define CPORT PORTA
#define RS 7
#define EN 6


#define DPORT PORTA
#define D7	2
#define DPORT PORTA
#define D6	3
#define DPORT PORTA
#define D5	4
#define DPORT PORTA
#define D4	5

#include <util/delay.h>


#define DDR(x) (*(&x - 1))      


#define LCD_CLR 0                  
#define	LCD_STROBE()	((CPORT |= (1 << EN)),(CPORT &= ~(1 << EN)))







static void lcd_write(uint8_t c)
{
	_delay_us(40);

	if(c & 0x80)
		DPORT |=  (1 << D7);
	else
		DPORT &= ~(1 << D7);
	
	if(c & 0x40)
		DPORT |=  (1 << D6);
	else
		DPORT &= ~(1 << D6);
	
	if(c & 0x20)
		DPORT |=  (1 << D5);
	else
		DPORT &= ~(1 << D5);
		
	if(c & 0x10)
		DPORT |=  (1 << D4);
	else
		DPORT &= ~(1 << D4);
	
	LCD_STROBE();
	

	if(c & 0x08)
		DPORT |=  (1 << D7);
	else
		DPORT &= ~(1 << D7);
		
	if(c & 0x04)
		DPORT |=  (1 << D6);
	else
		DPORT &= ~(1 << D6);
		
	if(c & 0x02)
		DPORT |=  (1 << D5);
	else
		DPORT &= ~(1 << D5);
		
	if(c & 0x01)
		DPORT |=  (1 << D4);
	else
		DPORT &= ~(1 << D4);
	
	LCD_STROBE();
}

void lcd_clear(void)
{
	CPORT &= ~(1 << RS);
	lcd_write(1<<LCD_CLR);
	_delay_ms(2);
}

void lcd_goto(unsigned char pos)
{
	CPORT &= ~(1 << RS);
	lcd_write(0x80|pos);
}


void lcd_gotoxy( unsigned char x, unsigned char y )
{
	lcd_goto( y*64+x );
}

void lcd_init()
{
	DDR(CPORT) |= (1 << RS);
	DDR(CPORT) |= (1 << EN);
	
	DDR(DPORT) |= (1 << D7);
	DDR(DPORT) |= (1 << D6);
	DDR(DPORT) |= (1 << D5);
	DDR(DPORT) |= (1 << D4);
	
	CPORT &= ~(1 << RS);
	CPORT &= ~(1 << EN);
	
	_delay_ms(15);	

	DPORT |= (1 << D4);
	DPORT |= (1 << D5);
	DPORT &= ~(1 << D6);
	DPORT &= ~(1 << D7);
	
	LCD_STROBE();
	_delay_ms(5);
	LCD_STROBE();
	_delay_us(200);
	LCD_STROBE();
	_delay_us(200);
	
	
	DPORT &= ~(1 << D4);	
	DPORT |=  (1 << D5);	
	DPORT &= ~(1 << D6);	
	DPORT &= ~(1 << D7);	
	
	LCD_STROBE();

	lcd_write(0x28);		
	lcd_write(0b00001100);	
	lcd_clear();			
	lcd_write(0x6);			
}

void lcd_puts(const char * s)
{
	CPORT|= (1 << RS);	
	while(*s)
	lcd_write(*s++);
}

void lcd_putc(char x)
{
	CPORT|= (1 << RS);
	lcd_write(x);
}

void lcd_num(int in)
{
	int c;
	char temp[100];
	int index=0;
		do 
		{
			c=in%10;
			in=in/10;
			temp[index]=c+'0';
			index++;
		}
		while (in!=0);
		for (i=index-1;i>=0;i--)
		{
			lcd_putc(temp[i]);
		}
}









