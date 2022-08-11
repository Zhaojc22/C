/*************************************************************************
	> File Name: system.c
	> Author: zhaojc
	> Mail: zhaojiacheng@qtec.cn
	> Created Time: Thu 11 Aug 2022 03:39:31 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


int main()
{
	system("date +%s > /tmp/out");

	exit(0);
}
