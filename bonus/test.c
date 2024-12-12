#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

// void check()
// {
// 	system("leaks a.out");
// }
int main()
{
	int fd = open("files/x", O_RDONLY);
	int fc = open("files/y", O_RDONLY);
	printf("fd = %d\n", fd);
	char *s;
	for(int i = 0; i < 6; i++)
	{
		s = get_next_line_bonus(fd);
		printf("r number %d================\n",i+ 1);
		printf("++%s++\n----------------------\n",s);
		free(s);
		s = get_next_line_bonus(fc);
		printf("r number %d================\n",i+ 1);
		printf("++%s++\n----------------------\n",s);
		free(s);
	}
	close(fd);
	//atexit(check);
}