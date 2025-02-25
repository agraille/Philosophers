/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:14:47 by agraille          #+#    #+#             */
/*   Updated: 2025/02/25 09:26:59 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static void	is_thinking(t_table *table)
{
	ft_usleep(1);
	stop_simu(table);
	sem_wait(table->print);
	printf("%s[%ld ms] : Philo %d is thinking      💭\n%s" \
		, YELLOW, get_time(), table->id, RESET);
	sem_post(table->print);
}

static void	is_sleeping(t_table *table)
{
	stop_simu(table);
	sem_wait(table->print);
	printf("%s[%ld ms] : Philo %d is sleeping      🛌\n%s" \
		, BLUE, get_time(), table->id, RESET);
	sem_post(table->print);
	ft_usleep(table->time_to_sleep);
	if (table->time_to_sleep < table->time_to_eat)
		ft_usleep(table->time_to_eat - table->time_to_sleep);
	is_thinking(table);
}

void	is_eating(t_table *table)
{
	stop_simu(table);
	sem_wait(table->print);
	printf("%s[%ld ms] : Philo %d is eating        🍝\n%s" \
		, GREEN, get_time(), table->id, RESET);
	sem_post(table->print);
	table->time_start = get_time();
	ft_usleep(table->time_to_eat);
	sem_post(table->forks);
	sem_post(table->forks);
	if (table->eat_count != -1)
		table->eat_count++;
	is_sleeping(table);
}
