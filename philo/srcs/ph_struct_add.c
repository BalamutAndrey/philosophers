/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_struct_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:44:31 by eboris            #+#    #+#             */
/*   Updated: 2021/09/14 10:37:55 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

t_phmain	*ph_struct_add(int argc, char **argv)
{
	t_phmain	*ph_main;

	ph_main = (t_phmain *)ph_memalloc(NULL, sizeof (t_phmain));
	if (ph_main == NULL)
		ph_exit(NULL, 1);
	ph_struct_add_args(ph_main, argc, argv);
	ph_struct_add_philo(ph_main);
	return (ph_main);
}
