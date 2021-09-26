/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo_pthreads_message.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:04:48 by eboris            #+#    #+#             */
/*   Updated: 2021/09/25 17:26:43 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	ph_philo_message(t_phmain *ph_main, t_ph_phil *philo, int message)
{
	int	ph_time;

	ph_time = ph_time_after_start(ph_main);
	if (message == 1)
	{
		printf("\x1b[31m%d %d died\x1b[0m\n", (ph_time - 0), philo->id);
	}	
	else if (message == 2)
		printf("\x1b[34m%d %d has taken a fork\x1b[0m\n", ph_time, philo->id);
	else if (message == 3)
		printf("\x1b[36m%d %d has taken a fork\x1b[0m\n", ph_time, philo->id);
	else if (message == 4)
		printf("\x1b[32m%d %d is eating\x1b[0m\n", ph_time, philo->id);
	else if (message == 5)
		printf("\x1b[33m%d %d is sleeping\x1b[0m\n", ph_time, philo->id);
	else if (message == 6)
		printf("\x1b[35m%d %d is thinking\x1b[0m\n", ph_time, philo->id);
}
