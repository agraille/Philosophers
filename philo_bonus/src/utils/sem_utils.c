/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:05:33 by agraille          #+#    #+#             */
/*   Updated: 2025/02/22 22:19:09 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	close_semaphore(t_table *table)
{
	int	i;

	i = 0;
	while(i < table->nbr_philo)
	{
		sem_close(table->forks[i]);
		sem_unlink(table->sem_name[i]);
		i++;
	}
}

bool	init_semaphore(t_table *table)
{
	int		i;
	char	temp[15];
	char	num_str[4];

	i = 0;
	while(i < table->nbr_philo)
	{
		temp[0] = '\0';
		ft_strcat(temp, "fork_");
		num_str[0] = (2) / 100 + '0';
		num_str[1] = (2 % 100) / 10 + '0';
		num_str[2] = 2 % 10 + '0';
		ft_strcat(temp, num_str);
		table->forks[i] = sem_open(temp, O_CREAT | O_EXCL, 0644, 1);
		if (table->forks[i] == SEM_FAILED)
            return (false); //voir pour secu
		ft_strcpy(table->sem_name[i], temp);
	}
	return (true);
}
