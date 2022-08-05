/*
 * @Author: Zhaojc
 * @Date: 2022-08-05 13:43:33
 * @LastEditTime: 2022-08-05 13:48:02
 * @Descripttion: getpwuid() 和 getpwnam() 测试， 当前实现的是通过命令行输入的user id 查看用户名
 * 如： ./username 0  输出的是 root 
 *      ./username 1 输出 daemon
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
