/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:04:00 by eboris            #+#    #+#             */
/*   Updated: 2021/09/25 11:59:07 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

int	main(int argc, char **argv)
{
	t_phmain		*ph_main;
	pthread_mutex_t	status;
	pthread_mutex_t	meals;
	t_ph_phil		*temp;
	int				i;

	// int z = 0;
	// while (++z < 100)
	// {
	if (argc < 5 || argc > 6)
		ph_exit(NULL, 1);
	ph_main = ph_struct_add(argc, argv);
	i = 1;
	temp = ph_main->phil_first;
	pthread_mutex_init(&status, NULL);
	pthread_mutex_init(&meals, NULL);
	ph_main->status = &status;
	ph_main->meals = &meals;
	pthread_mutex_lock(ph_main->status);
	pthread_mutex_lock(ph_main->meals);
	ph_philo_pthreads(ph_main);
	// }
	ph_exit(ph_main, 0);
	return (0);
}
