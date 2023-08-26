/*
 * application.c
 *
 * Created: 8/24/2023 1:51:49 AM
 *  Author: HP
 */
#include "application.h"

int currentLed = 0;
uint8_t LED_PIN[4] = {
  PIN4,
  PIN5,
  PIN6,
  PIN7
};
uint8_t buttonState = LOW;
uint8_t ledState = LOW;
uint8_t BUTTON_PIN = BUTTON_1_PIN;

EN_appError_t APP_init(void) {
  if (LED_init(LED_1_PORT, LED_PIN[0]) != LED_OK) {
    return APP_LED_ERROR;
  } else if (LED_init(LED_1_PORT, LED_PIN[1]) != LED_OK) {
    return APP_LED_ERROR;
  } else if (LED_init(LED_1_PORT, LED_PIN[2]) != LED_OK) {
    return APP_LED_ERROR;
  } else if (LED_init(LED_1_PORT, LED_PIN[3]) != LED_OK) {
    return APP_LED_ERROR;
  } else if (BUTTON_init(BUTTON_1_PORT, BUTTON_PIN) != BTN_OK) {
    return APP_BTN_ERROR;
  } else {
    return APP_OK;
  }

}

EN_appError_t APP_start(void) {

  if (LED_read(LED_1_PORT, LED_PIN[currentLed], & ledState) != LED_OK) {
    return APP_LED_ERROR;
  }
  if (BUTTON_read(BUTTON_1_PORT, BUTTON_PIN, & buttonState) != BTN_OK) {
    return APP_BTN_ERROR;
  }

  if (buttonState == HIGH) {
    _delay_ms(300);
    if (ledState == LOW) {
     
      if (LED_on(LED_1_PORT, LED_PIN[currentLed]) != LED_OK) {

        return APP_LED_ERROR;
      } else {
        currentLed = (currentLed + 1) % 4; // Move to the next LED in a cyclic manner

        return APP_OK;

      }
    } else if (ledState == HIGH) {

      if (LED_off(LED_1_PORT, LED_PIN[currentLed]) != LED_OK) {

        return APP_LED_ERROR;
      } else {
        currentLed = (currentLed + 1) % 4; // Move to the next LED in a cyclic manner

        return APP_OK;

      }

    } else {
      return APP_ERROR_EXIT;
    }

  } else {
    return APP_ERROR_EXIT;

  }

}

void test_app(void) {

  /* initializing test cases */
  /* test case 1.. returns APP_LED_ERROR */
  LED_PIN[0] = 10;
  APP_init();

  /* test case 2.. returns APP_BTN_ERROR */
  LED_PIN[0] = PIN4;
  BUTTON_PIN = 10;
  APP_init();
  BUTTON_PIN = BUTTON_1_PIN;

  /* APP_start test cases   */
  /* test case 3.. returns APP_LED_ERROR*/
  APP_init();
  LED_PIN[0] = 10;
  APP_start();
  
  
  /* test case 4.. returns APP_BTN_ERROR*/
 LED_PIN[0] = PIN4;
 APP_init();
 BUTTON_PIN = 10;
 APP_start();
  
  /* test case 5.. returns APP_ERROR_EXIT	*/
  BUTTON_PIN = BUTTON_1_PIN;
  LED_PIN[0] = PIN4;
 APP_init();
 buttonState = 3;
 APP_start();
 
 
 /*test case 6 returns APP_OK [HAPPY Case scenario*/
 buttonState = LOW;
 APP_init();
 while(1){
 APP_start();
 }

}