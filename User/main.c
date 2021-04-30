/**
  ******************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2018-xx-xx
  * @brief   GPIO���--ʹ�ù̼������LED��
  ******************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� STM32H743������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************
  */  
#include "board.h"
#include "main.h"
#include "rtthread.h"

/* �����߳̿��ƿ� */
static struct rt_thread led1_thread;

/* �����߳̿�ջʱҪ��RT_ALIGN_SIZE���ֽڶ��� */
ALIGN(RT_ALIGN_SIZE)
/* �����߳�ջ */
static rt_uint8_t rt_led1_thread_stack[1024];

static void led1_thread_entry(void* parameter);


/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
	
	rt_thread_init(&led1_thread,                 /* �߳̿��ƿ� */
                   "led1",                       /* �߳����� */
                   led1_thread_entry,            /* �߳���ں��� */
                   RT_NULL,                      /* �߳���ں������� */
                   &rt_led1_thread_stack[0],     /* �߳�ջ��ʼ��ַ */
                   sizeof(rt_led1_thread_stack), /* �߳�ջ��С */
                   3,                            /* �̵߳����ȼ� */
                   20);                          /* �߳�ʱ��Ƭ */
    rt_thread_startup(&led1_thread);             /* �����̣߳��������� */
	
	
//	/* ����LED�� */
//	while (1)
//	{
//		LED1( ON );			 // �� 
//		HAL_Delay(100);
//		LED1( OFF );		  // ��
//		HAL_Delay(100);

//		LED2( ON );			// �� 
//		HAL_Delay(100);
//		LED2( OFF );		  // ��
//		HAL_Delay(100);
//	}
}

static void led1_thread_entry(void* parameter)
{	
    while (1)
    {
        LED1_ON;
        rt_thread_delay(500);   /* ��ʱ500��tick */
        
        LED1_OFF;     
        rt_thread_delay(500);   /* ��ʱ500��tick */		 		

    }
}

