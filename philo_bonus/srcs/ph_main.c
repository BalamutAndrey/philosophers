/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:04:00 by eboris            #+#    #+#             */
/*   Updated: 2021/09/20 11:50:40 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

int	main(int argc, char **argv)
{
	t_phmain		*ph_main;

	if (argc < 5 || argc > 6)
		ph_exit(NULL, 1);
	ph_main = ph_struct_add(argc, argv);
	ph_philo_fork_process(ph_main);
	sem_close(ph_main->forks);
	sem_close(ph_main->meals);
	sem_unlink("forks");
	sem_unlink("meals");
	ph_exit(ph_main, 0);
	return (0);
}
