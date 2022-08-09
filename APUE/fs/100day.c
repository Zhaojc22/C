/*************************************************************************
	> File Name: 100day.c
	> Author: zhaojc
	> Mail: zhaojiacheng@qtec.cn
	> Created Time: Tue 09 Aug 2022 10:44:59 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIMESTRSIZE 1024
int main()
{
	time_t stamp;
	struct tm *tm;
	char time_str[TIMESTRSIZE];

	stamp = time(NULL);

	tm = localtime(&stamp);

	strftime(time_str, TIMESTRSIZE, "Now:%Y-%m-%d", tm);

	puts(time_str);

	tm->tm_mday += 100;

	(void)mktime(tm);

	strftime(time_str, TIMESTRSIZE, "100 days later :%Y-%m-%d", tm);

	puts(time_str);


	exit(0);
}
