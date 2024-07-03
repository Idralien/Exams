/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:59:45 by brsantsc          #+#    #+#             */
/*   Updated: 2024/07/03 12:05:58 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	ft_union(char *str1, char *str2)
{
	int	i = 0;
	char seen[256] = {0};

	while (*str1)
	{
		if (!check(seen, *str1))
		{
			seen[i] = *str1;
			write(1, str1, 1);
			i++;
		}
		str1++;
	}
	while (*str2)
	{
		if (!check(seen, *str2))
		{
			seen[i] = *str2;
			write(1, str2, 1);
			i++;
		}
		str2++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
