/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:34:41 by agraille          #+#    #+#             */
/*   Updated: 2025/02/19 16:32:02 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	give_fork(t_philo *philo)
{
	// voir pour gerer last et first philo impair
	if (philo->id % 2 != 0 && philo->tour % 2 != 0)
	{
		*philo->left_fork = false;
		printf(PRINT_TAKE_FORK);
	}
	else if (philo->id % 2 == 0 && philo->tour % 2 == 0)
	{
		*philo->left_fork = false;
		printf(PRINT_TAKE_FORK);
	}
	philo->tour++;
}

void	*start_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	give_fork(philo);
	is_eating(philo);
	return (NULL);
}
