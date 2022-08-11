/*************************************************************************
	> File Name: few.c
	> Author: zhaojc
	> Mail: zhaojiacheng@qtec.cn
	> Created Time: Thu 11 Aug 2022 02:19:39 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main()
{
	pid_t pid;

	puts("Begin!");

	fflush(NULL);

	pid = fork();

	if(pid < 0)
	{
		perror("fork()");
		exit(1);
	}

	if(pid == 0)
	{
		execl("/bin/sleep", "sleep", "100", NULL);
		// execl("/bin/sleep", "httpd", "100", NULL); //可以在进程中因此真正的进程名
		perror("execl()"); 
		exit(1);
	}

	wait(NULL);
	
	puts("End");

	exit(0);
}
