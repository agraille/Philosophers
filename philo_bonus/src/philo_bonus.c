/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:34:41 by agraille          #+#    #+#             */
/*   Updated: 2025/02/22 20:31:19 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

// static bool	took_odd(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->right_fork);
// 	if (stop_simu(philo) == true)
// 	{
// 		pthread_mutex_unlock(&philo->right_fork);
// 		return (false);
// 	}
// 	printf("%s[%ld ms] : Philo %d has taken a fork 🍴\n%s", \
// 		PURPLE, get_time(), philo->id, RESET);
// 	pthread_mutex_lock(&philo->left_fork);
// 	if (stop_simu(philo) == true)
// 	{
// 		reset_fork(philo);
// 		return (false);
// 	}
// 	printf("%s[%ld ms] : Philo %d has taken a fork 🍴\n%s", \
// 		PURPLE, get_time(), philo->id, RESET);
// 	return (true);
// }

// void	give_fork(t_philo *philo)
// {
// 	if (philo->id % 2 != 0)
// 	{
// 		if (took_odd(philo) == false)
// 			return ;
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(&philo->left_fork);
// 		if (stop_simu(philo) == true)
// 		{
// 			pthread_mutex_unlock(&philo->left_fork);
// 			return ;
// 		}
// 		printf("%s[%ld ms] : Philo %d has taken a fork 🍴\n%s", \
// 			PURPLE, get_time(), philo->id, RESET);
// 		pthread_mutex_lock(&philo->right_fork);
// 		if (stop_simu(philo) == true)
// 		{
// 			reset_fork(philo);
// 			return ;
// 		}
// 		printf("%s[%ld ms] : Philo %d has taken a fork 🍴\n%s", \
// 			PURPLE, get_time(), philo->id, RESET);
// 	}
// 	is_eating(philo);
// }

// void	*start_routine(void *arg)
// {

// 	while (1)
// 	{
// 		if (stop_simu(philo) == true)
// 			break ;
// 		give_fork(philo);
// 		if (philo->eat_count == philo->eat_max)
// 		{
// 			pthread_mutex_lock(&philo->stop_lock);
// 			philo->stop = 1;
// 			pthread_mutex_unlock(&philo->stop_lock);
// 			break ;
// 		}
// 	}
// 	return (NULL);
// }
