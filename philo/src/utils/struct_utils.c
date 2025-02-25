/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:39:28 by agraille          #+#    #+#             */
/*   Updated: 2025/02/25 10:21:37 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

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
	table->time_to_die = ft_atoi(argv[2]);
	if (table->time_to_die == 0)
		return (false);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->eat_max = ft_atoi(argv[5]);
	else
		table->eat_max = -1;
	if (table->eat_max == 0)
		return (false);
	return (true);
}

void	init_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].time_to_eat = table->time_to_eat;
		table->philo[i].time_to_sleep = table->time_to_sleep;
		table->philo[i].eat_count = 0;
		table->philo[i].stop = 0;
		table->philo[i].nbr_philo = table->nbr_philo;
		table->philo[i].eat_max = table->eat_max;
		table->philo[i].time_start = get_time();
		i++;
	}
	i = 0;
	while (table->nbr_philo > 1 && i < table->nbr_philo)
	{
		if (table->philo[i].id == table->nbr_philo)
			table->philo[i].left_fork = &table->philo[0].right_fork;
		else
			table->philo[i].left_fork = &table->philo[i + 1].right_fork;
		i++;
	}
}
