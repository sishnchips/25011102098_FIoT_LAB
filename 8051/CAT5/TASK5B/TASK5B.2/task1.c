#include <reg51.h>

sbit LED = P1^2;

unsigned char phase = 0;
unsigned char duty = 5;
unsigned int ms_count = 0;

void timer0() interrupt 1{
    TH0 = 0xFF;
    TL0 = 0xA4;
    phase++;
    if(phase >= 20) phase = 0;
    LED = phase < duty;
    ms_count++;
    if(ms_count >= 5000){
        ms_count = 0;
        duty += 5;
        if(duty > 15) duty = 5;
    }
}

void main(){
    TMOD = 0x01;
    TH0 = 0xFF;
    TL0 = 0xA4;
    ET0 = 1;
    EA = 1;
    TR0 = 1;
    while(1){
    }
}
