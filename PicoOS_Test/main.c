/*
 * PicoOS_Test.c
 *
 * Created: 29.04.2024 21:07:19
 * Author : Jack
 */ 

#include <avr/io.h>
#include <stdint.h>
#include "picoos.h"
#include "printf.h"
#include "usart0.h"


static void initialTask(void* arg);
static void ledTask(void *arg);
static void consoleTask(void *arg);

/* the initial values for the LED task */
static uint8_t t1 = (1 << PORTB5);

/* The start task for the initialization of the 2 other tasks.
 * This task will be destroyed, when the program runs out of the
 * block
 */
static void initialTask(void *arg) {
    posTaskCreate(ledTask, &t1, 1);
    posTaskCreate(consoleTask, NULL, 1);
}


static void ledTask(void *arg) {
    uint8_t *valuePtr = (uint8_t*) arg;
    uint8_t value = *valuePtr;
    DDRB = 1 << PORTB5;

    while(1) {
        PORTB ^= value;
        posTaskSleep(MS(500));
    }
}

static void consoleTask(void *arg) {
    usart0_init();
    init_printf(NULL, usart0_char);

    while(1) {
        printf("Hi\n");
        posTaskSleep(MS(1000));
    }
}

int main(void)
{   
    posInit(initialTask, NULL, 1);

    return 0;
}

