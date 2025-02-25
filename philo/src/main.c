/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:23:04 by agraille          #+#    #+#             */
/*   Updated: 2025/02/25 10:18:46 by agraille         ###   ########.fr       */
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

static void	monitor_while(int *all_dead, t_table *table, int *j, int *i)
{
	while (*i < table->nbr_philo)
	{
		pthread_mutex_lock(&table->philo[*i].time_lock);
		if (get_time() - table->philo[*i].time_start >= table->time_to_die)
		{
			pthread_mutex_lock(&table->philo[*i].stop_lock);
			if (table->philo[*i].stop == 0)
			{
				pthread_mutex_lock(&table->print_lock);
				printf("%s[%ld ms] : Philo %d died            💀%s\n", \
					RED, get_time(), table->philo[*i].id, RESET);
				pthread_mutex_unlock(&table->print_lock);
				while (++(*j) < table->nbr_philo)
					table->philo[*j].stop = 1;
			}
			pthread_mutex_unlock(&table->philo[*i].stop_lock);
		}
		pthread_mutex_unlock(&table->philo[*i].time_lock);
		pthread_mutex_lock(&table->philo[*i].stop_lock);
		if (table->philo[*i].stop == 0)
			*all_dead = 0;
		pthread_mutex_unlock(&table->philo[*i].stop_lock);
		(*i)++;
	}
}

static void	start_monitor(t_table *table)
{
	int	i;
	int	j;
	int	all_dead;

	all_dead = 0;
	while (all_dead == 0)
	{
		i = 0;
		j = -1;
		all_dead = 1;
		monitor_while(&all_dead, table, &j, & i);
		ft_usleep(1);
	}
}

int	main(int argc, char **argv)
{
	t_table		table;
	pthread_t	*threads;

	if (check_error(argc, argv) == false)
		return (EXIT_FAILURE);
	if (init_args(&table, argv) == false)
		return (EXIT_FAILURE);
	table.philo = malloc(sizeof(t_philo) * table.nbr_philo);
	if (!table.philo)
		return (EXIT_FAILURE);
	if (create_mutex(&table) == false)
		return (EXIT_FAILURE);
	threads = malloc(sizeof(pthread_t) * table.nbr_philo);
	if (!threads)
	{
		destroy_mutex(&table);
		free(table.philo);
		return (EXIT_FAILURE);
	}
	init_philo(&table);
	if (create_threads(threads, &table) == false)
		return (EXIT_FAILURE);
	start_monitor(&table);
	clean(threads, &table);
}
