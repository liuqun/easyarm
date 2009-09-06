/* File: my_led.h
 * --------------
 * �ҵ�LED����ͷ�ļ��������˼���ͨ�õ�LED���ƺ�����
 * ����LED���ƶ˿ڳ�ʼ��InitLED()�ͶԸ�LED���е������Ƶ�SetLED()��
 * ���ﶨ��ĺ���ԭ�Ͳ��������ض�Ӳ���ṹ��
 * ��Ӳ���ṹ��صľ���ʵ�֣�my_led.c��������Բ�ͬӲ���ֱ������ơ�
 *
 * �������һ�������ĺ����÷�ʾ����
 *
 * 	#include "my_led.h"
 *
 * 	void delay(int time)
 * 	{
 * 		while (time>0) {--time;}
 * 	}
 *
 * 	int main()
 * 	{
 * 		InitLED();
 *
 * 		SetLED(1, ON);
 * 		delay(9999);
 * 		SetLED(1, OFF);
 *
 * 		return (0);
 * 	}
 *
 */

#ifndef MY_LED_H
#define MY_LED_H

/*
 * ������InitLED()
 * ---------------
 * ��ʼ������LED�˿�
 * �÷�ʾ����
 * 	InitLED();
 * ��������
 * ����ֵ����
 */
void InitLED(void);

/* 
 * ������SetLED()
 * --------------
 * ��/�ص�iֻLED��
 * �÷�ʾ����
 * 	SetLED(i, ON);
 * 	SetLED(i, OFF);
 *
 * ������
 * int   i	���� ��iֻLED��
 * LED_t set	���� ���ƵƵ�����
 *
 * ��������ֵ����
 *
 * �Զ����������ͣ�LED_t
 * ���ڱ�ʾLED�Ƶ�����ON����OFF��
 */
typedef enum{ON,OFF} LED_t;
void SetLED(int i, LED_t set);

#endif//MY_LED_H
