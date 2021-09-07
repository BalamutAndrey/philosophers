/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_struct_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:44:31 by eboris            #+#    #+#             */
/*   Updated: 2021/09/07 14:49:23 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

t_phmain	*ph_struct_add(void)
{
	t_phmain	*ph_main;

	ph_main = (t_phmain *)ph_memalloc(NULL, sizeof (t_phmain));
	if (ph_main == NULL)
		ph_exit(NULL, 1);
	return (ph_main);
}
