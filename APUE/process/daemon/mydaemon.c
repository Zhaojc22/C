/*************************************************************************
	> File Name: mydeamon.c
	> Author: zhaojc
	> Mail: zhaojiacheng@qtec.cn
	> Created Time: Thu 11 Aug 2022 04:11:22 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <syslog.h>
#include <errno.h>

#define F_NAME "/tmp/out"

static int daemonize(void)
{
	pid_t pid;
	int fd;
	pid = fork();

	if(pid < 0)
		return -1;

	if(pid > 0)
		exit(0);

	fd = open("/dev/null", O_RDWR);

	if(fd < 0)
		return -1;
	
	dup2(fd, 0);
	dup2(fd, 1);
	dup2(fd, 2);
	if(fd > 2)
		close(fd);

	setsid();
	chdir("/");
	// umask(0);
	return 0;
}

int main()
{
	FILE *fp;
	int i;

	openlog("mydaemon", LOG_PID, LOG_DAEMON);


	if(daemonize())
	{
		syslog(LOG_ERR, "daemonize() failed!");
		exit(1);
	}
	else
		syslog(LOG_INFO, "daemonize() successed!");


	fp = fopen(F_NAME, "w");
	if(fp == NULL)
	{
		syslog(LOG_ERR, "fopen() failed:%s!", strerror(errno));
		exit(1);
	}

	syslog(LOG_INFO, "%s() opened!", F_NAME);

	for(i = 0; ;i++)
	{
		fprintf(fp, "%d\n", i);
		fflush(fp);
		syslog(LOG_DEBUG, "%d() is printed!", i);
		sleep(1);
	}

	fclose(fp);
	closelog();
	exit(0);
}
