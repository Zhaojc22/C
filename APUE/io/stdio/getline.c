/*
 * @Author: Zhaojc
 * @Date: 2022-08-03 17:08:30
 * @LastEditTime: 2022-08-03 17:25:59
 * @Descripttion: getline获取一行内容
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fp;
    char *linebuf = NULL;
    size_t linesize = 0;
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <tagert_file>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        perror("fopem():");
        exit(1);
    }

    while (1)
    {
        if (getline(&linebuf, &linesize, fp) < 0)
            break;
        printf("%ld\n", strlen(linebuf));
        printf("%ld\n", linesize);
    }
    exit(0);
}