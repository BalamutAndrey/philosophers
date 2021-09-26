/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_struct_add_philo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:19:42 by eboris            #+#    #+#             */
/*   Updated: 2021/09/20 10:39:06 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	ph_struct_add_philo(t_phmain *ph_main)
{
	int				i;
	t_ph_phil		*curr;
	t_ph_phil		*temp;

	i = 1;
	ph_main->phil_first = ph_struct_add_philo_phil(ph_main, i);
	curr = ph_main->phil_first;
	while ((++i) <= ph_main->num_phil)
	{
		temp = curr;
		curr = ph_struct_add_philo_phil(ph_main, i);
		curr->prev = temp;
		temp->next = curr;
	}
	ph_main->phil_first->prev = curr;
	curr->next = ph_main->phil_first;
}

t_ph_phil	*ph_struct_add_philo_phil(t_phmain *ph_main, int i)
{
	t_ph_phil	*new;

	new = ph_memalloc(ph_main, sizeof(t_ph_phil));
	new->id = i;
	new->pid = -1;
	new->prev = NULL;
	new->next = NULL;
	new->last_eat = ph_main->time_start_prog;
	new->num_eats = 0;
	new->ph_main = ph_main;
	return (new);
}
