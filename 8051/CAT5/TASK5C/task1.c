#include <reg51.h>

sbit row1 = P2^7;
sbit row2 = P2^6;
sbit col1 = P2^3;

unsigned char sequence[4] = {0x08,0x04,0x02,0x01};
unsigned char speeds[3] = {100,50,10};
unsigned char step = 0;
unsigned char mode = 0;
unsigned char ms_count = 0;
unsigned char release1 = 0;
unsigned char release2 = 0;
bit direction = 0;
bit pressed1 = 0;
bit pressed2 = 0;

void timer0() interrupt 1{
    TH0 = 0xFC;
    TL0 = 0x66;
    if(row1 == 0){ pressed1 = 1; release1 = 0; }
    else if(pressed1 && ++release1 >= 20){
        direction = ~direction;
        pressed1 = 0;
    }
    if(row2 == 0){ pressed2 = 1; release2 = 0; }
    else if(pressed2 && ++release2 >= 20){
        mode++;
        if(mode >= 3) mode = 0;
        pressed2 = 0;
    }
    ms_count++;
    if(ms_count >= speeds[mode]){
        ms_count = 0;
        P1 = (P1 & 0xF0) | sequence[step];
        if(direction) step = (step + 3) % 4;
        else step = (step + 1) % 4;
    }
}

void main(){
    P2 = 0xFF;
    col1 = 0;
    TMOD = 0x01;
    TH0 = 0xFC;
    TL0 = 0x66;
    ET0 = 1;
    EA = 1;
    TR0 = 1;
    while(1){
    }
}
