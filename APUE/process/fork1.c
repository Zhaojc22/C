/*************************************************************************
	> File Name: fork1.c
	> Author: zhaojc
	> Mail: zhaojiacheng@qtec.cn
	> Created Time: Tue 09 Aug 2022 04:45:52 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	printf("[%d]:Begin!\n", getpid());

	fflush(NULL); // !!!!!

	pid = fork();
	if(pid < -1)
	{
		perror("fork()");
		exit(1);
	}
	if(pid == 0)  //child
	{
		printf("[%d]:Child is working!\n", getpid());
	}
	else // parent
	{
		printf("[%d]:Parent is working!\n", getpid());
	}

	printf("[%d]:End!\n", getpid());
	
	// getchar();
	exit(0);
}
