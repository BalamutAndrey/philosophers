/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo_pthreads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:43:27 by eboris            #+#    #+#             */
/*   Updated: 2021/09/26 12:18:18 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	ph_philo_pthreads(t_phmain *ph_main)
{
	// t_ph_phil	*philo;
	// int			i;
	// ph_usleep(ph_main, 1000);
	ph_philo_pthread_create(ph_main);
	pthread_mutex_lock(ph_main->status);
	// i = 1;
	// philo = ph_main->phil_first;

	//

	// while (i <= ph_main->num_phil)
	// {
	// 	pthread_mutex_destroy(&philo->fork);
	// 	philo = philo->next;
	// 	i++;
	// }
	
	// pthread_mutex_destroy(&status);
	// pthread_mutex_destroy(&meals);
}

void	ph_philo_is_deads(t_ph_phil *philo)
{
	t_phmain	*ph_main;
	int			ph_time;

	ph_main = philo->ph_main;
	ph_time = ph_gettime_ms(ph_main);
	if (ph_time - philo->last_eat > ph_main->time_die)
	{
		// ph_usleep(ph_main, 9);
		printf("%d == %d - %d = %d (dead-time = %d) ==\n", philo->id, ph_time, philo->last_eat, ph_time - philo->last_eat, philo->ph_main->time_die);
		ph_philo_message(ph_main, philo, 1);
		pthread_mutex_unlock(ph_main->status);
	}

}

void	ph_philo_pthread_create(t_phmain *ph_main)
{
	int			i;
	t_ph_phil	*philo;
	// pthread_t	dead;
	// pthread_t	eats;

	i = 1;
	philo = ph_main->phil_first;
	while (i <= ph_main->num_phil)
	{
		if (philo->id % 2 == 1)
		{
			// pthread_create(&eats, NULL, ph_philo_num_time_full, philo->ph_main);
			// pthread_create(&dead, NULL, ph_philo_is_dead, philo);
			pthread_create(&philo->tid, NULL, ph_philo_one_philo, philo);
		}
		philo = philo->next;
		i++;
	}
	ph_usleep(ph_main, ph_main->time_eat / 2);
	i = 1;
	philo = ph_main->phil_first;
	while (i <= ph_main->num_phil)
	{
		if (philo->id % 2 == 0)
			pthread_create(&philo->tid, NULL, ph_philo_one_philo, philo);
		philo = philo->next;
		i++;
	}
}

void	*ph_philo_one_philo(void *phil)
{
	t_ph_phil	*philo;
	// pthread_t	dead;
	// pthread_t	eats;
	int			ph_time;

	philo = (t_ph_phil *)phil;
	// pthread_create(&eats, NULL, ph_philo_num_time_full, philo->ph_main);
	// pthread_create(&dead, NULL, ph_philo_is_dead, philo);
	ph_time = ph_gettime_ms(philo->ph_main);
	philo->last_eat = ph_time;
	while (philo->num_eats < philo->ph_main->num_time || philo->ph_main->num_time == -1)
	{
		ph_philo_is_deads(philo);
		pthread_mutex_lock(&philo->fork);
		ph_philo_message(philo->ph_main, philo, 2);
		ph_philo_is_deads(philo);
		pthread_mutex_lock(&philo->prev->fork);
		ph_philo_message(philo->ph_main, philo, 3);
		ph_philo_message(philo->ph_main, philo, 4);
		//
		printf("time = %d\n", ph_gettime_ms(philo->ph_main) - philo->last_eat);
		//
		philo->last_eat = ph_gettime_ms(philo->ph_main);
		ph_sleep(philo->ph_main, philo->last_eat, philo->ph_main->time_eat);
		ph_philo_is_deads(philo);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->prev->fork);
		philo->num_eats = philo->num_eats + 1;
		ph_philo_message(philo->ph_main, philo, 5);
		ph_sleep(philo->ph_main, (philo->last_eat + philo->ph_main->time_eat), philo->ph_main->time_sleep);
		ph_philo_is_deads(philo);
		ph_philo_message(philo->ph_main, philo, 6);
		ph_time = ph_gettime_ms(philo->ph_main);
	}
	philo->full_eats = 1;
	ph_usleep(philo->ph_main, 500);
	pthread_mutex_unlock(philo->ph_main->status);
	return (NULL);
}
