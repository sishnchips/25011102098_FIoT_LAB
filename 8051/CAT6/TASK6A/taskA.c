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

void uart_send(char c){
    SBUF = c;
    while(TI == 0);
    TI = 0;
}

void main(){
    char *msg;
    uart_init();
    while(1){
        msg = "Hello from 8051\r\n";
        while(*msg){
            uart_send(*msg++);
        }
    }
}
