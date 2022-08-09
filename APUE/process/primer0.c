/*************************************************************************
	> File Name: fork2.c
	> Author: zhaojc
	> Mail: zhaojiacheng@qtec.cn
	> Created Time: Tue 09 Aug 2022 05:18:29 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEFT 30000000
#define RIGHT 30000200
int main()
{
	int i, j, mark;
	for(i = LEFT; i <= RIGHT; i++)
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
			printf("%d is a primern\n", i);
	}


	exit(0);
}





