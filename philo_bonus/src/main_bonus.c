/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:23:04 by agraille          #+#    #+#             */
/*   Updated: 2025/02/24 16:00:02 by agraille         ###   ########.fr       */
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

static void	wait_end(t_table *table)
{
	int		status;
	pid_t	dead_pid;
	int		i;

	i = 0;
	while (1)
	{
		dead_pid = waitpid(-1, &status, 0);
		if (WIFSIGNALED(status)) 
		{
			while (i < table->nbr_philo)
			{
				if (table->pid[i] != dead_pid && table->pid[i] > 0)
					kill(table->pid[i], SIGKILL);
				i++;
			}
			break ;
		}
	}
}

static bool	run_fork(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->nbr_philo)
	{
		table->pid[i] = fork();
		if (table->pid[i] == -1)
		{
			table->id = i + 1;
			close_semaphore_forks(table);
			close_semaphore_print(table);
			return (false);
		}
		if (table->pid[i] == 0)
			start_routine(table);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_table		table;

	if (check_error(argc, argv) == false)
		return (EXIT_FAILURE);
	if (init_args(&table, argv) == false)
		return (EXIT_FAILURE);
	if (init_semaphore(&table) == false)
		return (EXIT_FAILURE);
	if (run_fork(&table) == false)
		return (EXIT_FAILURE);
	wait_end(&table);
	close_semaphore_forks(&table);
	close_semaphore_print(&table);
}
