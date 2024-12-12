#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void check()
{
	system("leaks a.out");
}
int main()
{
	int fd = open("output.txt", O_RDONLY);
	int fd2 = open("output-2.txt", O_RDONLY);
	char *s;
	for(int i = 0; i < 9616; i++)
	{
		s = get_next_line(fd);
		printf("read number %d================\n",i+ 1);
		printf("++%s++\n----------------------\n",s);
		free(s);
		s = get_next_line(fd2);
		printf("read number %d================\n",i+ 1);
		printf("++%s++\n----------------------\n",s);
		free(s);
	}
	close(fd);
	atexit(check);
}