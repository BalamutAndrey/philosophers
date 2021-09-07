/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_struct_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:44:31 by eboris            #+#    #+#             */
/*   Updated: 2021/09/07 16:53:37 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

t_phmain	*ph_struct_add(int argc, char **argv)
{
	t_phmain	*ph_main;

	ph_main = (t_phmain *)ph_memalloc(NULL, sizeof (t_phmain));
	if (ph_main == NULL)
		ph_exit(NULL, 1);
	// ph_main->num_phil = ft_atoi(argv[1]);
	// ph_main->time_die = ft_atoi(argv[2]);
	// ph_main->time_eat = ft_atoi(argv[3]);
	// ph_main->time_sleep = ft_atoi(argv[4]);
	// ph_main->num_time = -1;
	// if ((argc == 6) && (ft_atoi(argv[5]) > 0))
	// 	ph_main->num_time = ft_atoi(argv[5]);
	ph_struct_add_args(ph_main, argc, argv);
	return (ph_main);
}
