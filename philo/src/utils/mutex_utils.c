/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:55:04 by agraille          #+#    #+#             */
/*   Updated: 2025/02/25 15:48:52 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	reset_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	destroy_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_mutex_destroy(&table->philo[i].time_lock);
		pthread_mutex_destroy(&table->philo[i].right_fork);
		i++;
	}
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->stop_lock);
}

static void	destroy_mutex_reverse(t_table *table, int i)
{
	while (--i >= 0)
	{
		pthread_mutex_destroy(&table->philo[i].time_lock);
		pthread_mutex_destroy(&table->philo[i].right_fork);
	}
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->stop_lock);
}

static bool	init_mutex_secu(t_table *table, int i)
{
	
	if (pthread_mutex_init(&table->philo[i].time_lock, NULL) != 0)
	{
		return (false);
	}
	if (pthread_mutex_init(&table->philo[i].right_fork, NULL) != 0)
	{
		pthread_mutex_destroy(&table->philo[i].time_lock);
		return (false);
	}
	table->philo[i].print_lock = &table->print_lock;
	table->philo[i].stop_lock = &table->stop_lock;
	return (true);
}

bool	create_mutex(t_table *table)
{
	int	i;

	if (pthread_mutex_init(&table->print_lock, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&table->stop_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&table->print_lock);
		return (false);
	}
	i = 0;
	while (i < table->nbr_philo)
	{
		if (init_mutex_secu(table, i) == false)
			break ;
		i++;
	}
	if (i < table->nbr_philo)
	{
		destroy_mutex_reverse(table, i);
		free(table->philo);
		write(2, "Mutex init fail", 15);
		return (false);
	}
	return (true);
}
