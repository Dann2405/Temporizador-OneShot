#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

const uint BUTTON = 5; // configurado para ser o botão A da placa BitDogLAb

// função de inicialização do botão
void init_gpio_button()
{
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
}