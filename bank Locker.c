#include <lpc21xx.h>
#include <string.h>

#include "lcdheader.h"
#include "UARTheader.h"
#include "GSM.h"
#include "keypad 4x4.h"

#define M1      (1<<20)
#define M2      (1<<21)
#define BUZZER  (1<<19)
#define LED     (1<<18)

char password[] = "1213";
char password_enter[5];
char otp_enter[5];
char otp[5];

int attempts = 0;
int otp_num;

void get_password(char *);
void get_otp(char *);
void generate_otp(void);
void buzzer_on(void);
void buzzer_off(void);
void locker_open(void);
void locker_close(void);

int main()
{
  IODIR0 |= M1 | M2 | BUZZER |LED;

    LCD_INIT();
    UART0_CONFIG();
	  UART0_STR("testing");
    scroll_title("FORTILOCKERS");
	T1PR=0;
	T1TCR=0x01;

    while(1)
    {
        LCD_COMMAND(0x01);
        LCD_STR("ENTER PASSWORD");
        LCD_COMMAND(0xC0);

        get_password(password_enter);

        if(strcmp(password_enter,password)==0)
        {
            attempts = 0;

            generate_otp();

            LCD_COMMAND(0x01);
            LCD_STR("OTP SENDING");

            SEND_OTP_SMS(otp);

            delay_sec(3);

            LCD_COMMAND(0x01);
            LCD_STR("ENTER OTP");
            LCD_COMMAND(0xC0);

            get_otp(otp_enter);

           if(strcmp(otp_enter,otp)==0)
{
    int sec;

    LCD_COMMAND(0x01);
    LCD_STR("ACCESS GRANTED");
    delay_sec(2);

    locker_open();

    for(sec=10; sec>0; sec--)
    {
        LCD_COMMAND(0x01);
        LCD_STR("LOCKER OPEN");

        LCD_COMMAND(0xC0);
        LCD_STR("TIME:");

        LCD_DATA((sec/10)+'0');
        LCD_DATA((sec%10)+'0');
        LCD_DATA('S');

        IOSET0 = LED;      // LED ON
        delay_ms(500);

        IOCLR0 = LED;      // LED OFF
        delay_ms(500);
		}
    
    locker_close();
    IOCLR0 = LED;
    LCD_COMMAND(0x01);
    LCD_STR("LOCKER CLOSED");
    delay_sec(2);
}
            else
            {
                LCD_COMMAND(0x01);
                LCD_STR("INVALID OTP");

                buzzer_on();
                delay_sec(10);
                buzzer_off();
            }
        }
        else
        {
            attempts++;

            LCD_COMMAND(0x01);

            if(attempts == 1)
            {
                LCD_STR("PIN NOT MATCHED");
                LCD_COMMAND(0xC0);
                LCD_STR("2 ATTEMPTS LEFT");
            }
            else if(attempts == 2)
            {
                LCD_STR("PIN NOT MATCHED");
                LCD_COMMAND(0xC0);
                LCD_STR("1 ATTEMPT LEFT");
            }
            else
            {
                LCD_STR("3 ATTEMPTS OVER");
                LCD_COMMAND(0xC0);
                LCD_STR("TRY AFTER 24HRS");

                SEND_ALERT_SMS();

                buzzer_on();
                delay_sec(10);
                buzzer_off();

                while(1);
            }

            buzzer_on();
            delay_sec(2);
            buzzer_off();

            delay_sec(2);
        }
    }
}

/* PASSWORD ENTRY */
void get_password(char *s)
{
    int i;

    for(i=0;i<4;i++)
    {
        s[i] = keyscan();
		UART0_TX(s[i]);
        LCD_DATA('*');
        delay_ms(200);
    }

    s[4] = '\0';
}

/* OTP ENTRY */
void get_otp(char *p)
{
    int i;

    for(i=0;i<4;i++)
    {
        p[i] = keyscan();
		UART0_TX(p[i]);
        LCD_DATA('*');
        delay_ms(200);
    }

    p[4] = '\0';
}

/* OTP GENERATION */
void generate_otp(void)
{
    int i,temp;
	unsigned int s =T1TC;

   otp_num=((s>>3)^(s>>7)^s)%9000 + 1000;

    temp = otp_num;

    for(i=3;i>=0;i--)
    {
        otp[i] = (temp % 10) + '0';
        temp /= 10;
    }

    otp[4] = '\0';
}
/*void generate_otp(void)
{
    int i,temp;

    otp_num = (T1TC % 9000) + 1000;

    temp = otp_num;

    for(i=3;i>=0;i--)
    {
        otp[i] = (temp%10) + '0';
        temp /= 10;
    }

    otp[4] = '\0';
}
*/

/* BUZZER */
void buzzer_on(void)
{
    IOSET0 = BUZZER;
}

void buzzer_off(void)
{
    IOCLR0 = BUZZER;
}

/* LOCKER OPEN */
void locker_open(void)
{
    IOSET0 = M1;
    IOCLR0 = M2;

    delay_sec(3);

    IOCLR0 = M1;
}

/* LOCKER CLOSE */
void locker_close(void)
{
    IOSET0 = M2;
    IOCLR0 = M1;

    delay_sec(3);

    IOCLR0 = M2;
}

}

/* LOCKER OPEN */
void locker_open(void)
{
    IOSET0 = M1;
    IOCLR0 = M2;

    delay_sec(3);

    IOCLR0 = M1;
}

/* LOCKER CLOSE */
void locker_close(void)
{
    IOSET0 = M2;
    IOCLR0 = M1;

    delay_sec(3);

    IOCLR0 = M2;
}
