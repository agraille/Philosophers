/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:34:41 by agraille          #+#    #+#             */
/*   Updated: 2025/02/21 00:49:13 by agraille         ###   ########.fr       */
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

void	reset_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	give_fork(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->right_fork);
		if (stop_simu(philo) == true)
			return ;
		printf("%s[%ld ms] : Philo %d has taken a fork 🍴\n%s",PURPLE, get_time(), philo->id, RESET);
		pthread_mutex_lock(philo->left_fork);
		if (stop_simu(philo) == true)
			return ;
		printf("%s[%ld ms] : Philo %d has taken a fork 🍴\n%s",PURPLE, get_time(), philo->id, RESET);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		if (stop_simu(philo) == true)
			return ;
		printf("%s[%ld ms] : Philo %d has taken a fork 🍴\n%s",PURPLE, get_time(), philo->id, RESET);
		pthread_mutex_lock(philo->right_fork);
		if (stop_simu(philo) == true)
			return ;
		printf("%s[%ld ms] : Philo %d has taken a fork 🍴\n%s",PURPLE, get_time(), philo->id, RESET);
	}
	is_eating(philo);
}
void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (stop_simu(philo) == true)
			break ;
		give_fork(philo);
		if (philo->eat_count == philo->eat_max)
			break ;
	}
	return (NULL);
}
