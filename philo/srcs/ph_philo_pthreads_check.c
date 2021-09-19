/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo_pthreads_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:03:27 by eboris            #+#    #+#             */
/*   Updated: 2021/09/18 09:39:04 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	*ph_philo_is_dead(void *phil)
{
	t_ph_phil	*philo;
	int			ph_time;

	philo = (t_ph_phil *)phil;
	ph_time = ph_gettime_ms(philo->ph_main);
	while (philo)
	{
		if (ph_time - philo->last_eat > philo->ph_main->time_die)
		{
			ph_philo_message(philo->ph_main, philo, 1);
			pthread_mutex_unlock(philo->status);
			return (NULL);
		}
		else if (philo->ph_main->num_time != -1 && philo->num_eats \
				>= philo->ph_main->num_time)
		{
			ph_usleep(philo->ph_main, philo->id);
			pthread_mutex_unlock(philo->meals);
			return (NULL);
		}
		ph_time = ph_gettime_ms(philo->ph_main);
	}
	return (NULL);
}

void	*ph_philo_num_time_full(void *phmain)
{
	t_phmain	*ph_main;
	int			i;

	ph_main = (t_phmain *)phmain;
	i = 1;
	if (ph_main->num_time != -1)
		pthread_mutex_lock(ph_main->phil_first->meals);
	while ((ph_main->num_time != -1) && (i <= ph_main->num_phil))
	{
		pthread_mutex_lock(ph_main->phil_first->meals);
		i++;
	}
	pthread_mutex_unlock(ph_main->phil_first->status);
	return (NULL);
}
