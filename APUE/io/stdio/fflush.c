/*
 * @Author: Zhaojc
 * @Date: 2022-08-03 16:32:26
 * @LastEditTime: 2022-08-03 16:39:28
 * @Descripttion: 缓冲区
 */
#include<stdio.h>
#include<stdlib.h>

/**
 * 缓冲区的作用：大多数情况下是好事，合并系统调用
 * 
 * 行缓冲：换行的时候刷新缓冲区、满了的时候刷新，强制刷新（标准输出是这样的，因为是终端设备）
 * 
 * 全缓冲：满了的时候刷新，强制刷新（默认，只要不是中断设备）
 * 
 * 无缓冲：如stderr，需要立即输出的内容
 * 
 */
int main()
{
    printf("%d", __LINE__);
    fflush(stdout);

    while(1);

    printf("%d", __LINE__);
    fflush(NULL);

    exit(0);
}