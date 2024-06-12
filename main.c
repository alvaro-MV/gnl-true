#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strdup(const char *s1, char c);

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
	char	*next_line;
	size_t	bytes_read;

	fd_1 = open("textos/quijote.txt", O_RDONLY);
	int	n = 4;
	while (n--)
	{
		next_line = get_next_line(fd_1);
		printf("Next line: %s", next_line);
		free(next_line);
	}
// 	while (ft_strncmp(next_line = get_next_line(fd_1), "") != 0)
	//{
		//printf("%s", next_line);
		//free(next_line);
	//}
	//free(next_line);
	close(fd_1);
	return (0);
}
