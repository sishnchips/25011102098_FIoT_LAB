#include <reg51.h>

void uart_init()
{
    TMOD = 0x20;
    TH1 = 0xFA;
    PCON |= 0x80;
    TR1 = 1;

    SCON = 0x50;

    TI = 0;
    RI = 0;
}

void main()
{
    char c;

    uart_init();

    while(1)
    {
        while(RI == 0);

        c = SBUF;
        RI = 0;

        SBUF = c;

        while(TI == 0);
        TI = 0;
    }
}