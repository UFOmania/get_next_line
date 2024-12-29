#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void check()
{
	system("leaks a.out");
}
int main(){
	int fd = open("x.txt", O_RDONLY);
	for(int i = 0; i < 20; i++)
	{
		char *line = get_next_line(fd);
		printf("%s",line);
		free (line);
	}
	check();
	return (0);
}