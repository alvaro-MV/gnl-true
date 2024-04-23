#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1, char c);
char	*ft_strchr(const char *s, int c);

int main() {
	int		fd;
	char	*next_line;
	size_t	bytes_read;

	fd = open("segundo_ejemplo.txt", O_RDONLY);
	next_line = get_next_line(fd);
	printf("%s", next_line);

	free(next_line);
	next_line = get_next_line(fd);
	printf("%s", next_line);

	next_line = get_next_line(fd);
	printf("%s", next_line);

	next_line = get_next_line(fd);
	printf("%s", next_line);
	close (fd);
	//system("leaks a.out");
	return (0);
}

// int	main(void)
// {
// 	char	str[] = "Hola que tal estais.\n Espero que bien.\n Adios";
// 	printf("ft_strdup:%s", ft_strdup(str, '\n'));
// 	printf("ft_strchr:%s",ft_strchr(str, '\n'));
// }
