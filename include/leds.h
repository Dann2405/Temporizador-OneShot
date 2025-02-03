#include <stdio.h>
#include "pico/stdlib.h"

const uint LED_R = 13;
const uint LED_B = 12;
const uint LED_G = 11;

void init_gpio_leds()
{
    gpio_init(LED_R);
    gpio_init(LED_B);
    gpio_init(LED_G);

    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_set_dir(LED_B, GPIO_OUT);
    gpio_set_dir(LED_G, GPIO_OUT);
}