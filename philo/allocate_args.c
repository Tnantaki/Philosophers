/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:31:36 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/31 12:31:40 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*allocate_philo(int size)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * size);
	if (!philo)
		return (NULL);
	return (philo);
}

pthread_t	*allocate_thread(int size)
{
	pthread_t	*th;

	th = malloc(sizeof(pthread_t) * size);
	if (!th)
		return (NULL);
	return (th);
}

pthread_mutex_t	*allocate_mutex(int size)
{
	pthread_mutex_t	*mutex;

	mutex = malloc(sizeof(pthread_mutex_t) * size);
	if (!mutex)
		return (NULL);
	return (mutex);
}

int	*allocate_permission(int size)
{
	int	i;
	int	*permission;

	permission = malloc(sizeof(int) * size);
	if (!permission)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (i % 2 == 0)
			permission[i] = 1;
		else
			permission[i] = 0;
		i++;
	}
	if (size % 2 != 0)
		permission[size - 1] = 0;
	return (permission);
}
