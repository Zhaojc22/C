/*************************************************************************
	> File Name: myshell.c
	> Author: zhaojc
	> Mail: zhaojiacheng@qtec.cn
	> Created Time: Thu 11 Aug 2022 02:36:19 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <glob.h>

struct cmd_st
{
	glob_t glob_res;
};

#define DELIMS " \t\n"

static void prompt(void)
{
	printf("myshell-0.1$ ");
}


static void pares(char *line, struct cmd_st *cmd)
{
	char *tok;
	int flag = 0;

	while(1)
	{
		tok = strsep(&line, DELIMS);

		if(tok == NULL)
			break;
		if(tok[0] == '\0')
			continue;

		glob(tok, GLOB_NOCHECK | GLOB_APPEND * flag, NULL, &cmd->glob_res);
		flag = 1;
	}

}

int main()
{
	char *linebuf = NULL;
	size_t linebuf_size = 0;
	struct cmd_st cmd;
	pid_t pid;
	while(1)
	{

		prompt();

		if(getline(&linebuf, &linebuf_size, stdin) < 0)
			break;

		pares(linebuf, &cmd);

		if(0)
		{
			//do something
		}
		else
		{
			pid = fork();
			if(pid < 0)
			{
				perror("fork()");
				exit(1);
			}
			if(pid == 0)
			{
				execvp(cmd.glob_res.gl_pathv[0], cmd.glob_res.gl_pathv);
				perror("execvp");
				exit(1);
			}
			else
			{
				wait(NULL);
			}
		}

	}


	exit(0);

}
