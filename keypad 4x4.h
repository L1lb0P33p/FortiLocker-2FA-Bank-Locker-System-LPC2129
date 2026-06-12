#include <lpc21xx.h>


#define C0 (IOPIN1&(1<<20))
#define C1 (IOPIN1&(1<<21))
#define C2 (IOPIN1&(1<<22))
#define C3 (IOPIN1&(1<<23))

#define R0 (1<<16)
#define R1 (1<<17)
#define R2 (1<<18)
#define R3 (1<<19)

unsigned char key_lut[4][4] =
{
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

unsigned char keyscan(void)
{
    unsigned char row_val,col_val;

    IODIR1 |= (R0|R1|R2|R3);

    while(1)
    {
IOCLR1= R0|R1|R2|R3;
        IOSET1 = C0|C1|C2|C3;

        while((C0 && C1 && C2 && C3)==1);

        IOCLR1 = R0;
        IOSET1 = R1|R2|R3;

        if((C0 && C1 && C2 && C3)==0)
        {
            row_val = 0;
            break;
        }

        IOCLR1 = R1;
        IOSET1 = R0|R2|R3;

        if((C0 && C1 && C2 && C3)==0)
        {
            row_val = 1;
            break;
        }

        IOCLR1 = R2;
        IOSET1 = R0|R1|R3;

        if((C0 && C1 && C2 && C3)==0)
        {
            row_val = 2;
            break;
        }

        IOCLR1 = R3;
        IOSET1 = R0|R1|R2;

        if((C0 && C1 && C2 && C3)==0)
        {
            row_val = 3;
            break;
        }
    }

    if(C0==0)
        col_val = 0;
    else if(C1==0)
        col_val = 1;
    else if(C2==0)
        col_val = 2;
    else
        col_val = 3;

    delay_ms(150);

    while((C0&&C1&&C2&&C3)==0);

    return key_lut[row_val][col_val];
}