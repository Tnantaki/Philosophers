/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:31:45 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/31 12:31:46 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_digit(char *str)
{
	long long	nb;
	int			i;

	i = 0;
	nb = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9' && nb <= INT_MAX)
		nb = nb * 10 + (str[i++] - '0');
	if (nb > INT_MAX)
		return (0);
	if (i == 0)
		return (0);
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	check_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		prterr(0);
	if (is_digit(av[1]) != 1)
		prterr(1);
	if (is_digit(av[2]) != 1)
		prterr(2);
	if (is_digit(av[3]) != 1)
		prterr(3);
	if (is_digit(av[4]) != 1)
		prterr(4);
	if (ac == 6)
	{
		if (is_digit(av[5]) != 1)
			prterr(5);
	}
}

void	get_input(t_args *args, int ac, char **av)
{
	args->philo_nb = ft_atoi(av[1]);
	args->time.t_die = ft_atoi(av[2]) * 1000;
	args->time.t_eat = ft_atoi(av[3]) * 1000;
	args->time.t_slp = ft_atoi(av[4]) * 1000;
	if (args->philo_nb < 1)
		prterr(6);
	if (ac == 6)
	{
		args->time.max_meal = ft_atoi(av[5]);
		if (args->time.max_meal < 1)
			prterr(5);
	}
	else
		args->time.max_meal = 0;
	args->pl = NULL;
	args->th = NULL;
	args->mutex = NULL;
	args->lock = NULL;
	args->fork = NULL;
	args->live = 1;
}