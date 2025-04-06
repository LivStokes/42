#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
	{
		dest[i++] = *src++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char	dest[100];
	char	src[];

	ft_strcat(dest, src);

	char	*s
	s	= dest;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	write(1, "\n", 1);
	return (0);
}
