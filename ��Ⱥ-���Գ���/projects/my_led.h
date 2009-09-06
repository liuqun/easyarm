/* File: my_led.h
 * --------------
 * 我的LED函数头文件，定义了简单且通用的LED控制函数，
 * 包括LED控制端口初始化InitLED()和对各LED进行单独控制的SetLED()。
 * 这里定义的函数原型不依赖于特定硬件结构。
 * 与硬件结构相关的具体实现（my_led.c）可以针对不同硬件分别进行设计。
 *
 * 这里给出一个完整的函数用法示例：
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
 * 函数：InitLED()
 * ---------------
 * 初始化所有LED端口
 * 用法示例：
 * 	InitLED();
 * 参数：无
 * 返回值：无
 */
void InitLED(void);

/* 
 * 函数：SetLED()
 * --------------
 * 开/关第i只LED灯
 * 用法示例：
 * 	SetLED(i, ON);
 * 	SetLED(i, OFF);
 *
 * 参数：
 * int   i	—— 第i只LED灯
 * LED_t set	—— 控制灯的亮灭
 *
 * 函数返回值：无
 *
 * 自定义数据类型：LED_t
 * 用于表示LED灯的亮灭（ON亮，OFF灭）
 */
typedef enum{ON,OFF} LED_t;
void SetLED(int i, LED_t set);

#endif//MY_LED_H
