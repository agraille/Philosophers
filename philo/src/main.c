/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:23:04 by agraille          #+#    #+#             */
/*   Updated: 2025/02/19 13:32:20 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	check_error(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		write(2, "Invalid number of arguments\n", 28);
		return (false);
	}
	if (parsing(argv) == false)
	{
		write(2, "Only digit arguments are accepted\n", 34);
		return(false);
	}
	return (true);
}

static void	wait(pthread_t *threads, t_table *table)
{
	int	i;
	
	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
	free(table->philo);
}

int	main(int argc, char **argv)
{
	t_table		table;
	pthread_t	*threads;
	
	if (check_error(argc, argv) == false)
		return (EXIT_FAILURE);
	if (init_args(&table, argv) == false)
		return (EXIT_FAILURE);
	table.philo = (t_philo *)malloc(sizeof(t_philo) * table.nbr_philo);
	if (!table.philo)
		return (EXIT_FAILURE);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * table.nbr_philo);
	if (!threads)
		return (free(table.philo), EXIT_FAILURE);
	init_philo(&table);
	if (create_threads(threads, &table) == false)
		return (-1);
	wait(threads, &table);
}
// valgrind --tool=helgrind ou valgrind --tool=drd 
