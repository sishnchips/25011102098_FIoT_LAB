#include <reg51.h>

//port initialization
sbit r1 = P2^7;
sbit r2 = P2^6;
sbit r3 = P2^5;
sbit r4 = P2^4;

sbit c1 = P2^3;
sbit c2 = P2^2;
sbit c3 = P2^1;
sbit c4 = P2^0;


sbit RS = P3^2;
sbit E = P3^3;

//delay method
void delay(){
	unsigned char  i,j;
	for ( i = 0; i < 100 ; i++){
		for (j = 0 ; j < 100 ; j++){
		}
	}
}

//enable method
void enable(){
	E = 1;
	delay();
	E = 0;
}

//Method to send command
void lcd_cmd(unsigned char cmd){
	RS = 0;
	P3 = (P3 & 0x0F) | (cmd & 0xF0);
	enable();
	P3 = (P3 & 0x0F) | ((cmd & 0x0F) << 4);
	enable();
}

//Method to send data
void lcd_data(unsigned char cmd){
	RS = 1;
	P3 = (P3 & 0x0F)|(cmd & 0xF0);
	enable();
	P3 = (P3 & 0x0F)|((cmd & 0x0F) << 4);
	enable();
}

//Method to initizlise
void lcd_init(){
	RS = 0;
	E = 0;
	delay();
	P3 = (P3 & 0x0F) | 0x30;
	enable();
	delay();
	enable();
	delay();
	enable();
	P3 = (P3 & 0x0F) | 0x20;
	enable();
	lcd_cmd(0x28);
    lcd_cmd(0x01);  
  lcd_cmd(0x0C);   
  lcd_cmd(0x06);
}


void lcd_goto(unsigned char row, unsigned char column){
    lcd_cmd((row == 0 ? 0x80 : 0xC0) + column);
}






char keypad_scan()
{
    while(1)
    {
        r1 = 0;
        r2 = 1;
        r3 = 1;
        r4 = 1;

        if(c1 == 0)
        {
            while(c1 == 0);
            delay();
            return '1';
        }

        if(c2 == 0)
        {
            while(c2 == 0);
            delay();
            return '2';
        }

        if(c3 == 0)
        {
            while(c3 == 0);
            delay();
            return '3';
        }

        if(c4 == 0)
        {
            while(c4 == 0);
            delay();
            return 'A';
        }

        r1 = 1;
        r2 = 0;
        r3 = 1;
        r4 = 1;

        if(c1 == 0)
        {
            while(c1 == 0);
            delay();
            return '4';
        }

        if(c2 == 0)
        {
            while(c2 == 0);
            delay();
            return '5';
        }

        if(c3 == 0)
        {
            while(c3 == 0);
            delay();
            return '6';
        }

        if(c4 == 0)
        {
            while(c4 == 0);
            delay();
            return 'B';
        }

        r1 = 1;
        r2 = 1;
        r3 = 0;
        r4 = 1;

        if(c1 == 0)
        {
            while(c1 == 0);
            delay();
            return '7';
        }

        if(c2 == 0)
        {
            while(c2 == 0);
            delay();
            return '8';
        }

        if(c3 == 0)
        {
            while(c3 == 0);
            delay();
            return '9';
        }

        if(c4 == 0)
        {
            while(c4 == 0);
            delay();
            return 'C';
        }

        r1 = 1;
        r2 = 1;
        r3 = 1;
        r4 = 0;

        if(c1 == 0)
        {
            while(c1 == 0);
            delay();
            return 'E';
        }

        if(c2 == 0)
        {
            while(c2 == 0);
            delay();
            return '0';
        }

        if(c3 == 0)
        {
            while(c3 == 0);
            delay();
            return 'F';
        }

        if(c4 == 0)
        {
            while(c4 == 0);
            delay();
            return 'D';
        }
    }
}

void main(){
    unsigned char row = 0;
    unsigned char column = 0;
    char key;
    lcd_init();
    lcd_goto(row,column);
    lcd_data('S');
    while(1){
        key = keypad_scan();
        lcd_goto(row,column);
        lcd_data(' ');
        if(key == '2' && row > 0) row--;
        if(key == '8' && row < 1) row++;
        if(key == '4' && column > 0) column--;
        if(key == '6' && column < 15) column++;
        lcd_goto(row,column);
        lcd_data('S');
    }
}
