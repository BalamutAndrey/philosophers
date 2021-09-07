/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_struct_add_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:04:24 by eboris            #+#    #+#             */
/*   Updated: 2021/09/07 16:58:43 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	ph_struct_add_args(t_phmain *ph_main, int argc, char **argv)
{
	ph_main->num_phil = ph_struct_add_check(ph_main, argv[1], 1);
	ph_main->time_die = ph_struct_add_check(ph_main, argv[2], 2);
	ph_main->time_eat = ph_struct_add_check(ph_main, argv[3], 3);
	ph_main->time_sleep = ph_struct_add_check(ph_main, argv[4], 4);
	if (argc == 6)
		ph_main->num_time = ph_struct_add_check(ph_main, argv[5], 5);
	else
		ph_main->num_time = -1;
}

int		ph_struct_add_check(t_phmain *ph_main, char *str, int param)
{
	int	i;

	i = ft_atoi(str);
	if (i <= 0)
		ph_struct_args_error(ph_main, param);
	return (i);
}

void	ph_struct_args_error(t_phmain *ph_main, int error)
{
	if (error  == 1)
		printf("\x1b[31m \x1b[1m \n Number of philosophers <= 0!\x1b[0m\n");
	else if (error  == 2)
		printf("\x1b[31m \x1b[1m \n Time to die <= 0!\x1b[0m\n");
	else if (error  == 3)
		printf("\x1b[31m \x1b[1m \n Time_to_eat <= 0!\x1b[0m\n");
	else if (error  == 4)
		printf("\x1b[31m \x1b[1m \n Time to sleep <= 0!\x1b[0m\n");
	else if (error  == 5)
		printf("\x1b[31m \x1b[1m \n Number of times each philosopher must eat \
<= 0!\x1b[0m\n");
	ph_exit(ph_main, 1);
}