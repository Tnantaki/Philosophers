/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:31:52 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/31 12:31:53 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(pthread_mutex_t *mutex, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pthread_mutex_init(&mutex[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	init_philo(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philo_nb)
	{
		args->pl[i].mutex1 = &args->mutex[i];
		args->pl[i].fork1 = &args->fork[i];
		if (i + 1 == args->philo_nb)
		{
			args->pl[i].mutex2 = &args->mutex[0];
			args->pl[i].fork2 = &args->fork[0];
		}
		else
		{
			args->pl[i].mutex2 = &args->mutex[i + 1];
			args->pl[i].fork2 = &args->fork[i + 1];
		}
		args->pl[i].lock = args->lock;
		args->pl[i].time = &args->time;
		args->pl[i].live = &args->live;
		args->pl[i].philo = i + 1;
		args->pl[i].meal = 0;
		i++;
	}
}

void	init_args(t_args *args)
{
	args->pl = allocate_philo(args->philo_nb);
	args->th = allocate_thread(args->philo_nb);
	args->mutex = allocate_mutex(args->philo_nb);
	args->lock = allocate_mutex(1);
	args->fork = allocate_fork(args->philo_nb);
	if (!args->pl || !args->th || !args->mutex || !args->lock || !args->fork)
		free_exit(args, 1);
	if (init_mutex(args->mutex, args->philo_nb) != 1)
		free_exit(args, 2);
	if (init_mutex(args->lock, 1) != 1)
		free_exit(args, 2);
	init_philo(args);
}
