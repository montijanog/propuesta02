/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */
 // Ejercicio propuesto:
 //3) Hacer que un led parpadee cada segundo.
// 4) Hacer que un led parpadee cada segundo y un segundo led, parpadee cada 3segundos.

#include "mbed.h"

#define WAIT_TIME_MS 500 

// Definimos  las variables ouutput y los timers
DigitalOut led1(D2);
DigitalOut led2(D7);

Timer  timer_1; //timer para el led1
Timer timer_2; // timer para el led2



int main()
{
    //Inicialmente los leds apagados y se acctivan los  timer
    led1=0;
    led2=0;
    timer_1.start();
    timer_2.start();

    while (true)
    {
        // Parpadeo led 1 cada 1 segundo
        if(timer_1.read()>1.0f){

            led1 = !led1; //Led1 cambia de estado:  emncendido => apagado o viceversa 
            timer_1.reset(); //reseteo timer para que vuelva a iniciarlo desde 0
        }

        // Parpadeo led2 cada 3 segundos
        if (timer_2.read()>3.0f){
            
            led2 = !led2; //Led2 cambia de estado:  emncendido => apagado o viceversa 
            timer_2.reset(); //reseteo timer para que vuelva a iniciarlo desde 0
        
        
        thread_sleep_for(WAIT_TIME_MS);
    }
}