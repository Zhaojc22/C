/*************************************************************************
	> File Name: mysu.c
	> Author: zhaojc
	> Mail: zhaojiacheng@qtec.cn
	> Created Time: Thu 11 Aug 2022 03:22:06 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char **argv)
{
	pid_t pid;
	if(argc < 3)
	{
		fprintf(stderr, "Usage ...\n");
		exit(1);
	}
	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		exit(1);
	}

	if(pid == 0)
	{
		setuid(atoi(argv[1]));
		execvp(argv[2], argv+2);
		perror("execvp()");
		exit(1);
	}

	wait(NULL);
	
	exit(0);
}