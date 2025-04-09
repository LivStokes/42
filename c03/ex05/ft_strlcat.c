/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olstokes <olstokes@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 10:23:43 by olstokes          #+#    #+#             */
/*   Updated: 2025/04/09 12:21:44 by olstokes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	destl;
	unsigned int	srcl;
	unsigned int	i;

	destl = 0;
	srcl = 0;
	i = 0;
	while (dest[destl] && destl < size)
		destl++;
	while (src[srcl])
		srcl++;
	if (size <= destl)
		return (size + srcl);
	while (src[i] && (destl + i + 1) < size)
	{
		dest[destl + i] = src[i];
		i++;
	}
	dest[destl + i] = '\0';
	return (destl + srcl);
}
/*
void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(void)
{
	char	dest[20];
	char	src[20];

	strcpy(dest, "Hello, ");
	strcpy(src, "World");
	ft_strlcat(dest, src, 5);
	ft_putstr(dest);
	write(1, "\n", 1);
	return (0);
}
*/
