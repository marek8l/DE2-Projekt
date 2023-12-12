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
    }
    return 0;
}

/*
Funkce: ISR
----------------------
Při přetečení timeru (1s) se zavolá a vykoná vše co je uvnitř.
Pokuď je had naživu dojde k vykonání první části kodu, v této části dojde k přečtení vstupů tlačítek a následně k určení nového směru.
Poté dojde ke kontrole, zda-li je had stále naživu, v případě, že had narazí do svého ocasu, anebo narazí mimo arénu, dojde k změně stavu a vykoná se 
poslednoí část kodu, který napíše gamer over a zobrazí konečné skore hráče 
*/
ISR(TIMER1_OVF_vect){
 if (death == 0){
    
        readButtonInput();

        pix[x_pos][y_pos] = direction;
        switch (direction) {
            case LEFT:
                x_pos--;
                break;
            case RIGHT:
                x_pos++;
                break;
            case UP:
                y_pos--;
                break;
            case DOWN:
                y_pos++;
                break;
        }

        if ((x_pos <= WINDOW_MIN_X) || (x_pos >= WINDOW_MAX_X) || (y_pos <= WINDOW_MIN_Y) || (y_pos >= WINDOW_MAX_Y))
            death = 1;
        if (pix[x_pos][y_pos] != -1)
            death = 1;

        oled_drawPixel(x_pos, y_pos, WHITE);
        
        if ((x_pos == x_treat) && (y_pos == y_treat)){
            score += 10;
            generateNewTreat();
            oled_display();
        }
        else {
            moveTailByOne();
            oled_display();
        }
        

       // oled_display();
    }
    else {
        gameOver();
    }
}