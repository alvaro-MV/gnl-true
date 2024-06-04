#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1, char c);
char	*ft_strchr(const char *s, int c);

int main(void) {
	int		fd;
	char	*next_line;
	size_t	bytes_read;

	fd = open("textos/linea_larga.txt", O_RDONLY);
	int	n = 15;
	while (n--)
	{
		next_line = get_next_line(fd);
		printf("%s", next_line);
		free(next_line);
	}
	printf("Hol que tal.");
	printf("Comprobando que todo esta bien");
	//system("leaks a.out");
	close (fd);
	return (0);
}

// int	main(void)
 //{
	//char	read_buff[20];
	//int		fd;
	//int		n = 3;

	//fd = open("textos/notes.txt", O_RDONLY);
	//printf("fd after while: %i\n", fd);
	//while (fd != -1)
	//{
		//read(fd, read_buff, 20);
		//printf("%s", read_buff);
		//printf("|||");
		//printf("%i", fd);
	//}
	//close(fd);
	//return (0);
 //}
