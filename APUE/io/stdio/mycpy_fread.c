/*
 * @Author: Zhaojc
 * @Date: 2022-08-03 15:07:49
 * @LastEditTime: 2022-08-03 15:49:48
 * @Descripttion: 复制源文件到目标文件，类似于 cp,使用 fgets 实现
 */

#include <stdio.h>
#include <stdlib.h>
#define BUFFSIZE 1024
int main(int argc, char **argv)
{
    FILE *fps, *fpd;
    int n;
    char buff[BUFFSIZE];
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <src_file> <dest_file>\n", argv[0]);
        exit(1);
    }
    fps = fopen(argv[1], "r");
    if (fps == NULL)
    {
        fclose(fps);
        perror("fopen()");
        exit(1);
    }

    fpd = fopen(argv[2], "w");
    if (fpd == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    while ((n = fread(buff, 1, BUFFSIZE, fps)) > 0)
        fwrite(buff, 1, n, fpd);


    fclose(fpd);
    fclose(fps);
    exit(0);
}