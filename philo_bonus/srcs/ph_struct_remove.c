/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_struct_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:08:21 by eboris            #+#    #+#             */
/*   Updated: 2021/09/20 11:21:26 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	ph_struct_remove(t_phmain **phmain)
{
	t_phmain	*ph_main;

	ph_main = *phmain;
	ph_struct_remove_kill_fork(ph_main);
	free(ph_main);
	*phmain = NULL;
}

void	ph_struct_remove_kill_fork(t_phmain *ph_main)
{
	t_ph_phil	*temp;
	int			i;

	i = 1;
	if ((ph_main != NULL) && (ph_main->num_phil != 0) && \
		(ph_main->phil_first != NULL))
	{
		temp = ph_main->phil_first;
		while (i <= ph_main->num_phil)
		{
			if (temp->pid > 0)
			{
				kill(temp->pid, SIGTERM);
			}
			i++;
			temp = temp->next;
		}
	}
}