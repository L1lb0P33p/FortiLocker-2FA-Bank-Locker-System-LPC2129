#include <lpc21xx.h>

#define LCD_D  (0xFF<<4)
#define RS     (1<<12)
#define E      (1<<13)

void delay_ms(unsigned int);
void delay_sec(unsigned int);

void LCD_INIT(void);
void LCD_COMMAND(unsigned char);
void LCD_DATA(unsigned char);
void LCD_STR(unsigned char *);
void scroll_title(unsigned char *);

void delay_ms(unsigned int ms)
{
    T0PR = 15000-1;
    T0TCR = 0x01;

    while(T0TC < ms);

    T0TCR = 0x03;
    T0TCR = 0x00;
}

void delay_sec(unsigned int s)
{
    T0PR = 15000000-1;
    T0TCR = 0x01;

    while(T0TC < s);

    T0TCR = 0x03;
    T0TCR = 0x00;
}

void LCD_COMMAND(unsigned char cmd)
{
    IOCLR0 = LCD_D;
    IOSET0 = cmd<<4;
    IOCLR0 = RS;
    IOSET0 = E;
    delay_ms(2);
    IOCLR0 = E;
}

void LCD_DATA(unsigned char d)
{
    IOCLR0 = LCD_D;
    IOSET0 = d<<4;
    IOSET0 = RS;
    IOSET0 = E;
    delay_ms(2);
    IOCLR0 = E;
}

void LCD_STR(unsigned char *s)
{
    while(*s)
    {
        LCD_DATA(*s++);
    }
}

void LCD_INIT(void)
{
    IODIR0 |= LCD_D | RS | E;

    LCD_COMMAND(0x01);
    LCD_COMMAND(0x02);
    LCD_COMMAND(0x0C);
    LCD_COMMAND(0x38);
}

/* Title Scroll Function */

void scroll_title(unsigned char *str)
{
    int i,j;

    for(i=15;i>=0;i--)
    {
        LCD_COMMAND(0x01);
        LCD_COMMAND(0x80+i);

        for(j=0;str[j]!='\0';j++)
        {
            LCD_DATA(str[j]);
        }

        delay_ms(250);
    }

    delay_sec(2);

    LCD_COMMAND(0x01);
}