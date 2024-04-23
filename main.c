#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
char	*get_next_line(int fd);

int main() {
	int		fd;
	char	*next_line;
	size_t	bytes_read;

	fd = open("segundo_ejemplo.txt", O_RDONLY);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	int n = 2;
	while(n--)
	{
		free(next_line);
		next_line = get_next_line(fd);
		printf("%s", next_line);
	}
/* 	//printf("%s", next_line);

	next_line = get_next_line(fd);
	//printf("%s", next_line);
 */
	next_line = get_next_line(fd);
	printf("%s", next_line);
	close (fd);
	system("leaks a.out");
	return (0);
}

