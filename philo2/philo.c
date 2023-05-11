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

	check_args(ac, av);
	get_input(&args, ac, av);
	init_args(&args);
	create_thread(&args);
	join_thread(&args);
	destroy_mutex(&args);
	free_exit(&args, 0);
}
