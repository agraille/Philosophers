/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:03:40 by agraille          #+#    #+#             */
/*   Updated: 2025/02/24 21:41:59 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>

# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define RESET   "\033[0m"
# define PURPLE "\033[0;35m"

typedef struct s_table
{
	unsigned short	nbr_philo;
	unsigned short	id;
	unsigned short	time_to_die;
	unsigned short	time_to_eat;
	unsigned short	time_to_sleep;
	long int		time_start;
	int				eat_count;
	unsigned short	eat_max;
	char			sem_name[200];
	pid_t			pid[200];
	sem_t			*forks;
	sem_t			*print;
}	t_table;

int			ft_atoi(char *arg);
bool		parsing(char **argv);
bool		init_args(t_table *value, char **argv);
void		init_philo(t_table *table);
void		*start_routine(void *arg);
long int	get_time(void);
void		ft_usleep(int time_in_ms);
bool		init_semaphore(t_table *table);
void		close_semaphore_forks(t_table *table);
void		close_semaphore_print(t_table *table);
void		is_eating(t_table *table);
void		stop_simu(t_table *table);

#endif
