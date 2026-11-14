#include <reg51.h>

//port initialization
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

void lcd_puts(char *str){
    while(*str){
        lcd_data(*str++);
    }
}



void main(){
    lcd_init();
    lcd_goto(0,0);
    lcd_data('S');
    lcd_puts(" 25011102098");
    lcd_goto(1,0);
    lcd_puts("LCD display");
    while(1){
    }
}
