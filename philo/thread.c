/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:32:09 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/31 12:32:11 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(void *args)
{
	t_philo	*pl;

	pl = (t_philo *)args;
	pl->t_starve = pl->time->start + pl->time->t_die;
	while (1)
	{
		pl->t_cur = get_elapse_time();
		printf(TAKE_FORK, (pl->t_cur - pl->time->start) / 1000, pl->philo);
		while (1)
		{
			if (!check_starvation(pl))
				return (0);
			usleep(50);
		}
	}
	return (NULL);
}

int	create_thread(t_args *args)
{
	int	i;

	i = 0;
	args->time.start = get_elapse_time();
	if (args->philo_nb == 1)
	{
		if (pthread_create(&args->th[i], NULL, &one_philo, &args->pl[i]) != 0)
			return (destroy_mutex(args), free_args(args, 3), 0);
		return (1);
	}
	while (i < args->philo_nb)
	{
		if (pthread_create(&args->th[i], NULL, &routine, &args->pl[i]) != 0)
			return (destroy_mutex(args), free_args(args, 3), 0);
		i += 2;
		if (i >= args->philo_nb && i % 2 == 0)
			i = 1;
	}
	return (1);
}

int	join_thread(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philo_nb)
	{
		if (pthread_join(args->th[i], NULL) != 0)
			return (destroy_mutex(args), free_args(args, 4), 0);
		i++;
	}
	return (1);
}

void	destroy_mutex(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philo_nb)
	{
		pthread_mutex_destroy(&args->mutex[i]);
		i++;
	}
	pthread_mutex_destroy(args->lock);
}
