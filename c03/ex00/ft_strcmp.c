/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olstokes <olstokes@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:47:29 by olstokes          #+#    #+#             */
/*   Updated: 2025/04/09 12:26:09 by olstokes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "more than 2 strings\n", 20);
		return (1);
	}
	if (ft_strcmp(argv[1], argv[2]) == 0)
		write(1, "same\n", 5);
	else
		write(1, "not same\n", 9);
	return (0);
}
*/
