#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
char	*get_next_line(int fd);

int main() {
	int fd;
	
	fd = open("ejemplo.txt", O_RDONLY);
	printf("%i ", fd);
	get_next_line(fd);

	close (fd);
	return 0;
}

