/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:04:00 by eboris            #+#    #+#             */
/*   Updated: 2021/09/07 17:01:27 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

int	main(int argc, char **argv)
{
	t_phmain	*ph_main;

	if (argc < 5 || argc > 6)
		ph_exit(NULL, 1);
	ph_main = ph_struct_add(argc, argv);
	//
	printf("1 = %i\n2 = %i\n3 = %i\n4 = %i\n5 = %i\n", ph_main->num_phil, ph_main->time_die, ph_main->time_eat, ph_main->time_sleep, ph_main->num_time);
	//
	ph_exit(ph_main, 0);
	return (0);
}
