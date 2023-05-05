/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:32:25 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/31 12:32:27 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long long	nb;
	int			negative;
	int			i;

	i = 0;
	nb = 0;
	negative = 1;
	while ((str[i] && str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			negative = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	return (nb * negative);
}

void	prterr(int errnum)
{
	if (errnum == 0)
	{
		printf("\e[1;37mThe program take at least 4 argument.\e[0m\n");
		printf("1st arg: number of philosophers.\n");
		printf("2nd arg: time to die.\n");
		printf("3rd arg: time to eat.\n");
		printf("4th arg: time to sleep.\n");
		printf("5th arg[option]: Max meal of each philosopher.\n");
	}
	else if (errnum == 1)
		printf("Invalid number of philosophers.\n");
	else if (errnum == 2)
		printf("Invalid time to die.\n");
	else if (errnum == 3)
		printf("Invalid time to eat.\n");
	else if (errnum == 4)
		printf("Invalid time to sleep.\n");
	else if (errnum == 5)
		printf("Invalid number of times each philosopher must eat.\n");
	else if (errnum == 6)
		printf("The number of philosophers must have at least 1.\n");
	exit(0);
}

void	free_exit(t_args *args, int code)
{
	if (args->pl)
		free(args->pl);
	if (args->th)
		free(args->th);
	if (args->forks)
		free(args->forks);
	if (args->lock)
		free(args->lock);
	if (args->pms)
		free(args->pms);
	if (code == 0)
		exit(0);
	else if (code == 1)
		printf(ERR, "Error to malloc");
	else if (code == 2)
		printf(ERR, "Error to initialize mutex");
	else if (code == 3)
		printf(ERR, "Fail to create new thread");
	else if (code == 4)
		printf(ERR, "Fail to join thread");
	exit(1);
}
