/*
 * @Author: Zhaojc
 * @Date: 2022-08-05 14:12:30
 * @LastEditTime: 2022-08-05 14:31:14
 * @Descripttion: 检查输入的用户密码是否正确，用户由命令行输入;如 ./chkpass zhaoja
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <shadow.h>
#include <crypt.h>

int main(int argc, char **argv)
{
    char *input_pass;
    char *crypted_pass;
    struct spwd *shadow_line;
    if (argc < 2)
    {
        fprintf(stderr, "Usage ... \n");
        exit(1);
    }

    input_pass = getpass("Passwd:");

    shadow_line = getspnam(argv[1]);

    crypted_pass = crypt(input_pass, shadow_line->sp_pwdp);

    if (strcmp(shadow_line->sp_pwdp, crypted_pass) == 0)
    {
        puts("Success!");
    }
    else
    {
        puts("failed!");
    }

    exit(0);
}