/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:12:59 by eboris            #+#    #+#             */
/*   Updated: 2021/09/16 12:43:49 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	ph_exit(t_phmain *ph_main, int error)
{
	if (error != 0)
		ph_exit_print_error(error);
	if (ph_main != NULL)
		ph_struct_remove(&ph_main);
	exit(error);
}
