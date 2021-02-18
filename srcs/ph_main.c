/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:04:00 by eboris            #+#    #+#             */
/*   Updated: 2021/02/18 15:10:41 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

t_phmain	*ph_main;

int	main(int argc, char **argv)
{
	extern t_phmain	*ph_main;

	ph_main = ph_struct_add();
	(void)argc;
	(void)argv;
	ph_exit(0);
	return (0);
}
