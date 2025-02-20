/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:23:04 by agraille          #+#    #+#             */
/*   Updated: 2025/02/20 13:34:27 by agraille         ###   ########.fr       */
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
		return (false);
	}
	return (true);
}

static void	clean(pthread_t *threads, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
	destroy_mutex(table);
	free(table->philo);
}

// static void	start_monitor(t_table *table)
// {
// 	int	i;

// 	while (1)
// 	{
// 		i = 0;
// 		while (i < table->nbr_philo)
// 		{
// 			pthread_mutex_lock(&table->philo[i].time_lock);
// 			if (get_time() - table->philo[i].time_start >= table->time_to_die)
// 			{
// 				printf("%ld %d is die\n",  get_time(), table->philo[i].id);
// 				pthread_mutex_unlock(&table->philo[i].time_lock);
// 				break ;
// 			}
// 			pthread_mutex_unlock(&table->philo[i].time_lock);
// 		}
// 		if (i < table->nbr_philo)
// 			break ;
// 		usleep(40000);
// 	}
// 	i = 0;
// 	while (i < table->nbr_philo)
// 	{
// 		pthread_mutex_lock(&table->philo[i].stop_lock);
// 		table->philo[i].stop = 1;
// 		pthread_mutex_unlock(&table->philo[i].stop_lock);
// 		i++;
// 	}
// }

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
	if (create_mutex(&table) == false)
		exit(EXIT_FAILURE);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * table.nbr_philo);
	if (!threads)
	{
		destroy_mutex(&table);
		free(table.philo);
		exit(EXIT_FAILURE);
	}
	init_philo(&table);
	if (create_threads(threads, &table) == false)
		exit(EXIT_FAILURE);
	// start_monitor(&table);
	clean(threads, &table);
}
// valgrind --tool=helgrind ou valgrind --tool=drd 
