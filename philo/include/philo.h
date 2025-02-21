/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:03:40 by agraille          #+#    #+#             */
/*   Updated: 2025/02/21 12:19:38 by agraille         ###   ########.fr       */
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

# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define RESET   "\033[0m"
# define PURPLE "\033[0;35m"

typedef struct s_philo
{
	int				id;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_count;
	int				eat_max;
	long int		time_start;
	int				stop;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	stop_lock;
	pthread_mutex_t	time_lock;
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
void		give_fork(t_philo *philo);
void		reset_fork(t_philo *philo);
void		destroy_mutex(t_table *table);
bool		create_mutex(t_table *table);
bool		stop_simu(t_philo *philo);

#endif
