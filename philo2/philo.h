/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:35:39 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/31 12:35:40 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <limits.h>

# define BLACK	"\e[0;30m"
# define RED	"\e[0;31m"
# define GREEN	"\e[0;32m"
# define YELLOW	"\e[0;33m"
# define BLUE	"\e[0;34m"
# define PURPLE	"\e[0;35m"
# define CYAN	"\e[0;36m"
# define WHITE	"\e[0;37m"
# define RESET	"\e[0m"

# define TAKE_FORK	"\e[1;35m%lu ms %d has taken a fork\e[0m\n"
# define EATING		"\e[1;33m%lu ms %d is eating\e[0m\n"
# define SLEEPING	"\e[1;36m%lu ms %d is sleeping\e[0m\n"
# define THINGKING	"\e[1;32m%lu ms %d is thinking\e[0m\n"
# define DIED		"\e[1;31m%lu ms %d died\e[0m\n"
# define ERR		"\e[1;31m%s\e[0m\n"

typedef pthread_mutex_t	t_mutex;

typedef struct s_time
{
	long int	start;
	long int	t_die;
	long int	t_eat;
	long int	t_slp;
	int			max_meal;
}	t_time;

typedef struct s_philo
{
	t_mutex		*mutex1;
	t_mutex		*mutex2;
	t_mutex		*lock;
	t_time		*time;
	long int	t_starve;
	long int	t_cur;
	int			*fork1;
	int			*fork2;
	int			*live;
	int			philo;
	int			meal;
}	t_philo;

typedef struct s_args
{
	t_time		time;
	t_philo		*pl;
	pthread_t	*th;
	t_mutex		*mutex;
	t_mutex		*lock;
	int			*fork;
	int			live;
	int			philo_nb;
}	t_args;

//check_arguments
void		check_args(int ac, char **av);
void		get_input(t_args *args, int ac, char **av);
//allocate_argments
t_philo		*allocate_philo(int size);
pthread_t	*allocate_thread(int size);
t_mutex		*allocate_mutex(int size);
int			*allocate_fork(int size);
// int			*allocate_permission(int size);
//init argument
void		init_args(t_args *args);
//thread
void		create_thread(t_args *args);
void		join_thread(t_args *args);
void		destroy_mutex(t_args *args);
//routine
void		*routine(void *args);
int			check_starvation(t_philo *pl);
int			philo_take_fork(t_philo *pl, t_mutex *mutex, int *fork, int mode);
int			philo_eating(t_philo *pl);
int			philo_sleeping(t_philo *pl);
//utils
int			ft_atoi(const char *str);
long int	get_elapse_time(void);
int			print_mesage(t_philo *pl, char *str);
void		prterr(int errnum);
void		free_exit(t_args *args, int code);

#endif
