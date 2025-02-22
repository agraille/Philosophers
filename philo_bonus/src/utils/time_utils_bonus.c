/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:57:42 by agraille          #+#    #+#             */
/*   Updated: 2025/02/22 14:46:14 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

long int	get_time(void)
{
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	return ((cur_time.tv_sec * 1000) + (cur_time.tv_usec / 1000));
}

void	ft_usleep(int time_in_ms)
{
	long int	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
		usleep(1000);
}
