/*
 * @Author: Zhaojc
 * @Date: 2022-08-03 15:16:35
 * @LastEditTime: 2022-08-03 16:21:23
 * @Descripttion: 计算文件字符个数, 使用 fgetc 实现
 */

// man 3 fgetc
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fp;
    int count = 0;
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <tagert_file>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        perror("fopen()");
        exit(1);
    }
    while (fgetc(fp) != EOF)
    {
        count++;
    }
    printf("count = %d\n", count);
    fclose(fp);
    exit(0);
}