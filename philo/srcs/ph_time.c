/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:31:38 by eboris            #+#    #+#             */
/*   Updated: 2021/09/14 10:40:27 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

u_int64_t	ph_gettime_ms(t_phmain *ph_main)
{
	struct timeval	curr;
	int				get_time_return;
	u_int64_t		sec;
	u_int64_t		usec;
	u_int64_t		msec;

	get_time_return = gettimeofday(&curr, NULL);
	if (get_time_return != 0)
	{
		ph_exit(ph_main, 3);
	}
	sec = curr.tv_sec * 1000;
	usec = curr.tv_usec / 1000;
	msec = curr.tv_sec * 1000 + curr.tv_usec / 1000;
	return (msec);
}
