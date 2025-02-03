#include "include/leds.h"

const uint BUTTON = 5; // configurado para ser o botão A da placa BitDogLAb
absolute_time_t last_press_time;
#define DEBOUNCE_TIME_MS 50

// função de inicialização do botão
void init_gpio_button()
{
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
}

// função OneShot para que os LEDs sejam desligando sequencialmente
void OneShot()
{
    if(gpio_get(BUTTON) == 0 && !leds_active)
    {
        absolute_time_t current_time = get_absolute_time();
        int64_t tempo_decorrido = absolute_time_diff_us(last_press_time, current_time) / 1000;

        if(tempo_decorrido >= DEBOUNCE_TIME_MS)
        {
        last_press_time = current_time;
        leds_active = true;
        gpio_put(LED_R, 1);
        gpio_put(LED_B, 1);
        gpio_put(LED_G, 1);
        add_alarm_in_ms(3000, turn_off_callback_ledR, NULL, false);
        printf("Botão pressionado, OneShot Iniciado\n");
        }
    }
}