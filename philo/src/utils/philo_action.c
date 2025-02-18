/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:14:47 by agraille          #+#    #+#             */
/*   Updated: 2025/02/18 10:29:26 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	is_eating(t_philo *philo)
{
	philo->time_start= get_time();
	printf("Je suis le philo numero %d, TIME = %ld \n", philo->id, philo->time_start);
	ft_usleep(philo->time_to_eat);
	printf("Je suis le philo numero %d, DEAD = %ld \n", philo->id,  get_time());

}

// void	is_sleeping(t_philo *philo)
// {
		
// }

// void	is_thinking(t_philo *philo)
// {
		
// }
