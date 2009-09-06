// LED测试

#include "my_led.h"

void Delay(void);

main()
{
	// 初始化LED
	InitLED();
	
	// 灭灯
	SetLED(1, OFF);
	SetLED(2, OFF);
	SetLED(3, OFF);

	// LED循环点灯
	for (int i=0; i<50; i++)
	{
		SetLED(1, ON);
		Delay();
		SetLED(1, OFF);
		
		SetLED(2, ON);
		Delay();
		SetLED(2, OFF);
		
		SetLED(3, ON);
		Delay();
		SetLED(3, OFF);
	}
}

void Delay(void)
{
	int	n = 999999;
	while (n>0)
	{	--n;
	}
}
