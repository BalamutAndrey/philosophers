/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:31:38 by eboris            #+#    #+#             */
/*   Updated: 2021/09/25 16:59:21 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

int	ph_gettime_ms(t_phmain *ph_main)
{
	struct timeval	curr;
	int				msec;

	gettimeofday(&curr, NULL);
	if (curr.tv_usec == 0 && curr.tv_sec == 0)
	{
		ph_exit(ph_main, 3);
	}
	msec = (curr.tv_sec * 1000) + (curr.tv_usec / 1000);
	return (msec);
}

void	ph_usleep(t_phmain *ph_main, int time)
{
	int	finish_time;

	finish_time = ph_gettime_ms(ph_main) + time;
	while (ph_gettime_ms(ph_main) < finish_time)
	{
		usleep(1000);
	}
}

int	ph_time_after_start(t_phmain *ph_main)
{
	int	ph_time;

	ph_time = ph_gettime_ms(ph_main) - ph_main->time_start_prog;
	return (ph_time);
}
