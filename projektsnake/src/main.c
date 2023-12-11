#include <avr/io.h>
#include <avr/interrupt.h>
#include "oled.h"
#include "gpio.h"
#include "timer.h"
#include "twi.h"
#include "snake.h"
#include "snake.c"

/*
Funkce: main
----------------------
Slouží k vykonání jádra celého programu
Inicializace OLED displeje, inicializace tlačítek a nastavení timeru 1
*/

void main(){
    oled_init(OLED_DISP_ON);
    oled_clrscr();
    oled_display();

    GPIO_mode_input_pullup(&DDRD, LEFT);
    GPIO_mode_input_pullup(&DDRD, RIGHT);
    GPIO_mode_input_pullup(&DDRD, UP);
    GPIO_mode_input_pullup(&DDRD, DOWN);

    TIM1_OVF_1SEC
    TIM1_OVF_ENABLE
    sei();

    reset();

    while (1){
    readButtonInput();
    generateNewTreat();
    moveTailByOne();
    CheckState();
    }
}



ISR(TIMER1_OVF_vect){
    if (death == 0){
        state=0;
        }
    else {
        state=1;
        }
    }