#include <avr/io.h>
#include <avr/interrupt.h>
#include "oled.h"
#include "gpio.h"
#include "twi.h"
#include "snake.h"

/* 
Funkce: reset
------------------------
Nastavení všech globálních proměnných na jejich počátečních hodnot
Vykreslení herního okna, počáteční pozice hada a jídla
*/
void reset(){
    direction = RIGHT;
    prev_dir = RIGHT;
    x_pos = STARTING_X_POS;
    y_pos = STARTING_Y_POS;
    x_tail = STARTING_X_POS-2;
    y_tail = STARTING_Y_POS;
    death = 0;
    score = 0;
    random_var = MAGIC_CONSTANT;

    for (int i = 0; i<SCREEN_WIDTH; i++){
        for (int j = 0; j<SCREEN_HEIGHT; j++){
            pix[i][j] = -1;
        }
    }

    generateNewTreat();

    oled_clrscr();
    oled_drawRect(WINDOW_MIN_X, WINDOW_MIN_Y, WINDOW_MAX_X-WINDOW_MIN_X, WINDOW_MAX_Y-WINDOW_MIN_Y, WHITE);
    oled_drawPixel(STARTING_X_POS-2, STARTING_Y_POS, WHITE);
    oled_drawPixel(STARTING_X_POS-1, STARTING_Y_POS, WHITE);
    oled_drawPixel(STARTING_X_POS-0, STARTING_Y_POS, WHITE);
    pix[STARTING_X_POS-2][STARTING_Y_POS] = RIGHT;
    pix[STARTING_X_POS-1][STARTING_Y_POS] = RIGHT;
    pix[STARTING_X_POS-0][STARTING_Y_POS] = -1;
    oled_drawPixel(x_treat, y_treat, WHITE);
    oled_display();
}

/*
Funkce: readButtonInput
------------------------------
Slouží k získání dat z tlačítek a nastavení směru pohybu
Definice podmínek pro správný pohyb
*/
void readButtonInput(){
    if (GPIO_read(&PIND,LEFT) == 0)
        direction = LEFT;
    else if (GPIO_read(&PIND,RIGHT) == 0)
        direction = RIGHT;
    else if (GPIO_read(&PIND,UP) == 0)
        direction = UP;
    else if (GPIO_read(&PIND,DOWN) == 0)
        direction = DOWN;

    if (((prev_dir==RIGHT) && (direction==LEFT)) || ((prev_dir==LEFT) && (direction==RIGHT)))
        direction = prev_dir;
    else if (((prev_dir==UP) && (direction==DOWN)) || ((prev_dir==DOWN) && (direction==UP)))
        direction = prev_dir;
    else
        prev_dir = direction;
}

/*
Funkce: generateNewTreat
-------------------------------------
Slouží k určení souřadnic jídla a k následnému vykreslení jídla
Souřadnice jídla se mění na základě pohybu hráče
*/
void generateNewTreat(){
    while (1){
        x_treat = (x_pos * random_var * direction) % SCREEN_HEIGHT;
        y_treat = (y_pos * random_var * direction) % SCREEN_WIDTH;
        if ((x_treat > WINDOW_MIN_X) && (y_treat > WINDOW_MIN_Y) && (x_treat < WINDOW_MAX_X) && (y_treat < WINDOW_MAX_Y)){
            if ((pix[x_treat][y_treat] == -1) && (x_treat != x_pos) && (y_treat != y_pos))                        
                break;
        }
        random_var = (random_var*2) % 1000;
    }
    oled_drawPixel(x_treat, y_treat, WHITE);
}

/*
Funkce: moveTailByOne
-------------------------------
Slouží k posunu těla hada na základě přijatých změn směru
*/
void moveTailByOne(){
    oled_drawPixel(x_tail, y_tail, BLACK);
    int temp = pix[x_tail][y_tail];
    pix[x_tail][y_tail] = -1;
    switch (temp) {
        case LEFT:
            x_tail--;
            break;
        case RIGHT:
            x_tail++;
            break;
        case UP:
            y_tail--;
            break;
        case DOWN:
            y_tail++;
            break;
    }
}
/*
Funkce: gameOver
-------------------------------
Slouží k vykreslení obrazovky při prohře
*/
void gameOver(){
        oled_clrscr();
        oled_charMode(DOUBLESIZE);
        oled_puts("GAME OVER");
        oled_charMode(NORMALSIZE);
        oled_gotoxy(0, 2);
        oled_puts("Score: " + score);
        oled_display();
}
