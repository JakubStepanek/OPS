/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "stm32746g_discovery_lcd.h"

// DISPLAY_TIME rate in milliseconds
#define DISPLAY_TIME 1000

Thread thread1;
Thread thread2;

void displayOnDisplay(int xPosition, int yPosition, int number) {
  BSP_LCD_DisplayStringAt(xPosition, yPosition,
                          (uint8_t *)"THIS THREAD" + number, CENTER_MODE);
}

void ourThread1() {
  displayOnDisplay(0, 50, 3);
  HAL_Delay(DISPLAY_TIME);
}

void ourThread2() {
  displayOnDisplay(0, 100, 5);
  HAL_Delay(DISPLAY_TIME);
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
  thread1.join();
  BSP_LCD_Clear(LCD_COLOR_BLACK);
  ThisThread::sleep_for(DISPLAY_TIME);

  thread2.start(ourThread2);
  thread2.join();
  BSP_LCD_Clear(LCD_COLOR_BLACK);
  ThisThread::sleep_for(DISPLAY_TIME * 2);

  while (true) {
  }
}
