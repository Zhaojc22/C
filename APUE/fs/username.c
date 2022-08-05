/*
 * @Author: Zhaojc
 * @Date: 2022-08-05 13:43:33
 * @LastEditTime: 2022-08-05 13:48:02
 * @Descripttion: getpwuid() 和 getpwnam() 测试
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
int main(int argc, char const **argv)
{
    struct passwd *user;
    if (argc < 2)
    {
        fprintf(stderr, "Usage ...\n");
        exit(1);
    }
    user = getpwuid(atoi(argv[1]));
    puts(user->pw_name);
    exit(0);
}
