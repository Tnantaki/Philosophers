/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:32:16 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/31 12:32:17 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_elapse_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int	print_mesage(t_philo *pl, char *str)
{
	pthread_mutex_lock(pl->lock);
	if (*(pl->live) == 1)
	{
		pl->t_cur = get_elapse_time();
		printf(str, (pl->t_cur - pl->time->start) / 1000, pl->philo);
		pthread_mutex_unlock(pl->lock);
		return (1);
	}
	pthread_mutex_unlock(pl->lock);
	return (0);
}

int	print_doublemesage(t_philo *pl, char *str)
{
	pthread_mutex_lock(pl->lock);
	if (*(pl->live) == 1)
	{
		pl->t_cur = get_elapse_time();
		printf(str, (pl->t_cur - pl->time->start) / 1000, pl->philo);
		printf(str, (pl->t_cur - pl->time->start) / 1000, pl->philo);
		pthread_mutex_unlock(pl->lock);
		return (1);
	}
	pthread_mutex_unlock(pl->lock);
	return (0);
}
