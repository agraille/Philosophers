/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:55:36 by agraille          #+#    #+#             */
/*   Updated: 2025/02/21 00:05:09 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	create_threads(pthread_t *threads, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		if (pthread_create(&threads[i], NULL, start_routine, \
			(void *)&table->philo[i]) != 0)
		{
			while (--i >= 0)
				pthread_join(threads[i], NULL);
			destroy_mutex(table);
			free(threads);
			free(table->philo);
			write(2, "Threads init fail", 17);
			return (false);
		}
		i++;
	}
	return (true);
}
