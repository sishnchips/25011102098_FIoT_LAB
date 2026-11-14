#include <reg51.h>

sbit led = P1^7;


void delay(){
	int i, j;
	for (i = 0 ; i < 400 ; i++){
		for (j = 0 ; j < 400 ; j++){
			}
	}
}


void blink1(){
	led = 1;
	delay();
	led = 0;
	delay();
}


void main(){
	led = 0;
	while(1){
		blink1();
	}
}

