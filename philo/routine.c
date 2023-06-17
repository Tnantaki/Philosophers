/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:32:04 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/31 12:32:05 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_philo	*pl;

	pl = (t_philo *)args;
	pl->t_starve = pl->time->start + pl->time->t_die;
	while (check_starvation(pl))
	{
		if (!philo_take_fork(pl, pl->mutex1, pl->fork1, 1))
			break ;
		if (!philo_take_fork(pl, pl->mutex2, pl->fork2, 0))
			break ;
		if (!philo_eating(pl))
			break ;
		if (!philo_sleeping(pl))
			break ;
	}
	return (NULL);
}

int	check_starvation(t_philo *pl)
{
	if (pl->t_starve < get_elapse_time())
	{
		pthread_mutex_lock(pl->lock);
		if (*(pl->live) == 0)
		{
			pthread_mutex_unlock(pl->lock);
			return (0);
		}
		else
			*(pl->live) = 0;
		pthread_mutex_unlock(pl->lock);
		pl->t_cur = get_elapse_time();
		printf(DIED, (pl->t_cur - pl->time->start) / 1000, pl->philo);
		return (0);
	}
	return (1);
}

int	philo_take_fork(t_philo *pl, t_mutex *mutex, int *fork, int mode)
{
	while (check_starvation(pl))
	{
		pthread_mutex_lock(mutex);
		if (*fork == mode)
		{
			pthread_mutex_unlock(mutex);
			if (!print_message(pl, TAKE_FORK))
				return (0);
			return (1);
		}
		pthread_mutex_unlock(mutex);
		usleep(50);
	}
	return (0);
}

int	philo_eating(t_philo *pl)
{
	if (!print_message(pl, EATING))
		return (0);
	pl->t_starve = pl->t_cur + pl->time->t_die;
	while (get_elapse_time() - pl->t_cur < pl->time->t_eat)
	{
		if (!check_starvation(pl))
			return (0);
		usleep(50);
	}
	pthread_mutex_lock(pl->mutex1);
	pthread_mutex_lock(pl->mutex2);
	*(pl->fork1) = 0;
	*(pl->fork2) = 1;
	pthread_mutex_unlock(pl->mutex1);
	pthread_mutex_unlock(pl->mutex2);
	if (pl->time->max_meal)
	{
		pl->meal += 1;
		if (pl->meal >= pl->time->max_meal)
			return (0);
	}
	return (1);
}

int	philo_sleeping(t_philo *pl)
{
	if (!print_message(pl, SLEEPING))
		return (0);
	while (get_elapse_time() - pl->t_cur < pl->time->t_slp)
	{
		if (!check_starvation(pl))
			return (0);
		usleep(50);
	}
	if (!print_message(pl, THINGKING))
		return (0);
	return (1);
}
