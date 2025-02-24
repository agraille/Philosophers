/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:05:33 by agraille          #+#    #+#             */
/*   Updated: 2025/02/24 15:08:35 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

void	close_semaphore_print(t_table *table)
{
		sem_close(table->print);
		sem_unlink("/print");
}

void	close_semaphore_forks(t_table *table)
{
		sem_close(table->forks);
		sem_unlink("/forks");
}

bool	init_semaphore(t_table *table)
{
	table->forks = sem_open("/forks", O_CREAT | O_EXCL, 0644, table->nbr_philo);
	if (table->forks == SEM_FAILED)
		return (false);
	table->print = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);
	if (table->forks == SEM_FAILED)
	{
		close_semaphore_forks(table);
		return (false);
	}
	return (true);
}
