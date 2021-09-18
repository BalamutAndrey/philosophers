/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:31:38 by eboris            #+#    #+#             */
/*   Updated: 2021/09/18 09:30:56 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

int	ph_gettime_ms(t_phmain *ph_main)
{
	struct timeval	curr;
	int				get_time_return;
	int				sec;
	int				usec;
	int				msec;

	get_time_return = gettimeofday(&curr, NULL);
	if (get_time_return != 0)
	{
		ph_exit(ph_main, 3);
	}
	sec = curr.tv_sec * 1000;
	usec = curr.tv_usec / 1000;
	msec = sec + usec;
	return (msec);
}

void	ph_usleep(t_phmain *ph_main, int time)
{
	int	finish_time;
	int	curr_time;

	finish_time = ph_gettime_ms(ph_main) + time;
	curr_time = ph_gettime_ms(ph_main);
	while (curr_time < finish_time)
	{
		usleep(time);
		curr_time = ph_gettime_ms(ph_main);
	}
}

int	ph_time_after_start(t_phmain *ph_main)
{
	int	ph_time;

	ph_time = ph_gettime_ms(ph_main) - ph_main->time_start_prog;
	return (ph_time);
}
