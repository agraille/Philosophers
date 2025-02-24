/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:34:41 by agraille          #+#    #+#             */
/*   Updated: 2025/02/24 15:57:02 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	stop_simu(t_table *table)
{
	sem_wait(table->print);
	printf("%s[%ld ms] : Philo %d is died          💀\n%s", \
					RED, get_time(), table->id, RESET);
	sem_post(table->print);
}


void	give_fork(t_table *table)
{
	sem_wait(table->print);
	printf("%s[%ld ms] : Philo %d has taken a fork 🍴\n%s", \
			PURPLE, get_time(), table->id, RESET);
	sem_post(table->print);
	sem_wait(table->print);
	printf("%s[%ld ms] : Philo %d has taken a fork 🍴\n%s", \
			PURPLE, get_time(), table->id, RESET);
	sem_post(table->print);
	is_eating(table);
}

void	*start_routine(void *arg)
{
	t_table *table;

	table = (t_table *)arg;
	if (table->nbr_philo == 1)
	{
		printf("%s[%ld ms] : Philo %d has taken a fork 🍴\n%s", \
			PURPLE, get_time(), table->id, RESET);
		return (NULL);
	}
	if (table->id % 2 == 0)
		ft_usleep(1);
	while (1)
	{
		stop_simu(table);
		give_fork(table);
		if (table->eat_count == table->eat_max)
			exit(EXIT_SUCCESS);
	}
	return (NULL);
}
