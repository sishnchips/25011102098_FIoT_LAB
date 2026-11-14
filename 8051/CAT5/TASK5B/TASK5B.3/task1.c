#include <reg51.h>

sbit LED = P1^2;
unsigned char ms_count = 0;

void timer0() interrupt 1{
    TH0 = 0xFC;
    TL0 = 0x66;
    ms_count++;
    if(ms_count >= 10) ms_count = 0;
    LED = ms_count == 0;
}

void main(){
    TMOD = 0x01;
    TH0 = 0xFC;
    TL0 = 0x66;
    ET0 = 1;
    EA = 1;
    TR0 = 1;
    while(1){
    }
}
