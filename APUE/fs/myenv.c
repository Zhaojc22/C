/*************************************************************************
	> File Name: myenv.c
	> Author: zhaojc
	> Mail: zhaojiacheng@qtec.cn
	> Created Time: Tue 09 Aug 2022 02:49:54 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main()
{
	int i;
	for(i = 0; environ[i] != NULL; i++)
		puts(environ[i]);

	exit(0);
}