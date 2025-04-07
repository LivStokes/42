/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olstokes <olstokes@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:02:43 by olstokes          #+#    #+#             */
/*   Updated: 2025/04/07 16:16:13 by olstokes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	next;

	i = 0;
	next = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (next && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		if ((str[i] < '0')
			|| (str[i] > '9' && str[i] < 'A')
			|| (str[i] > 'Z' && str[i] < 'a')
			|| (str[i] > 'z'))
			next = 1;
		else
			next = 0;
		i++;
	}
	return (str);
}

/*void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	main(void)
{
	char	str1[] = "heLlo wOrld!";
	char	str2[] = "meow MeOw";

	ft_putstr(ft_strcapitalize(str1));
	write(1, "\n", 1);
	

	ft_putstr(ft_strcapitalize(str2));
	write(1, "\n", 1);

	return (0);
}
*/
