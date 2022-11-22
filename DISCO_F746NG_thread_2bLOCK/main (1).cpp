/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "stm32746g_discovery_lcd.h"
#include "setting.h"
Mutex stdio_mutex;

Thread thread1;
Thread thread2;
Thread thread3;

void displayOnDisplay(int xPosition, int yPosition, int number) {
    stdio_mutex.lock();
  BSP_LCD_DisplayStringAt(xPosition, yPosition,
                          (uint8_t *)"THIS THREAD" + number, CENTER_MODE);
  ThisThread::sleep_for(THREAD_DURATION);
  BSP_LCD_Clear(LCD_COLOR_BLACK);
  stdio_mutex.unlock();
}

void ourThread1() {
  while (true) {
    displayOnDisplay(0, 50, 5);
  }
}

void ourThread2() {
  while (true) {
    displayOnDisplay(0, 100, 1);
  }
}

void ourThread3() {
  while (true) {
    displayOnDisplay(0, 150, 7);
  }
}
int main() {
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
  while (true) {
  }
}
