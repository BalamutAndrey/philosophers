/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:12:59 by eboris            #+#    #+#             */
/*   Updated: 2021/02/18 15:09:48 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	ph_exit(int	error)
{
	extern t_phmain	*ph_main;

	if (error != 0)
		ph_exit_print_error(error);
	ph_struct_remove(&ph_main);
	ph_putstr_fd("Philosophers: Version 1.00.\n", 1);
	exit(error);
}

void	ph_exit_print_error(int	error)
{
	if (error == 1)
	{
		ph_putstr_fd("Philosophers: Malloc error!\n", 2);
	}
}
