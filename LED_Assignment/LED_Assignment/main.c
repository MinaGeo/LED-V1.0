/*
 * My first project.c
 * write high on pin 0 on port A
 * Created: 8/23/2023 5:57:40 PM
 * Author : HP
 */ 

//#include <avr/io.h>
#include "../Application/application.h"

int main(void)
{
  
	//test_dio();
	//test_app();
	
	
	APP_init();
	
	while (1)
	{
		APP_start();
		
	}
}

