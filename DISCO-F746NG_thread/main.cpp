#include "mbed.h"
#include "stm32746g_discovery_lcd.h"
#include <iostream>
#include  <random>
#include "./setting.h"

Thread thread1;
Thread thread2;
Thread thread3;

void ourThread1(){          
    while(true){  
            BSP_LCD_DisplayStringAt(0, 1, (uint8_t *)"thread1", CENTER_MODE);
            ThisThread::sleep_for(THREAD_DURATION);
            BSP_LCD_Clear(LCD_COLOR_BLACK);
    }
}

void ourThread2(){  
    while(true){      
            BSP_LCD_DisplayStringAt(0, 50, (uint8_t *)"thread2", CENTER_MODE);
            ThisThread::sleep_for(THREAD_DURATION);
            BSP_LCD_Clear(LCD_COLOR_BLACK);
    }
}

void ourThread3(){      
    while(true){            
            BSP_LCD_DisplayStringAt(0, 100, (uint8_t *)"thread3", CENTER_MODE);
            ThisThread::sleep_for(THREAD_DURATION);
            BSP_LCD_Clear(LCD_COLOR_BLACK);
    }
}
int main()
{
    //std::cout << std::rand()% 5000 + 1500;
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
     
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
    BSP_LCD_SetTextColor(LCD_COLOR_MAGENTA);
  

     
    thread1.start(ourThread1);
    thread2.start(ourThread2);
    thread3.start(ourThread3);
    while(true){}
}
