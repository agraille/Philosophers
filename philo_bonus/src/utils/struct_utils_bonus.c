/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:39:28 by agraille          #+#    #+#             */
/*   Updated: 2025/02/24 21:44:29 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

static bool	check_eat_max(t_table *table, char *argv)
{
	if (argv[5])
	{
		table->eat_max = ft_atoi(argv[5]);
		if (table->eat_max == 0)
			return (false);
		table->eat_count = 0;
	}
	else
		table->eat_count = -1;
}

bool	init_args(t_table *table, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == -1)
			return (false);
		i++;
	}
	table->nbr_philo = ft_atoi(argv[1]);
	if (table->nbr_philo > 200)
	{
		write(2, "Max philo was 200\n", 18);
		return (false);
	}
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (check_eat_max(table, argv[5]) == false)
		return (false);
	return (true);
}
