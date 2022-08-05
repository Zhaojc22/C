/*
 * @Author: Zhaojc
 * @Date: 2022-08-04 17:24:09
 * @LastEditTime: 2022-08-05 09:20:57
 * @Descripttion: glob函数 解析模式/通配符
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glob.h>

// #define PAT "/etc/a*.conf"
#define PAT "/etc/*"

#if 0
static int errfunc__(const char *errpath, int errno)
{
    puts(errpath);
    fprintf(stderr, "Error Msg: %s\n", strerror(errno));
    return 0;
}
#endif
    
int main()
{
    glob_t globres;
    int ret;
    int i;
    ret = glob(PAT, 0, NULL, &globres);
    if (ret)
    {
        printf("Error code = %d\n", ret);
        exit(1);
    }
    for (i = 0; i < globres.gl_pathc; i++)
        puts(globres.gl_pathv[i]);

    globfree(&globres);

    exit(0);
}