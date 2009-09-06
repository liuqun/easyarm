// UARTͨѶʵ��(Hello world)

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
	char	msg_Chinese[100]="��ã�\r\n";
	
	// ��ʼ��
	Init();
	
	// ����������Ϣ�ַ���
	SendMsg(msg_English);
	SendMsg(msg_Chinese);
	
	// �رո��豸
	UARTDisable(UART2_BASE);
	SysCtlPeripheralDisable(SYSCTL_PERIPH_UART2);
	SysCtlPeripheralDisable(SYSCTL_PERIPH_GPIOG);
}


// �Ӻ���: Init()
// ͨѶ�˿ڳ�ʼ��
// ע������ʹ���������Ƽ����º���UARTConfigSetExpClk()��
//     ��׺ExpClk��ָ��with explicitly provided peripheral clock��
void Init()
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
	GPIOPinTypeUART(GPIO_PORTG_BASE, GPIO_PIN_0 | GPIO_PIN_1);//ע��PG0~U2Rx
								  //    PG1~U2Tx
	UARTConfigSetExpClk(
		UART2_BASE,
		SysCtlClockGet(),
		9600,			//������
		UART_CONFIG_WLEN_8 |	//����λ����
		UART_CONFIG_STOP_ONE |	//ֹͣλ
		UART_CONFIG_PAR_NONE);	//��żУ��
	UARTEnable(UART2_BASE);
}


// �Ӻ���: SendMsg()
// ͨ��UART������Ϣ�ַ���
void SendMsg(char *msg)
{
	while (*msg!='\0')
	{
		UARTCharPut(UART2_BASE, *msg);
		++msg;
	}
}

