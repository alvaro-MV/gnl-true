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
	int		fd;
	char	*next_line;
	size_t	bytes_read;

	fd = open("textos/quijote.txt", O_RDONLY);
//	int	n = 16;
	//while (n--)
	//{
		//next_line = get_next_line(fd);
		//printf("%s", next_line);
		//free(next_line);
	//}

	while (ft_strncmp(next_line = get_next_line(fd), "") != 0)
	{
		printf("%s", next_line);
		free(next_line);
	}
	free(next_line);
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
