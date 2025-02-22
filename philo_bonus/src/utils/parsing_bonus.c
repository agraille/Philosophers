/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:05:45 by agraille          #+#    #+#             */
/*   Updated: 2025/02/22 14:46:02 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

int	ft_atoi(char *arg)
{
	unsigned int	result;

	result = 0;
	while (*arg >= '0' && *arg <= '9')
	{
		if (result * 10 / 10 != result)
		{
			write(2, "Value to big !\n", 15);
			return (-1);
		}
		result = result * 10 + (*arg - '0');
		arg++;
	}
	if (result > USHRT_MAX)
	{
		write(2, "Value to big !\n", 15);
		return (-1);
	}
	return (result);
}

bool	parsing(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
