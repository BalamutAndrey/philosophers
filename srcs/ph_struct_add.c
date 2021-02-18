/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_struct_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:44:31 by eboris            #+#    #+#             */
/*   Updated: 2021/02/18 15:04:50 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

t_phmain	*ph_struct_add(void)
{
	t_phmain	*ph_main;

	ph_main = (t_phmain *)ph_memalloc(sizeof (t_phmain));
	return (ph_main);
}
