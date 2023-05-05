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
		args->pl[i].my_fork = &args->forks[i];
		if (i + 1 == args->philo_nb)
			args->pl[i].next_fork = &args->forks[0];
		else
			args->pl[i].next_fork = &args->forks[i + 1];
		args->pl[i].lock = args->lock;
		args->pl[i].time = &args->time;
		args->pl[i].pms = args->pms;
		args->pl[i].live = &args->live;
		args->pl[i].philo = i + 1;
		args->pl[i].my_id = i;
		if (i + 1 == args->philo_nb)
			args->pl[i].next_id = 0;
		else
			args->pl[i].next_id = i + 1;
		args->pl[i].meal = 0;
		i++;
	}
}

void	init_args(t_args *args)
{
	args->pl = allocate_philo(args->philo_nb);
	args->th = allocate_thread(args->philo_nb);
	args->forks = allocate_mutex(args->philo_nb);
	args->lock = allocate_mutex(1);
	args->pms = allocate_permission(args->philo_nb);
	if (!args->pl || !args->th || !args->forks || !args->lock || !args->pms)
		free_exit(args, 1);
	if (init_mutex(args->forks, args->philo_nb) != 1)
		free_exit(args, 2);
	if (init_mutex(args->lock, 1) != 1)
		free_exit(args, 2);
	init_philo(args);
}
