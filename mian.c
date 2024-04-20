#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
char	*get_next_line(int fd);

int main() {
	int 	fd;
	char	*next_line;

	fd = open("segundo_ejemplo.txt", O_RDONLY);
	printf("%i\n", fd);
	next_line = get_next_line(fd);
	printf("return_buffer: %s\n", next_line);
	free(next_line);

	next_line = get_next_line(fd);
	printf("return_buffer: %s\n", next_line);
	free(next_line);

	next_line = get_next_line(fd);
	printf("return_buffer: %s\n", next_line);
	free(next_line);

	close (fd);
	return (0);
}

