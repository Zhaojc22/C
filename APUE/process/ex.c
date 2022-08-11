/*************************************************************************
	> File Name: ex.c
	> Author: zhaojc
	> Mail: zhaojiacheng@qtec.cn
	> Created Time: Thu 11 Aug 2022 02:12:34 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("Begin!\n");

	fflush(NULL);

	execl("/bin/date", "date", "+%s", NULL);
	
	perror("execl()");

	exit(1);

	printf("End!\n");

	exit(0);
}
