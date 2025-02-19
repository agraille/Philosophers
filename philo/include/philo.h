/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:03:40 by agraille          #+#    #+#             */
/*   Updated: 2025/02/19 16:04:34 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

# define PRINT_TAKE_FORK "Philo : %d take fork 🍴\n",philo->id

typedef enum e_status
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
}	t_status;

typedef struct s_philo
{
	int			id;
	int			time_to_eat;
	int			time_to_sleep;
	int			time_to_die;
	int			eat_count;
	int			eat_max;
	long int	time_start;
	int			fork;
	int			nbr_philo;
	int			tour;
	int			*left_fork;
	t_status	status;
}	t_philo;

typedef struct s_table
{
	unsigned short	nbr_philo;
	unsigned short	time_to_die;
	unsigned short	time_to_eat;
	unsigned short	time_to_sleep;
	unsigned short	eat_max;
	t_philo			*philo;
}	t_table;

int			ft_atoi(char *arg);
bool		parsing(char **argv);
bool		init_args(t_table *value, char **argv);
void		init_philo(t_table *table);
void		*start_routine(void *arg);
bool		create_threads(pthread_t *threads, t_table *table);
long int	get_time(void);
void		ft_usleep(int time_in_ms);
void		is_eating(t_philo *philo);

#endif
