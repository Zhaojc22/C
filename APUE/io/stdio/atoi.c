/*
 * @Author: Zhaojc
 * @Date: 2022-08-03 16:01:43
 * @LastEditTime: 2022-08-03 16:14:15
 * @Descripttion: atoi函数测试，将字符串转为整形数
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{

    // char str[] = "123456";
    // printf("%d\n", atoi(str));
    char buf[1024];
    int year = 2022, month = 8, day = 3;
    sprintf(buf, "%d-%d-%d", year, month, day);
    puts(buf);
    exit(0);
}