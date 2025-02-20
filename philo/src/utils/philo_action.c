/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:14:47 by agraille          #+#    #+#             */
/*   Updated: 2025/02/20 13:42:21 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	is_thinking(t_philo *philo)
{
	if (stop_simu(philo) == true)
		return ;
	// printf("[%ld ms] : Philo %d is thinking      💭\n",  get_time(), philo->id);
	printf("%ld %d is thinking\n",  get_time(), philo->id);
	ft_usleep(1);
}

static void	is_sleeping(t_philo *philo)
{
	if (stop_simu(philo) == true)
		return ;
	// printf("[%ld ms] : Philo %d is sleeping      🛌\n", get_time(), philo->id);
	printf("%ld %d is sleeping\n",  get_time(), philo->id);
	ft_usleep(philo->time_to_sleep);
	is_thinking(philo);
	
}

void	is_eating(t_philo *philo)
{
	if (stop_simu(philo) == true)
		return ;
	// printf("[%ld ms] : Philo %d is eating        🍝\n", get_time(), philo->id);
	printf("%ld %d is eating\n",  get_time(), philo->id);
	ft_usleep(philo->time_to_eat);
	philo->eat_count++;
	reset_fork(philo);
	is_sleeping(philo);
}
