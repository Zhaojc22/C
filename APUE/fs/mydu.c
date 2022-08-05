/*
 * @Author: Zhaojc
 * @Date: 2022-08-05 09:35:16
 * @LastEditTime: 2022-08-05 13:32:29
 * @Descripttion: 仿照命令 du， 输出目标路径文件的块大小，如果是文件夹就输出文件夹下所有文件的块大小的和，当前实现可能会在测试是同 du 命令有一些不同，这可能是因为有一些文件我们没有权限，需要后续优化
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
    // 通过 lstat 函数获取路径所对应的文件
    if (lstat(path, &stat_res) < 0)
    {
        perror("lstat()");
        exit(1);
    }
    // 判断获取的文件的文件类型，只要不是文件夹了，就可以获取块大小，然后返回
    if (!S_ISDIR(stat_res.st_mode))
    {
        fprintf(stdout, "%ld    %s\n", stat_res.st_blocks, path);
        return stat_res.st_blocks;
    }
    // 是文件夹就要向下递归操作，查找下面所有的文件了，包括隐藏文件
    strncpy(nextpath, path, PATHSIZE - 1);

    strncat(nextpath, "/*", PATHSIZE - 1);
    // 获取非隐藏的文件
    ret = glob(nextpath, 0, NULL, &glob_res);
    // 有一些空文件
    if (ret == 3)
        return 8;
    if (ret)
    {
        fprintf(stderr, "glob error1 -- %d\n", ret);
        exit(1);
    }

    strncpy(nextpath, path, PATHSIZE - 1);

    strncat(nextpath, "/.*", PATHSIZE - 1);
    // 获取隐藏文件， 添加到之前获取的非隐藏文件结构体中
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
        // 这里如果不加判断的话就会在某一个文件夹下死循环，因 /. 一直在当前文件夹下转
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