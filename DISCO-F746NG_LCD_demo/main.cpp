	

#include "mbed.h"
#include "stm32746g_discovery_lcd.h"
 
 const int pause = 5000;
int main()
{
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
 
    while (1) {
        BSP_LCD_Clear(LCD_COLOR_BLACK);
        BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
        BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
        BSP_LCD_SetTextColor(LCD_COLOR_MAGENTA);
 
        BSP_LCD_DisplayStringAt(0, 50, (uint8_t *)"LUCINKA", CENTER_MODE);

 
        BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
        BSP_LCD_SetTextColor(LCD_COLOR_ORANGE);
        BSP_LCD_DisplayStringAt(0, 150, (uint8_t *)"JAKoUBek", CENTER_MODE);


        BSP_LCD_SetTextColor(LCD_COLOR_CYAN);
        BSP_LCD_DrawEllipse(240, 115, 150, 100);
 
        HAL_Delay(pause);
    }
}