/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:59:15 by eboris            #+#    #+#             */
/*   Updated: 2021/09/07 16:58:15 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	ph_exit_print_error(int	error)
{
	if (error == 1)
		ph_exit_print_error_usage();
	else if (error == 2)
		printf("\x1b[31m \x1b[1m \n Philosophers: Malloc error!\x1b[0m\n");
	else
		printf("\x1b[31m \x1b[1m \n Philosophers: Unknown error!\x1b[0m\n");
}

void	ph_exit_print_error_usage(void)
{
	printf("\x1b[31m \x1b[1m \n Philosophers: Usage error!\x1b[0m\n\n");
	printf("\x1b[32m Usage: philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] \
\x1b[0m\n");
}