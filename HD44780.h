/*
 * HD44780.h
 *
 *  Created on: 2 февр. 2018 г.
 *      Author: ellissar
 *
 *      Для начала работы необходимо:
 *      1. Переопределить используемые порты и выводы микроконтроллера в этом файле на свои
 *         (LCD_RS_PIN, LCD_E_PIN, LCD_DB4_PIN, LCD_DB5_PIN, LCD_DB6_PIN, LCD_DB7_PIN, LCD_GPIO_PORT1, LCD_GPIO_PORT2).
 *      2. Если тактирование портов не включено, то в функции LCD_InitPin() раскомментировать первые две строки и
 *         следовать комментарию написанному там.
 *      3. Однократно вызвать функцию LCD_Init () для подготовки дисплея к приёму данных.
 *      4. Можно пользоваться.
 */

#ifndef HD44780_H_
#define HD44780_H_

#include "stm32f3xx_hal.h"

//Изменить следующие 9 define на свои если необходимо
#define LCD_RS_PIN			GPIO_PIN_10	//PA10
#define LCD_E_PIN			GPIO_PIN_8	//PA8
#define LCD_DB4_PIN			GPIO_PIN_6	//PC6
#define LCD_DB5_PIN			GPIO_PIN_7	//PC7
#define LCD_DB6_PIN			GPIO_PIN_8	//PC8
#define LCD_DB7_PIN			GPIO_PIN_9	//PC9
#define LCD_GPIO_PORT1		GPIOA
#define LCD_GPIO_PORT2		GPIOC


#define RS_1	LCD_GPIO_PORT1->BSRR = (uint32_t)LCD_RS_PIN
#define RS_0	LCD_GPIO_PORT1->BRR = (uint32_t)LCD_RS_PIN

#define E_1		LCD_GPIO_PORT1->BSRR = (uint32_t)LCD_E_PIN
#define E_0		LCD_GPIO_PORT1->BRR = (uint32_t)LCD_E_PIN

#define DB4_1	LCD_GPIO_PORT2->BSRR = (uint32_t)LCD_DB4_PIN
#define DB4_0	LCD_GPIO_PORT2->BRR = (uint32_t)LCD_DB4_PIN

#define DB5_1	LCD_GPIO_PORT2->BSRR = (uint32_t)LCD_DB5_PIN
#define DB5_0	LCD_GPIO_PORT2->BRR = (uint32_t)LCD_DB5_PIN

#define DB6_1	LCD_GPIO_PORT2->BSRR = (uint32_t)LCD_DB6_PIN
#define DB6_0	LCD_GPIO_PORT2->BRR = (uint32_t)LCD_DB6_PIN

#define DB7_1	LCD_GPIO_PORT2->BSRR = (uint32_t)LCD_DB7_PIN
#define DB7_0	LCD_GPIO_PORT2->BRR = (uint32_t)LCD_DB7_PIN


//Отправить инструкцию дислпею
void LCD_Send_Command (uint8_t command);

//Отправить один символ на дисплей
void LCD_Send_Char (uint8_t data);

//Отправить строку на дисплей
void LCD_Send_String (uint8_t *str, uint8_t size);

//Установить курсор в указанную позицию
void LCD_Set_Cursor (uint8_t row, uint8_t col);

//Очистить экран
void LCD_Clear (void);

//Инициализациия дисплея
void LCD_Init (void);


#endif /* HD44780_H_ */
