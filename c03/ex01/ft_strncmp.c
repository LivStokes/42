/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olstokes <olstokes@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:07:14 by olstokes          #+#    #+#             */
/*   Updated: 2025/04/08 17:38:27 by olstokes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

/*void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(void)
{
	char	s1[20];
	char	s2[20];
	char	result;

	strcpy(s1, "mieow!");
	strcpy(s2, "meow!");
	result = ft_strncmp(s1, s2, 3);
	if (result > 0)
	{
		ft_putstr("str1 greater than str2\n");
	}
	else if (result < 0)
	{
		ft_putstr("str1 less than str2\n");
	}
	else
	{
		ft_putstr("both strings are equal\n");
	}
	return (0);
}
*/
