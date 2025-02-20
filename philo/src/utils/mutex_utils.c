/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:55:04 by agraille          #+#    #+#             */
/*   Updated: 2025/02/21 00:31:16 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	destroy_mutex(t_table *table)
{
	int i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_mutex_destroy(&table->philo[i].stop_lock);
		pthread_mutex_destroy(&table->philo[i].time_lock);
		pthread_mutex_destroy(table->philo[i].left_fork);
		// pthread_mutex_destroy(table->philo[i].right_fork);
		free(table->philo[i].left_fork);
		// free(table->philo[i].right_fork);
		i++;
	}
}

bool	create_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		table->philo[i].right_fork = malloc(sizeof(pthread_mutex_t));
		table->philo[i].left_fork = malloc(sizeof(pthread_mutex_t));
		if (!table->philo[i].right_fork || !table->philo[i].left_fork)
		{
			free(table->philo);
			write(2, "Mutex init fail", 15);
			return (false);
		}
		if (pthread_mutex_init(&table->philo[i].stop_lock, NULL) != 0 \
		|| pthread_mutex_init(&table->philo[i].time_lock, NULL) != 0\
		|| pthread_mutex_init(table->philo[i].right_fork, NULL) != 0\
		|| pthread_mutex_init(table->philo[i].left_fork, NULL) != 0)
		{
			while (--i >= 0)
			{
				pthread_mutex_destroy(&table->philo[i].stop_lock);
				pthread_mutex_destroy(&table->philo[i].time_lock);
				pthread_mutex_destroy(table->philo[i].right_fork);
				pthread_mutex_destroy(table->philo[i].left_fork);
				// revoir le free
			}
			free(table->philo);
			write(2, "Mutex init fail", 15);
			return (false);
		}
		i++;
	}
	return (true);
}
