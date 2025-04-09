/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olstokes <olstokes@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 10:21:14 by olstokes          #+#    #+#             */
/*   Updated: 2025/04/09 16:56:50 by olstokes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*s;
	char	*ss;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		s = str;
		ss = to_find;
		while (*s && *ss && *s == *ss)
		{
			s++;
			ss++;
		}
		if (*ss == '\0')
			return (str);
		str++;
	}
	return (0);
}
/*
void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(void)
{
	char	str[30] = "the start the end";
	char	to_find[20] = "the start";
	char	*result;

	result = ft_strstr(str, to_find);
	if (result)
		ft_putstr(result);
	else
		ft_putstr("ss not found");
	write(1, "\n", 1);
	return (0);
}
*/
