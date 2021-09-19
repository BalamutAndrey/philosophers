/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:54:23 by eboris            #+#    #+#             */
/*   Updated: 2021/09/07 15:05:19 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	*ph_memalloc(t_phmain *ph_main, size_t size)
{
	void	*res;

	if (size == 0)
		return (NULL);
	res = malloc(size);
	if (res == NULL)
		ph_exit(ph_main, 2);
	return (res);
}
