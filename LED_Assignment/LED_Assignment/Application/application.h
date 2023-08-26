/*
 * application.h
 *
 * Created: 8/24/2023 1:51:41 AM
 *  Author: HP
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
#define F_CPU 1000000UL  // 1 MH
#include <util/delay.h>
#include "../ECUAL/LED/led.h"
#include "../ECUAL/BUTTON/button.h"

typedef enum EN_appError_t{
	APP_OK, APP_LED_ERROR, APP_BTN_ERROR,APP_INT_ERROR,APP_ERROR_EXIT
}EN_appError_t;

EN_appError_t APP_init(void);
EN_appError_t APP_start(void);


void test_app(void);
#endif /* APPLICATION_H_ */