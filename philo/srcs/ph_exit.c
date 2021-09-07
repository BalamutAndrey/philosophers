/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:12:59 by eboris            #+#    #+#             */
/*   Updated: 2021/09/07 14:49:05 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	ph_exit(t_phmain *ph_main, int error)
{
	if (error != 0)
		ph_exit_print_error(error);
	if (ph_main != NULL)
		ph_struct_remove(&ph_main);
	ph_main = NULL;
	printf("\nPhilosophers: Version 1.00.\n");
	exit(error);
}

void	ph_exit_print_error(int	error)
{
	if (error == 1)
		printf("Philosophers: Malloc error!\n");
	else
		printf("Philosophers: Unknown error!\n");
}
