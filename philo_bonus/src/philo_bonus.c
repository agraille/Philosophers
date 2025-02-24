/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:34:41 by agraille          #+#    #+#             */
/*   Updated: 2025/02/24 21:41:37 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	stop_simu(t_table *table)
{
	if (get_time() - table->time_start >= table->time_to_die)
	{
		sem_wait(table->print);
		printf("%s[%ld ms] : Philo %d is died          💀\n%s", \
			RED, get_time(), table->id, RESET);
		sem_post(table->print);
		close_semaphore_forks(table);
		close_semaphore_print(table);
		kill(getpid(), SIGKILL);
	}
}

void	give_fork(t_table *table)
{
	sem_wait(table->forks);
	stop_simu(table);
	sem_wait(table->print);
	printf("%s[%ld ms] : Philo %d has taken a fork 🍴\n%s", \
			PURPLE, get_time(), table->id, RESET);
	sem_post(table->print);
	sem_wait(table->forks);
	stop_simu(table);
	sem_wait(table->print);
	printf("%s[%ld ms] : Philo %d has taken a fork 🍴\n%s", \
			PURPLE, get_time(), table->id, RESET);
	sem_post(table->print);
	is_eating(table);
}

void	*start_routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	table->time_start = get_time();
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
