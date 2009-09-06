// UART通讯实验(Hello world)

#include "hw_types.h"
#include "hw_memmap.h"
#include "sysctl.h"
#include "gpio.h"
#include "uart.h"


void Init();
void SendMsg();


void main()
{
	char	msg_English[100]="Hello world!\r\n";
	char	msg_Chinese[100]="你好！\r\n";
	
	// 初始化
	Init();
	
	// 发送若干消息字符串
	SendMsg(msg_English);
	SendMsg(msg_Chinese);
	
	// 关闭各设备
	UARTDisable(UART2_BASE);
	SysCtlPeripheralDisable(SYSCTL_PERIPH_UART2);
	SysCtlPeripheralDisable(SYSCTL_PERIPH_GPIOG);
}


// 子函数: Init()
// 通讯端口初始化
// 注：这里使用驱动库推荐的新函数UARTConfigSetExpClk()。
//     后缀ExpClk是指“with explicitly provided peripheral clock”
void Init()
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
	GPIOPinTypeUART(GPIO_PORTG_BASE, GPIO_PIN_0 | GPIO_PIN_1);//注：PG0~U2Rx
								  //    PG1~U2Tx
	UARTConfigSetExpClk(
		UART2_BASE,
		SysCtlClockGet(),
		9600,			//波特率
		UART_CONFIG_WLEN_8 |	//数据位长度
		UART_CONFIG_STOP_ONE |	//停止位
		UART_CONFIG_PAR_NONE);	//奇偶校验
	UARTEnable(UART2_BASE);
}


// 子函数: SendMsg()
// 通过UART发送消息字符串
void SendMsg(char *msg)
{
	while (*msg!='\0')
	{
		UARTCharPut(UART2_BASE, *msg);
		++msg;
	}
}

