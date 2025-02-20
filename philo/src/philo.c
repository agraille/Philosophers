/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:34:41 by agraille          #+#    #+#             */
/*   Updated: 2025/02/20 13:42:07 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	stop_simu(t_philo *philo)
{
	pthread_mutex_lock(&philo->stop_lock);
	if (philo->stop == 1 || philo->eat_count == philo->eat_max)
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
	if (stop_simu(philo) == true)
		return ;
	if (philo->id % 2 != 0) 
    {
        pthread_mutex_lock(philo->right_fork);
        pthread_mutex_lock(philo->left_fork);
        // printf("[%ld ms] : Philo %d has taken a fork 🍴\n", get_time(), philo->id);
		printf("%ld %d has taken a fork\n",  get_time(), philo->id);
    }
    else
    {
        pthread_mutex_lock(philo->left_fork);
        pthread_mutex_lock(philo->right_fork);
        // printf("[%ld ms] : Philo %d has taken a fork 🍴\n", get_time(), philo->id);
		printf("%ld %d has taken a fork\n",  get_time(), philo->id);
    }
	is_eating(philo);
}
void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		give_fork(philo);
		if (philo->eat_count == philo->eat_max)
		{
			philo->stop = 1;
			break ;
		}
		if (stop_simu(philo) == true)
			break ;
	}
	return (NULL);
}
