#include "include/leds.h"

const uint BUTTON = 5; // configurado para ser o botão A da placa BitDogLAb

// função de inicialização do botão
void init_gpio_button()
{
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
}

void OneShot()
{
    if(gpio_get(BUTTON) == 0 && !leds_active)
    {
        leds_active = true;
        gpio_put(LED_R, 1);
        gpio_put(LED_B, 1);
        gpio_put(LED_G, 1);
        add_alarm_in_ms(3000, turn_off_callback_ledR, NULL, false);
    }
}