/**
  ******************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2018-xx-xx
  * @brief   GPIO输出--使用固件库点亮LED灯
  ******************************************************************
  * @attention
  *
  * 实验平台:野火 STM32H743开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************
  */  
#include "board.h"
#include "main.h"
#include "rtthread.h"

/* 定义线程控制块 */
static struct rt_thread led1_thread;

/* 定义线程控栈时要求RT_ALIGN_SIZE个字节对齐 */
ALIGN(RT_ALIGN_SIZE)
/* 定义线程栈 */
static rt_uint8_t rt_led1_thread_stack[1024];

static void led1_thread_entry(void* parameter);


/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
	
	rt_thread_init(&led1_thread,                 /* 线程控制块 */
                   "led1",                       /* 线程名字 */
                   led1_thread_entry,            /* 线程入口函数 */
                   RT_NULL,                      /* 线程入口函数参数 */
                   &rt_led1_thread_stack[0],     /* 线程栈起始地址 */
                   sizeof(rt_led1_thread_stack), /* 线程栈大小 */
                   3,                            /* 线程的优先级 */
                   20);                          /* 线程时间片 */
    rt_thread_startup(&led1_thread);             /* 启动线程，开启调度 */
	
	
//	/* 控制LED灯 */
//	while (1)
//	{
//		LED1( ON );			 // 亮 
//		HAL_Delay(100);
//		LED1( OFF );		  // 灭
//		HAL_Delay(100);

//		LED2( ON );			// 亮 
//		HAL_Delay(100);
//		LED2( OFF );		  // 灭
//		HAL_Delay(100);
//	}
}

static void led1_thread_entry(void* parameter)
{	
    while (1)
    {
        LED1_ON;
        rt_thread_delay(500);   /* 延时500个tick */
        
        LED1_OFF;     
        rt_thread_delay(500);   /* 延时500个tick */		 		

    }
}

