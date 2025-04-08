/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olstokes <olstokes@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:08:27 by olstokes          #+#    #+#             */
/*   Updated: 2025/04/08 18:34:17 by olstokes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

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
/*
int	main(void)
{
	char	dest[20] = "Hello";
	char	src[20] = "Meow";
	char	*s;

	ft_strcat(dest, src);
	s = dest;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	write(1, "\n", 1);
	return (0);
}
*/
