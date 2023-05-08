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

int	check_philo_live(t_philo *pl)
{
	pthread_mutex_lock(pl->lock);
	if (*(pl->live) == 0)
	{
		pthread_mutex_unlock(pl->lock);
		return (0);
	}
	pthread_mutex_unlock(pl->lock);
	return (1);
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

int	philo_take_fork(t_philo *pl)
{
	while (1)
	{
		pthread_mutex_lock(pl->my_fork);
		if (pl->pms[pl->my_id] == 1)
		{
			pthread_mutex_lock(pl->next_fork);
			if (!print_doublemesage(pl, TAKE_FORK))
				return (place2fork(pl->my_fork, pl->next_fork));
			pl->pms[pl->my_id] = 0;
			return (1);
		}
		pthread_mutex_unlock(pl->my_fork);
		if (!check_starvation(pl))
			return (0);
		usleep(100);
	}
	return (0);
}

int	philo_eating(t_philo *pl)
{
	if (!print_mesage(pl, EATING))
		return (place2fork(pl->my_fork, pl->next_fork));
	pl->t_starve = pl->t_cur + pl->time->t_die;
	while (get_elapse_time() - pl->t_cur < pl->time->t_eat)
	{
		if (!check_starvation(pl))
			return (place2fork(pl->my_fork, pl->next_fork));
		usleep(100);
	}
	pl->pms[pl->next_id] = 1;
	place2fork(pl->my_fork, pl->next_fork);
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
	if (!print_mesage(pl, SLEEPING))
		return (0);
	while (get_elapse_time() - pl->t_cur < pl->time->t_slp)
	{
		if (!check_starvation(pl))
			return (0);
		usleep(100);
	}
	if (!print_mesage(pl, THINGKING))
		return (0);
	return (1);
}
