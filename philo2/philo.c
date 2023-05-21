/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:31:58 by tnantaki          #+#    #+#             */
/*   Updated: 2023/03/31 12:31:59 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args	args;

	if (!check_args(ac, av))
		return (1);
	if (!get_input(&args, ac, av))
		return (1);
	if (!init_args(&args))
		return (1);
	if (!create_thread(&args))
		return (1);
	if (!join_thread(&args))
		return (1);
	destroy_mutex(&args);
	free_args(&args, 0);
	return (0);
}
