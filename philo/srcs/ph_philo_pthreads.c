/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo_pthreads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:43:27 by eboris            #+#    #+#             */
/*   Updated: 2021/09/15 10:14:32 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	ph_philo_pthreads(t_phmain *ph_main)
{
	;
}

void	*ph_philo_one_philo(void *ph_struct)
{
	t_phmain	*ph_main;
	pthread_t	philo_pthread;
	
	ph_main = (t_phmain *)ph_struct;
}

void	*ph_philo_is_dead(void *phil)
{
	t_ph_phil	*philo;
	u_int64_t	time;

	philo = (t_ph_phil *)phil;
	time = ph_gettime_ms(philo->ph_main);
	while (((time - philo->last_eat) < philo->ph_main->time_die) &&\
			(philo->ph_main->num_time) == -1 ||\
			(philo->num_eats < philo->ph_main->num_time))
	{
		if (time - philo->last_eat > philo->ph_main->time_die)
		{
			printf("%llu %d has died", ph_time_after_start(philo->ph_main),\
					philo->id);
			pthread_mutex_unlock(philo->status);
			return (NULL);
		}
		else if (philo->num_eats != -1 && philo->ph_main->num_time\
				>= philo->num_eats)
		{
			ft_usleep(philo->id); //float?
			pthread_mutex_unlock(philo->meals);
			return (NULL);
		}
		time = ph_gettime_ms(philo->ph_main);
	}
}
