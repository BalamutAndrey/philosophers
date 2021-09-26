/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo_pthreads_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:03:27 by eboris            #+#    #+#             */
/*   Updated: 2021/09/25 18:57:55 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	*ph_philo_is_dead(void *phil)
{
	t_phmain	*ph_main;
	t_ph_phil	*philo;
	int			ph_time;

	philo = (t_ph_phil *)phil;
	ph_main = philo->ph_main;
	ph_time = ph_gettime_ms(ph_main);
	while (philo->status == 0 && philo->full_eats == 0)
	{
		if (ph_time - philo->last_eat > ph_main->time_die)
		{
			// ph_usleep(ph_main, 9);
			printf("%d == %d - %d = %d (dead-time = %d) ==\n", philo->id, ph_time, philo->last_eat, ph_time - philo->last_eat, philo->ph_main->time_die);
			ph_philo_message(ph_main, philo, 1);
			pthread_mutex_unlock(ph_main->status);
			return (NULL);
		}
		ph_time = ph_gettime_ms(ph_main);
	}
	return (NULL);
}

// void	*ph_philo_num_time_full(void *phmain)
// {
// 	t_phmain	*ph_main;
// 	t_ph_phil	*philo;
// 	int			i;

// 	ph_main = (t_phmain *)phmain;
// 	while (1)
// 	{
// 		i = 1;
// 		philo = ph_main->phil_first;
// 		while (i <= ph_main->num_phil)
// 		{
// 			if (philo->full_eats == 0 && philo->num_eats < philo->ph_main->num_time)
// 				break ;
// 			else if (philo->full_eats == 0)
// 			{
// 				philo->full_eats = 1;
// 				// pthread_mutex_unlock(&philo->fork);
// 				// pthread_mutex_unlock(&philo->prev->fork);
// 			}
// 			i++;
// 			philo = philo->next;
// 		}
// 		if (i > ph_main->num_phil)
// 		{
// 			ph_usleep(ph_main, ph_main->time_die);
// 			pthread_mutex_unlock(ph_main->status);
// 			return (NULL);
// 		}
// 	}
// 	return (NULL);
// }

// void	*ph_philo_is_dead(void *phil)
// {
// 	t_ph_phil	*philo;
// 	int			ph_time;

// 	philo = (t_ph_phil *)phil;
// 	ph_time = ph_gettime_ms(philo->ph_main);
// 	ph_usleep(philo->ph_main, philo->ph_main->time_eat);
// 	while (philo)
// 	{
// 		if (ph_time - philo->last_eat > philo->ph_main->time_die)
// 		{
// 			ph_philo_message(philo->ph_main, philo, 1);
// 			pthread_mutex_unlock(philo->status);
// 			return (NULL);
// 		}
// 		else if (philo->ph_main->num_time != -1 && philo->num_eats \
// 				>= philo->ph_main->num_time)
// 		{
// 			ph_usleep(philo->ph_main, philo->id);
// 			pthread_mutex_unlock(philo->meals);
// 			printf("%d %d * * * Нажрались!!! * * * \n", ph_time_after_start(philo->ph_main), philo->id);
// 			return (NULL);
// 		}
// 		ph_time = ph_gettime_ms(philo->ph_main);
// 		ph_usleep(philo->ph_main, philo->ph_main->time_eat);
// 	}
// 	return (NULL);
// }

// void	*ph_philo_num_time_full(void *phmain)
// {
// 	t_phmain	*ph_main;
// 	int			i;

// 	ph_main = (t_phmain *)phmain;
// 	i = 1;
// 	if (ph_main->num_time != -1)
// 		pthread_mutex_lock(ph_main->phil_first->meals);
// 	while ((ph_main->num_time != -1) && (i <= ph_main->num_phil))
// 	{
// 		pthread_mutex_lock(ph_main->phil_first->meals);
// 		i++;
// 	}
// 	pthread_mutex_unlock(ph_main->phil_first->status);
// 	return (NULL);
// }
