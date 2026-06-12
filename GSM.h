#ifndef GSM_H
#define GSM_H
extern char otp[5];

void SEND_OTP_SMS(char *);
void SEND_ALERT_SMS(void);

void SEND_OTP_SMS(char *s)
{
UART0_STR("AT\r");

delay_ms(1000);

UART0_STR("AT+CMGF=1\r");

delay_ms(1000);

UART0_STR("AT+CMGS=\"+918825618838\"\r");

delay_ms(1000);
UART0_STR("received otp is");

UART0_STR(s);

delay_ms(1000);

UART0_TX(0x1A);

delay_ms(3000);
}

void SEND_ALERT_SMS(void)
{
UART0_STR("AT\r");

delay_ms(1000);

UART0_STR("AT+CMGF=1\r");

delay_ms(1000);

UART0_STR("AT+CMGS=\"+918825618838\"\r");

delay_ms(1000);

UART0_STR("ALERT! SYSTEM LOCKED");

delay_ms(1000);

UART0_TX(0x1A);

delay_ms(3000);
}
#endif