#include <reg51.h>

sbit LED = P1^2;

unsigned char phase = 0;
unsigned char duty = 0;
bit up = 1;
unsigned int ms_count = 0;

void timer0() interrupt 1{
    TH0 = 0xFF;
    TL0 = 0xA4;
    phase++;
    if(phase >= 20) phase = 0;
    LED = phase < duty;
    ms_count++;
    if(ms_count >= 500){
        ms_count = 0;
        if(up){
            duty++;
            if(duty >= 20) up = 0;
        }
        else{
            duty--;
            if(duty == 0) up = 1;
        }
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
