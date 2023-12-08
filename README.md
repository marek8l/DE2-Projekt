# DE2- Projekt Snake game

### Členové týmu

* Marek IVAN
* Petr KAPLAN
* Miroslav TRCHALÍK
* Dominik EIS

## Theoretical description and explanation
![alt text](celek.jpg)
Cílem naší práce bylo vytvořit zabávnou arkádovou hru Had. K tomu je zapotřebí využití Arduino Uno board, které obsahuje námi napsaný kód, jenž obsahu řešení problémů k úspěšné funkčnosti hada. Dále potřebujeme OLED display 128x64, na kterém se tato minihra vykresluje a nakonec máme sadu čtyř tlačítek, která určuje směr pohybu hada. Namísto 4 tlačítek jsme měli v plánu vytvořit vlastní desku s tlačítky a joystickem. Ve finále jsme využili Joystick Shield Gamepad pro Arduino, které vyřešilo naši potřebu pro tvorbu vlastní desky. První problém, který jsme řešili bylo ,jak vykresli hada? Inspirovali jsme se řešením ze šestého cvičení z laboratoří. Za chvíli se nám podařilo vykreslit hada a arénu,v níž se odehrává hra. Poté bylo zapotřebí vyzkoušet funkčnost tlačítek, opět jsme se inspirovali cvičením tentokrát pátým, kde jsme kontrolovali funkčnost tlačítek pomocí UART. Za třetí následoval problém s vykreslením ovoce, které chce had zkonzumovat pro jeho růst a navýšení skóre. A tak vzniklo magické číslo, kterým se násobí číslem portu, podle stiknutého tlačítka pro pohyb. Funkce náhodně vygeneruje souřadnice X a Y, tyto souřadnice odpovídají pozici ovoce v herní ploše. Také jsme vyřešili, aby nenastalo, že se ovoce objeví mimo herní plochu. Největší problém spočíval v časovači. Ten s námi nechtěl spolupracovat, ale nakonec se nám jej povedlo do určité míry zprovoznit.Pohyb hada jsme vyřešili, pomocí pole, kde jsou nastaveny -1, pokud se v tomto pixelu nenachází nějaká část hada, naopak pixel bude mít hodnotu 1 , pokud se zde had nachází. Dále jsme řešili problémy, jako například, aby změna pohybu hada mohla být, pouze ta,kde by nenastalo, že had se otočí sám do sebe. A nakonec podmínky, kdy nastane "Game Over". To se stane v případě, když had narazí do svého ocasu nebo do zdi arény. Po smrti hada vyskočí obrazovka oznamující konec hry a skóre hráče.

## Hardware description of demo application

Insert descriptive text and schematic(s) of your implementation.

## Software description

Put flowchats of your algorithm(s) and direct links to source files in `src` or `lib` folders.

## Instructions

Write an instruction manual for your application, including photos and a link to a short app video.

## References

1. (https://www.neon-el.cz/joystick-shield-gamepad-pro-arduino)https://www.neon-el.cz/joystick-shield-gamepad-pro-arduino
2. https://www.youtube.com/watch?v=O22KN90N-gE
3. https://github.com/tomas-fryza/digital-electronics-2/tree/master
4. https://stackoverflow.com/
   
