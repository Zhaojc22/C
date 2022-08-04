/*
 * @Author: Zhaojc
 * @Date: 2022-08-04 10:24:39
 * @LastEditTime: 2022-08-04 11:20:19
 * @Descripttion: 系统IO实现 mycopy
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

#define BUFFSIZE 1024

int main(int argc, char **argv)
{
    int sfd, dfd;
    char buf[BUFFSIZE];
    int len;
    int ret;
    int pos = 0;
    if (argc < 3)
    {
        fprintf(stderr, "Usag: %s <src> <dest>\n", argv[0]);
        exit(1);
    }

    sfd = open(argv[1], O_RDONLY);
    if (sfd < 0)
    {
        perror("Open():");
        exit(1);
    }
    dfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (dfd < 0)
    {
        close(sfd);
        perror("Open():");
        exit(1);
    }

    while (1)
    {
        len = read(sfd, buf, BUFFSIZE);
        if (len < 0)
        {
            perror("read():");
            break;
        }

        if (len == 0)
            break;

        pos = 0;
        while (len > 0)
        {

            ret = write(dfd, buf + pos, len);
            if (ret < 0)
            {
                perror("write()");
                exit(1);
            }
            pos += ret;
            len -= ret;
        }
    }

    close(dfd);
    close(sfd);

    exit(0);
}