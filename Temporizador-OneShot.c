#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h" // biblioteca de gerenciamento de temporizadores e alarmes
#include "include/leds.h"



int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
