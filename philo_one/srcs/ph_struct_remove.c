/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_struct_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:08:21 by eboris            #+#    #+#             */
/*   Updated: 2021/02/20 07:57:48 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	ph_struct_remove(void)
{
	extern t_phmain	*g_ph_main;

	free(g_ph_main);
	g_ph_main = NULL;
}
