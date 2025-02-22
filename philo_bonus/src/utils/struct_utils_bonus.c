/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:39:28 by agraille          #+#    #+#             */
/*   Updated: 2025/02/22 14:47:59 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

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
	if (table->nbr_philo > 250)
	{
		write(2, "Max philo was 250\n", 18);
		return (false);
	}
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->eat_max = ft_atoi(argv[5]);
	else
		table->eat_max = -1;
	return (true);
}
