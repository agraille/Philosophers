/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:23:04 by agraille          #+#    #+#             */
/*   Updated: 2025/02/22 14:48:53 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

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

static void	start_monitor(t_table *table)
{
	int	i;
	int	j;
	int	all_dead;

	all_dead = 0;
	while (all_dead == 0)
	{
		i = 0;
		j = 0;
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
}
// valgrind --tool=helgrind ou valgrind --tool=drd 
