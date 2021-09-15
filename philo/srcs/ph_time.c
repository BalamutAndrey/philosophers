/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:31:38 by eboris            #+#    #+#             */
/*   Updated: 2021/09/15 10:08:05 by eboris           ###   ########.fr       */
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

void		ph_usleep(t_phmain *ph_main, u_int64_t time)
{
	u_int64_t	finish_time;
	u_int64_t	curr_time;

	finish_time = ph_gettime_ms(ph_main) + time;
	curr_time = ph_gettime_ms(ph_main);
	while (curr_time < finish_time)
	{
		usleep(time);
		curr_time = ph_gettime_ms(ph_main);
	}
}

u_int64_t	ph_time_after_start(t_phmain *ph_main)
{
	u_int64_t	time;

	time = ph_gettime_ms(ph_main) - ph_main->time_start_prog;
	return(time);
}