/*
 * @Author: Zhaojc
 * @Date: 2022-08-03 14:40:48
 * @LastEditTime: 2022-08-03 15:26:33
 * @Descripttion: 获得当前状态下可以打开文件的最大数
 */

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

// 在不改变环境变量的情况下，一个进程默认打开三个流（stream-> stdin、stdout、stderr)
// 使用 ulimit -a 可以查看当前环境下的一些限制;如下，其中openfiles 最大是1024， 又因为已经打开了上面三个，所以结果是1021
// $ ulimit -a
// core file size          (blocks, -c) 0
// data seg size           (kbytes, -d) unlimited
// scheduling priority             (-e) 0
// file size               (blocks, -f) unlimited
// pending signals                 (-i) 7496
// max locked memory       (kbytes, -l) 65536
// max memory size         (kbytes, -m) unlimited
// open files                      (-n) 1024
// pipe size            (512 bytes, -p) 8
// POSIX message queues     (bytes, -q) 819200
// real-time priority              (-r) 0
// stack size              (kbytes, -s) 8192
// cpu time               (seconds, -t) unlimited
// max user processes              (-u) 7496
// virtual memory          (kbytes, -v) unlimited
// file locks                      (-x) unlimited

int main()
{
    int count = 0;
    FILE *fp = NULL;

    while (1)
    {
        fp = fopen("fopen.c", "r");
        if (fp == NULL)
        {
            perror("fopen()");
            break;
        }
        count++;
    }
    printf("count = %d\n", count);
    exit(0);
}