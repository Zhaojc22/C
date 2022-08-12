/*************************************************************************
	> File Name: star.c
	> Author: zhaojc
	> Mail: zhaojiacheng@qtec.cn
	> Created Time: Fri 12 Aug 2022 05:06:14 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

static void INT_HANDLER(int s)
{
	write(1, "!", 1);
}

int main()
{
	int i;

//	signal(SIGINT, SIG_IGN);
	signal(SIGINT, INT_HANDLER);
	for(i = 0; i < 10; i++)
	{
		write(1,"*", 1);
		sleep(1);
	}

	exit(0);
}
