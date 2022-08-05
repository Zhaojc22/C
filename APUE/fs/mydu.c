/*
 * @Author: Zhaojc
 * @Date: 2022-08-05 09:35:16
 * @LastEditTime: 2022-08-05 13:32:29
 * @Descripttion: 仿照命令 du
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <glob.h>

#define PATHSIZE 1024

static int path_noloop(const char *path)
{
    char *pos;
    pos = strrchr(path, '/');
    if (pos == NULL)
    {
        exit(1);
    }

    if (strcmp(pos + 1, ".") == 0 || strcmp(pos + 1, "..") == 0)
    {
        return 0;
    }
    return 1;
}

static int64_t mydu(const char *path)
{
    static struct stat stat_res;
    static char nextpath[PATHSIZE];
    glob_t glob_res;
    int64_t sum = 0;
    int i, ret;

    if (lstat(path, &stat_res) < 0)
    {
        perror("lstat()");
        exit(1);
    }
    
    if (!S_ISDIR(stat_res.st_mode))
    {
        fprintf(stdout, "%ld    %s\n", stat_res.st_blocks, path);
        return stat_res.st_blocks;
    }

    strncpy(nextpath, path, PATHSIZE - 1);

    strncat(nextpath, "/*", PATHSIZE - 1);

    ret = glob(nextpath, 0, NULL, &glob_res);
    if (ret == 3)
        return 8;
    if (ret)
    {
        fprintf(stderr, "glob error1 -- %d\n", ret);
        exit(1);
    }

    strncpy(nextpath, path, PATHSIZE - 1);

    strncat(nextpath, "/.*", PATHSIZE - 1);

    ret = glob(nextpath, GLOB_APPEND, NULL, &glob_res);
    if (ret == 3)
        return 8;
    if (ret)
    {
        fprintf(stderr, "glob error2 -- %d\n", ret);
        exit(1);
    }
    sum = stat_res.st_blocks;
    for (i = 0; i < glob_res.gl_pathc; i++)
    {
        if (path_noloop(glob_res.gl_pathv[i]))
            sum += mydu(glob_res.gl_pathv[i]);
    }

    globfree(&glob_res);

    return sum;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }

    printf("%ld\n", mydu(argv[1]) / 2);
    exit(0);
}