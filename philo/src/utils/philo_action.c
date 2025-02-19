/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:14:47 by agraille          #+#    #+#             */
/*   Updated: 2025/02/19 14:59:21 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// void	is_sleeping(t_philo *philo)
// {
	
// }

// void	is_thinking(t_philo *philo)
// {
	
// }

void	is_eating(t_philo *philo)
{
	// if (philo->FORK == false)
	// 	is_thinking(philo);
	philo->time_start= get_time();
	// printf("Je suis le philo numero %d, TIME = %ld \n", philo->id, philo->time_start);
	ft_usleep(philo->time_to_eat);
	printf("Je suis le philo numero %d, DEAD = %ld , FORK = %d \n",\
		 philo->id,  get_time(), philo->fork);
	philo->eat_count++;
	// if (philo->eat_count == philo->eat_max)
		//close le thread
	// is_sleeping(philo);
}

