#include <reg51.h>

sbit led1 = P1^3;
sbit led2 = P1^4;
sbit led3 = P1^5;
sbit led4 = P1^6;

sbit row1 = P2^7;
sbit col1 = P2^3;

void delay(){
	int i, j;
	for (i = 0 ; i < 400 ; i++){
		for (j = 0 ; j < 400 ; j++){
			}
	}
}

void mode_running(){
			led1 = 1;
			delay();
			led1 = 0;
			delay();
			led2 = 1;
			delay();
			led2 = 0;
			delay();
			led3 = 1;
			delay();
			led3 = 0;
			delay();
			led4 = 1;
			delay();
			led4 = 0;
}

bit button_pressed(){
	P2 = 0xFF;     

  col1 = 0;      
  if(row1 == 0)
       return 1;
   return 0;
}

void debounce(){
	while(button_pressed());
	delay();
}

void mode_binary_count(){
	int i,j,k,l;
	for (i = 0 ; i <= 1; i++){
		for (j = 0; j <= 1 ; j++){
			for (k = 0 ; k <= 1 ; k++){
				for (l = 0 ; l <= 1 ; l++){
					led1 = l;
					led2 = k;
					led3 = j;
					led4 = i;
					delay();
				}
			}
		}
	}
}

void mode_alternating(){
	led1 = 0;
	led2 = 1;
	led3 = 0;
	led4 = 1;
	delay();
	led1 = 1;
	led2 = 0;
	led3 = 1;
	led4 = 0;
	delay();
}

void mode_flash(){
	led1 = 1;
	led2 = 1;
	led3 = 1;
	led4 = 1;
	delay();
	led1 = 0;
	led2 = 0;
	led3 = 0;
	led4 = 0;
	delay();
}


void main(){
	int mode = 0;
	
	led1 = 0;
	led2 = 0;
	led3 = 0;
	led4 = 0;
	
	while (1) {
		if (button_pressed()) {
			debounce();
			
      mode++;
				
      if (mode > 4)
				mode = 1;
      }
			
      switch (mode) {
				case 1:
          mode_running();
          break;

        case 2:
					mode_binary_count();
          break;

         case 3:
           mode_alternating();
           break;

         case 4:
           mode_flash();
           break;
        }
    }
	
}