#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h" // biblioteca de gerenciamento de temporizadores e alarmes
#include "include/leds.h"
#include "include/button.h"



int main()
{
    stdio_init_all();

    while (true) {
        sleep_ms(50);
        OneShot();
    }
}
