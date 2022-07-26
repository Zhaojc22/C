/*************************************************************************
	> File Name: fork2.c
	> Author: zhaojc
	> Mail: zhaojiacheng@qtec.cn
	> Created Time: Tue 09 Aug 2022 05:18:29 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#define LEFT 30000000
#define RIGHT 30000200
int main()
{
	int pid;
	int i, j, mark;
	int n;
	int N = 3;
	for(n = 0; n < N; n++)
	{
		pid = fork();
		
		if(pid < 0)
		{
			perror("fork()");
			exit(1);
		}
		
		if(pid == 0)
		{
			for(i = LEFT + n; i <= RIGHT; i += N )
			{
				mark = 1;
			
			for(j = 2; j < i / 2; j++)
			{
 				if(i % j == 0)
				{
					mark = 0;
					break;
				}
			}
			if(mark)
				printf("[%d]%d is a primern\n", n, i);

			}
			exit(0);
		}   
	}

	for(n=0; n < N; n++)
		wait(NULL);

	exit(0);
}


