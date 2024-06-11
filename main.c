#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1, char c);
char	*ft_strchr(const char *s, int c);

int	ft_strncmp(char	*s1, char	*s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return ((unsigned char) *s1 - (unsigned char) *s2);
	else
		return (0);
}

int main(void) {
	int		fd_1;
	int		fd_2;
	char	*next_line;
	size_t	bytes_read;

	fd_1 = open("textos/aer.txt", O_RDONLY);
	fd_2 = open("textos/ejemplo.txt", O_RDONLY);
	int	n = 4;
	next_line = get_next_line(fd_1);
	printf("Next line: %s", next_line);
	free(next_line);
	next_line = get_next_line(fd_2);
	printf("Next line: %s\n\n", next_line);
	free(next_line);

	next_line = get_next_line(fd_1);
	printf("Next line: %s", next_line);
	free(next_line);
	next_line = get_next_line(fd_2);
	printf("Next line: %s", next_line);
	free(next_line);
//	while (n--)
	//{
		//next_line = get_next_line(100);
		//printf("%s", next_line);
		//free(next_line);
	//}

// 	while (ft_strncmp(next_line = get_next_line(fd), "") != 0)
	//{
		//printf("%s", next_line);
		//free(next_line);
	//}
	//free(next_line);
	close(fd_1);
	close(fd_2);

	return (0);
}
