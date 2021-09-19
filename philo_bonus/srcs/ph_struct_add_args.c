/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_struct_add_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:04:24 by eboris            #+#    #+#             */
/*   Updated: 2021/09/19 14:23:22 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	ph_struct_add_args(t_phmain *ph_main, int argc, char **argv)
{
	ph_main->num_phil = ph_struct_add_check(ph_main, argv[1], 1);
	ph_main->time_die = ph_struct_add_check(ph_main, argv[2], 2);
	ph_main->time_eat = ph_struct_add_check(ph_main, argv[3], 3);
	ph_main->time_sleep = ph_struct_add_check(ph_main, argv[4], 4);
	ph_main->num_time = -1;
	if (argc == 6)
		ph_main->num_time = ph_struct_add_check(ph_main, argv[5], 5);
	ph_main->time_think = ph_main->time_die - ph_main->time_eat
		- ph_main->time_sleep;
	if (ph_main->time_think < 0)
		ph_struct_args_error(ph_main, 6);
	ph_main->time_start_prog = ph_gettime_ms(ph_main);
	ph_main->forks = sem_open \
	("forks", O_CREAT, S_IRWXU, (ph_main->num_phil / 2));
	ph_main->meals = sem_open("meals", O_CREAT, S_IRWXU, 0);
}

int	ph_struct_add_check(t_phmain *ph_main, char *str, int param)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ph_struct_args_error(ph_main, param);
		i++;
	}
	i = ft_atoi(str);
	if (i <= 0)
		ph_struct_args_error(ph_main, param);
	return (i);
}
