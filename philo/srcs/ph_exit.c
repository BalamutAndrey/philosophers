/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:12:59 by eboris            #+#    #+#             */
/*   Updated: 2021/09/07 15:26:07 by eboris           ###   ########.fr       */
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
	printf("\n\x1b[36m * * * * * * * * * * * * * * * *\x1b[0m\n");
	printf("\x1b[36m * Philosophers: Version 1.00. *\x1b[0m\n");
	printf("\x1b[36m * * * * * * * * * * * * * * * *\x1b[0m\n");
	exit(error);
}
