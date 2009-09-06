/* File: my_led.c
 * --------------
 * 针对EasyARM1138开发板实现的my_led控制函数。
 * PD0~LED1
 * PG2~LED2
 * PG3~LED3
 */


#include <assert.h>
#include "my_led.h"

#include "hw_types.h"	// common data types of Luminary driver lib
#include "hw_memmap.h"	// using GPIO_PORTD_BASE, GPIO_PORTG_BASE
#include "sysctl.h"	// using SysCtlPeripheralEnable()
#include "gpio.h"	// using GPIOPinTypeGPIOOutput(), GPIOPinWrite()


/*
 * 函数：InitLED()
 * 注：省略了初始灭灯处理
 */
void InitLED()
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0);
	GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PIN_2 | GPIO_PIN_3);
}

/*
 * 函数：SetLED()
 * 
 */
void SetLED(int i, LED_t set)
{
	unsigned char	ucVal;// 作GPIOPinWrite()的第三个参数

	assert(1<=i && i<=3);// EasyARM1138开发板只有三只LED
	
	if (set == ON)
		ucVal = 0x00;// 低电平开灯
	else
		ucVal = 0xff;// 高电平灭灯
	
	switch (i)
	{
		case 1:	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, ucVal);
			break;
		case 2:	GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_2, ucVal);
			break;
		case 3:	GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_3, ucVal);
			break;
	}
}
