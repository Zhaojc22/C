/*
 * @Author: Zhaojc
 * @Date: 2022-08-04 17:24:09
 * @LastEditTime: 2022-08-05 09:20:57
 * @Descripttion: glob函数 解析模式/通配符
 * 
 */
#if 0
NAME
       glob, globfree - find pathnames matching a pattern, free memory from glob()

SYNOPSIS
       #include <glob.h>

       int glob(const char *pattern, int flags,
                int (*errfunc) (const char *epath, int eerrno),
                glob_t *pglob);
       void globfree(glob_t *pglob);

        typedef struct {
               size_t   gl_pathc;    /* Count of paths matched so far  */
               char   **gl_pathv;    /* List of matched pathnames.  */
               size_t   gl_offs;     /* Slots to reserve in gl_pathv.  */
           } glob_t;
...
RETURN VALUE
       On successful completion, glob() returns zero.  Other possible returns are:

       GLOB_NOSPACE = 1
              for running out of memory, 

       GLOB_ABORTED = 2
              for a read error, and

       GLOB_NOMATCH = 3
              for no found matches.
#endif


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