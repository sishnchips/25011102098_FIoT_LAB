#include <reg51.h>

sbit led1 = P1^3;
sbit led2 = P1^4;
sbit led3 = P1^5;
sbit led4 = P1^6;


sbit r1 = P2^7;
sbit r2 = P2^6;
sbit r3 = P2^5;
sbit r4 = P2^4;

sbit c1 = P2^3;
sbit c2 = P2^2;
sbit c3 = P2^1;
sbit c4 = P2^0;

void delay()
{
    int i, j;
    for(i = 0; i < 50; i++)
        for(j = 0; j < 50; j++);
}

void display_digit(char num)
{
    if(num == '0')
        P0 = 0x3F;
    else if(num == '1')
        P0 = 0x06;
    else if(num == '2')
        P0 = 0x5B;
    else if(num == '3')
        P0 = 0x4F;
    else if(num == '4')
        P0 = 0x66;
    else if(num == '5')
        P0 = 0x6D;
    else if(num == '6')
        P0 = 0x7D;
    else if(num == '7')
        P0 = 0x07;
    else if(num == '8')
        P0 = 0x7F;
    else if(num == '9')
        P0 = 0x6F;
    else if(num == 'A')
        P0 = 0x77;
    else if(num == 'B')
        P0 = 0x7C;
    else if(num == 'C')
        P0 = 0x39;
    else if(num == 'D')
        P0 = 0x5E;
		else if (num == 'E'){
				P0 = 0x79;
		}
		else if (num == 'F'){
				P0 = 0x71; 
		}
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

void led_control(char key){
    led1 = 0; led2 = 0; led3 = 0; led4 = 0;
    switch(key){
        case '1': led1 = 1; break;
        case '2': led2 = 1; break;
        case '3': led3 = 1; break;
        case '4': led4 = 1; break;
        case '5': mode_running(); break;
        case '6': mode_alternating(); break;
        case '7': mode_binary_count(); break;
        case '8': mode_flash(); break;
        case '9': break;
        case '0': P0 = 0x3F; break;
    }
}

void main()
{
    char key;

    P0 = 0x00;

    while(1)
    {
        key = keypad_scan();
        display_digit(key);
        led_control(key);
    }
}
