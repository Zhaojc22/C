/*************************************************************************
	> File Name: 100day.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Tue 09 Aug 2022 10:44:59 AM CST
	> Describe:
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define TIMESTRSIZE 1024
#define FMTSTRSIZE 1024

int main(int argc, char **argv)
{
	time_t stamp;
	struct tm *tm;
	char time_str[TIMESTRSIZE];
	char c;
	char format_str[FMTSTRSIZE];
	FILE *fp = stdout;

	format_str[0] = '\0';
	if(argc < 2)
	{
		fprintf(stderr, "Usage .... \n");
		exit(1);
	}

					
	while(1)
	{
		c = getopt(argc, argv, "-H:MSy:md");
		if(c < 0)
			break;

		switch(c)
		{
			case 1:
				if( fp == stdout )
				{
					fp = fopen(argv[optind - 1], "w+");

					if(fp == NULL)
					{
						perror("fopen()");
						fp = stdout;
					}
				}
				break;

			case 'H':
				if(strcmp(optarg, "12") == 0)
					strncat(format_str, "-%I(%P)", FMTSTRSIZE - 1);
				else if( strcmp(optarg, "24") == 0)
					strncat(format_str, "-%H",FMTSTRSIZE - 1);
				else
					fprintf(stderr, "Invalid argument of -H");
				break;

			case 'M':
				strncat(format_str, "-%M", FMTSTRSIZE - 1);
				break;

			case 'S':
				strncat(format_str, "-%S", FMTSTRSIZE - 1);
				break;

			case 'y':
				if(strcmp(optarg, "2") == 0)
					strncat(format_str, "-%y", FMTSTRSIZE - 1);
				else if( strcmp(optarg, "4") == 0)
					strncat(format_str, "-%Y",FMTSTRSIZE - 1);
				else
					fprintf(stderr, "Invalid argument of -y");
				
				break;

			case 'm':
				strncat(format_str, "-%m", FMTSTRSIZE - 1);
				break;

			case 'd':
				strncat(format_str, "-%d", FMTSTRSIZE - 1);
				break;

			default:
				break;	
		}
	}

	strncat(format_str, "\n", FMTSTRSIZE - 1);


	stamp = time(NULL);

	tm = localtime(&stamp);

	strftime(time_str, TIMESTRSIZE, format_str, tm);	

	fputs(time_str, fp);

	if( fp != stdout )
		fclose(fp);

	exit(0);
}
