#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

const uint LED_R = 13; // led vermelho - GPIO 13
const uint LED_B = 12; // led azul - GPIO 12
const uint LED_G = 11; // led verde - GPIO 11

bool led_active = false; // verifica se o led esta aceso, para evitar multiplas ativações
absolute_time_t turn_off_time; // variavel para armazenar o tempo em que os LEDs devem ser desligados

// função de inicialização dos leds
void init_gpio_leds()
{
    gpio_init(LED_R); // inicializa o led
    gpio_init(LED_B); // inicializa o led
    gpio_init(LED_G); // inicializa o led

    gpio_set_dir(LED_R, GPIO_OUT); // define o led como saida
    gpio_set_dir(LED_B, GPIO_OUT); // define o led como saida
    gpio_set_dir(LED_G, GPIO_OUT); // define o led como saida
}

