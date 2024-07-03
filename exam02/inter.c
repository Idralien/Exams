/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:08:03 by brsantsc          #+#    #+#             */
/*   Updated: 2024/07/03 12:18:50 by brsantsc         ###   ########.fr       */
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

void	inter(char *str1, char *str2)
{
	int	i = 0;
	char seen[128] = {0};

	while (*str1)
	{
		if (check(str2, *str1) && !check(seen, *str1))
		{
			write(1, str1, 1);
			seen[i] = *str1;
			i++;
		}
		str1++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
