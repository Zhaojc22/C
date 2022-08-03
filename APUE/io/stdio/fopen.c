/*
 * @Author: Zhaojc
 * @Date: 2022-08-03 14:05:16
 * @LastEditTime: 2022-08-03 15:26:41
 * @Descripttion: 打开文件，关闭文件，报错函数（errno的相关处理）
 */

// man 3 fopen
// man 3 fclose
// man 3 perror
// man 3 strerror

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// perror(); 是包含在 stdio.h 中的函数,它能够将 errno 转化为error msg输出
// strerror(int errno); 是包含在 string.h 中的函数，将 errno 转化为 error msg

int main()
{
    FILE *fp;
    fp = fopen("tmp", "r");
    // fopen函数的返回值的指针是在堆上的
    if (fp == NULL)
    {
        // fprintf(stderr, "fopen() failed! errno = %d\n", errno);
        // perror("fopen()");
        fprintf(stderr, "fopen(): %s\n", strerror(errno));
        exit(1);
    }
    puts("OK!");
    fclose(fp);
    exit(0);
}