/*
 * @Author: Zhaojc
 * @Date: 2022-08-04 11:17:29
 * @LastEditTime: 2022-08-04 13:07:15
 * @Descripttion: 查看 标准IO 和 文件IO 混用时的混乱情况
 */
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

// $ strace ./ab 
// ....
// write(1, "b", 1b)                        = 1
// write(1, "b", 1b)                        = 1
// write(1, "b", 1b)                        = 1
// write(1, "aaa", 3aaa)                      = 3
// exit_group(0)                           = ?
// 程序同过strace 命令跟踪过程 可以看到是根据程序处理了所有 文件IO 然后一次性 标准IO 写入缓冲区中的内容通过调用一次 文件IO 输出

int main()
{
    putchar('a');
    write(1, "b", 1);

    putchar('a');
    write(1, "b", 1);

    putchar('a');
    write(1, "b", 1);
    exit(0);
}
