#include <reg51.h>

sbit LED = P1^2;
sbit row1 = P2^7;
sbit col1 = P2^3;

unsigned char high_reload[5] = {0xEE,0xFC,0xFE,0xFF,0xFF};
unsigned char low_reload[5] = {0x00,0x66,0x33,0x1A,0xA4};
volatile unsigned char mode = 0;
bit pressed = 0;

void timer0() interrupt 1{
    TH0 = high_reload[mode];
    TL0 = low_reload[mode];
    LED = ~LED;
}

void main(){
    TMOD = 0x01;
    TH0 = high_reload[0];
    TL0 = low_reload[0];
    row1 = 1;
    col1 = 0;
    ET0 = 1;
    EA = 1;
    TR0 = 1;
    while(1){
        if(row1 == 0) pressed = 1;
        else if(pressed){
            pressed = 0;
            EA = 0;
            mode++;
            if(mode >= 5) mode = 0;
            EA = 1;
        }
    }
}
