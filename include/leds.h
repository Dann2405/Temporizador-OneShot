#ifndef LEDS
#define LEDS

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

const uint LED_R = 13; // led vermelho - GPIO 13
const uint LED_B = 12; // led azul - GPIO 12
const uint LED_G = 11; // led verde - GPIO 11

bool leds_active = false; // verifica se o led esta aceso, para evitar multiplas ativações
absolute_time_t turn_off_time; // variavel para armazenar o tempo em que os LEDs devem ser desligados

// declarando funções callbacks para evitar erros "undeclared"
int64_t turn_off_callback_ledR(alarm_id_t id, void *user_data);
int64_t turn_off_callback_ledB(alarm_id_t id, void *user_data);
int64_t turn_off_callback_ledG(alarm_id_t id, void *user_data);


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

// função de callback para desligar o led vermelho após o tempo programado
int64_t turn_off_callback_ledR(alarm_id_t id, void *user_data)
{
    gpio_put(LED_R, 0);

    add_alarm_in_ms(3000, turn_off_callback_ledB, NULL, false);

    return 0;
}

// função de callback para desligar o led azul após o tempo programado
int64_t turn_off_callback_ledB(alarm_id_t id, void *user_data)
{
    gpio_put(LED_B, 0);
    add_alarm_in_ms(3000, turn_off_callback_ledG, NULL, false);
    return 0;
}

// função de callback para desligar o led verde após o tempo programado
int64_t turn_off_callback_ledG(alarm_id_t id, void *user_data)
{
    gpio_put(LED_G, 0);
    leds_active = false; // vai liberar o botão para reinicar
    return 0;
}

#endif