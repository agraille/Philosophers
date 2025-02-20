/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:14:47 by agraille          #+#    #+#             */
/*   Updated: 2025/02/21 00:54:29 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	is_thinking(t_philo *philo)
{
	if (stop_simu(philo) == true)
		return ;
	printf("%s[%ld ms] : Philo %d is thinking      💭\n%s" \
		,YELLOW, get_time(), philo->id, RESET);
}

static void	is_sleeping(t_philo *philo)
{
	if (stop_simu(philo) == true)
		return ;
	printf("%s[%ld ms] : Philo %d is sleeping      🛌\n%s" \
		,BLUE, get_time(), philo->id, RESET);
	ft_usleep(philo->time_to_sleep);
	is_thinking(philo);
	
}

void	is_eating(t_philo *philo)
{
	if (stop_simu(philo) == true)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	printf("%s[%ld ms] : Philo %d is eating        🍝\n%s" \
		,GREEN, get_time(), philo->id, RESET);
	pthread_mutex_lock(&philo->time_lock);
	philo->time_start = get_time();
	pthread_mutex_unlock(&philo->time_lock);
	ft_usleep(philo->time_to_eat);
	if (philo->eat_count != -1)
		philo->eat_count++;
	reset_fork(philo);
	is_sleeping(philo);
}
