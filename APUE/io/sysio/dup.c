/*
 * @Author: Zhaojc
 * @Date: 2022-08-04 13:32:46
 * @LastEditTime: 2022-08-04 14:15:32
 * @Descripttion: 测试 dup() 函数， 将给定的文件描述符放到当前文件描述符数组最小的起始地址
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FNAME "/tmp/out"

int main()
{

    int fd;

    // close(1);

    fd = open(FNAME, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd < 0)
    {
        perror("open()");
        exit(1);
    }

#if 0
    // 已经把文件打开了然后再关闭stdout 这是数组中最小能使用的下表是1
    close(1);
    // 将前面的 fd 移动到 1
    dup(fd);
    // 因为上面两块的操作加到一起不是原子操作，所以可能在多线程或者多任务中出错，因为当你关闭之后，可能在间隙有人使用1
#endif

    dup2(fd, 1); // dup2是原子操作，这就避免了上面出现的问题，但下面的关闭文件要判断一下，因为如果你原来的fd就是1那么这句话啥都不做，下面释放了就写不进去了


    // 这是 fd 对应的文件已经有了 文件描述符1 可以找到它 所以将原来的 fd 关闭
    if(fd != 1)
        close(fd);

    // 下面代码不变
    puts("hello!");

    // 模块化编程要记得还原环境， 将1还给系统输出

    exit(0);
}