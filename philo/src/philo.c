/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:34:41 by agraille          #+#    #+#             */
/*   Updated: 2025/02/24 15:41:41 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	stop_simu(t_philo *philo)
{
	pthread_mutex_lock(&philo->stop_lock);
	if (philo->stop == 1)
	{
		pthread_mutex_unlock(&philo->stop_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->stop_lock);
	return (false);
}

static void	print_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->print_lock);
	printf("%s[%ld ms] : Philo %d has taken a fork 🍴%s\n", \
		PURPLE, get_time(), philo->id, RESET);
	pthread_mutex_unlock(philo->print_lock);
}

static bool	took_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	if (stop_simu(philo) == true)
	{
		pthread_mutex_unlock(&philo->right_fork);
		return (false);
	}
	print_take_fork(philo);
	pthread_mutex_lock(philo->left_fork);
	if (stop_simu(philo) == true)
	{
		reset_fork(philo);
		return (false);
	}
	print_take_fork(philo);
	return (true);
}

void	give_fork(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		if (took_odd(philo) == false)
			return ;
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		if (stop_simu(philo) == true)
		{
			pthread_mutex_unlock(philo->left_fork);
			return ;
		}
		print_take_fork(philo);
		pthread_mutex_lock(&philo->right_fork);
		if (stop_simu(philo) == true)
		{
			reset_fork(philo);
			return ;
		}
		print_take_fork(philo);
	}
	is_eating(philo);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->nbr_philo == 1)
	{
		print_take_fork(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (1)
	{
		if (stop_simu(philo) == true)
			break ;
		if (philo->nbr_philo > 1)
			give_fork(philo);
		if (philo->eat_count == philo->eat_max)
		{
			pthread_mutex_lock(&philo->stop_lock);
			philo->stop = 1;
			pthread_mutex_unlock(&philo->stop_lock);
			break ;
		}
	}
	return (NULL);
}
