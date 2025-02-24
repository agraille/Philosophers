/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:14:47 by agraille          #+#    #+#             */
/*   Updated: 2025/02/24 11:23:36 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	is_thinking(t_philo *philo)
{
	ft_usleep(1);
	if (stop_simu(philo) == true)
		return ;
	pthread_mutex_lock(philo->print_lock);
	printf("%s[%ld ms] : Philo %d is thinking      💭%s\n" \
		, YELLOW, get_time(), philo->id, RESET);
	pthread_mutex_unlock(philo->print_lock);
}

static void	is_sleeping(t_philo *philo)
{
	if (stop_simu(philo) == true)
		return ;
	pthread_mutex_lock(philo->print_lock);
	printf("%s[%ld ms] : Philo %d is sleeping      🛌%s\n" \
		, BLUE, get_time(), philo->id, RESET);
	pthread_mutex_unlock(philo->print_lock);
	ft_usleep(philo->time_to_sleep);
	if (philo->time_to_sleep < philo->time_to_eat)
		ft_usleep(philo->time_to_eat - philo->time_to_sleep);
	is_thinking(philo);
}

void	is_eating(t_philo *philo)
{
	if (stop_simu(philo) == true)
	{
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->print_lock);
	printf("%s[%ld ms] : Philo %d is eating        🍝%s\n" \
		, GREEN, get_time(), philo->id, RESET);
	pthread_mutex_unlock(philo->print_lock);
	pthread_mutex_lock(&philo->time_lock);
	philo->time_start = get_time();
	pthread_mutex_unlock(&philo->time_lock);
	ft_usleep(philo->time_to_eat);
	reset_fork(philo);
	if (philo->eat_count != -1)
		philo->eat_count++;
	is_sleeping(philo);
}
