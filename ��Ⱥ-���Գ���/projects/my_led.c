/* File: my_led.c
 * --------------
 * ���EasyARM1138������ʵ�ֵ�my_led���ƺ�����
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
 * ������InitLED()
 * ע��ʡ���˳�ʼ��ƴ���
 */
void InitLED()
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0);
	GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PIN_2 | GPIO_PIN_3);
}

/*
 * ������SetLED()
 * 
 */
void SetLED(int i, LED_t set)
{
	unsigned char	ucVal;// ��GPIOPinWrite()�ĵ���������

	assert(1<=i && i<=3);// EasyARM1138������ֻ����ֻLED
	
	if (set == ON)
		ucVal = 0x00;// �͵�ƽ����
	else
		ucVal = 0xff;// �ߵ�ƽ���
	
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
