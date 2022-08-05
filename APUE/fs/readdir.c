/*
 * @Author: Zhaojc
 * @Date: 2022-08-05 09:23:40
 * @LastEditTime: 2022-08-05 09:30:05
 * @Descripttion: 把目标目录当做一个目录流来解析
 */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#define PAT "/etc"

int main()
{
    DIR *dp;
    struct dirent *cur;
    dp = opendir(PAT);
    if (dp == NULL)
    {
        perror("opendir()");
        exit(1);
    }

    while ((cur = readdir(dp)) != NULL)
        puts(cur->d_name);
        
    closedir(dp);
    exit(0);
}