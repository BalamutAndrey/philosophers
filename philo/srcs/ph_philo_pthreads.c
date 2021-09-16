/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo_pthreads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:43:27 by eboris            #+#    #+#             */
/*   Updated: 2021/09/16 15:03:03 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	ph_philo_pthreads(t_phmain *ph_main)
{
	t_ph_phil		*philo;
	pthread_mutex_t	status;
	pthread_mutex_t	meals;
	pthread_t		tid;
	int				i;

	pthread_mutex_init(&status, NULL);
	pthread_mutex_init(&meals, NULL);
	pthread_mutex_lock(&status);
	i = 1;
	philo = ph_main->phil_first;
	while (i <= ph_main->num_phil)
	{
		philo->status = &status;
		philo->meals = &meals;
		pthread_create(&tid, NULL, ph_philo_one_philo, philo);
		philo = philo->next;
		i++;
	}
	if (ph_main->num_time != -1)
		pthread_create(&tid, NULL, ph_philo_num_time_full, ph_main);
	pthread_mutex_lock(&status);
	i = 1;
	philo = ph_main->phil_first;
	while (i <= ph_main->num_phil)
	{
		pthread_mutex_destroy(&philo->fork);
		philo = philo->next;
		i++;
	}
	pthread_mutex_destroy(&status);
	pthread_mutex_destroy(&meals);
}

void	*ph_philo_one_philo(void *phil)
{
	t_ph_phil	*philo;
	pthread_t	thread;

	philo = (t_ph_phil *)phil;
	pthread_create(&thread, NULL, ph_philo_is_dead, philo);
	if (philo->id % 2 == 0)
	{
		ph_usleep(philo->ph_main, (float)philo->ph_main->time_eat * 0.9 + 1);
	}
	while (philo->ph_main->num_time == -1 || philo->ph_main->num_time > \
			philo->num_eats)
	{
		pthread_mutex_lock(&philo->fork);
		ph_philo_message(philo->ph_main, philo, 2);
		pthread_mutex_lock(&philo->prev->fork);
		ph_philo_message(philo->ph_main, philo, 3);
		philo->last_eat = ph_gettime_ms(philo->ph_main);
		ph_philo_message(philo->ph_main, philo, 4);
		ph_usleep(philo->ph_main, philo->ph_main->time_eat);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->prev->fork);
		philo->num_eats = philo->num_eats + 1;
		ph_philo_message(philo->ph_main, philo, 5);
		ph_usleep(philo->ph_main, philo->ph_main->time_sleep);
		ph_philo_message(philo->ph_main, philo, 6);
	}
	return (NULL);
}

void	*ph_philo_is_dead(void *phil)
{
	t_ph_phil	*philo;
	u_int64_t	time;

	philo = (t_ph_phil *)phil;
	time = ph_gettime_ms(philo->ph_main);
	while (((time - philo->last_eat) <= philo->ph_main->time_die) || \
			((philo->ph_main->num_time) == -1 || \
			(philo->num_eats < philo->ph_main->num_time)))
	{
		if (time - philo->last_eat > philo->ph_main->time_die)
		{
			ph_philo_message(philo->ph_main, philo, 1);
			pthread_mutex_unlock(philo->status);
			return (NULL);
		}
		else if (philo->num_eats != -1 && philo->num_eats \
				>= philo->ph_main->num_time)
		{
			ph_usleep(philo->ph_main, philo->id); //float?
			pthread_mutex_unlock(philo->meals);
			return (NULL);
		}
		time = ph_gettime_ms(philo->ph_main);
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
	printf("%llu %d Nazhralsya\n", ph_time_after_start(ph_main), ph_main->phil_first->id);
	pthread_mutex_unlock(ph_main->phil_first->status);
	return (NULL);
}

void	ph_philo_message(t_phmain *ph_main, t_ph_phil *philo, int message)
{
	u_int64_t	time;

	time = ph_time_after_start(ph_main);
	if (message == 1)
	{
		printf("%llu %d died\n", time, philo->id);
	}
	else if (message == 2)
	{
		printf("%llu %d has taken a fork\n", time, philo->id);
	}
	else if (message == 3)
	{
		printf("%llu %d has taken a fork\n", time, philo->id);
	}
	else if (message == 4)
	{
		printf("%llu %d is eating\n", time, philo->id);
	}
	else if (message == 5)
	{
		printf("%llu %d is sleeping\n", time, philo->id);
	}
	else if (message == 6)
	{
		printf("%llu %d is thinking\n", time, philo->id);
	}
}
