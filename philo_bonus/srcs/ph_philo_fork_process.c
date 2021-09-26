/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo_fork_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:07:07 by eboris            #+#    #+#             */
/*   Updated: 2021/09/21 10:31:24 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	ph_philo_fork_process(t_phmain *ph_main)
{
	t_ph_phil	*temp;
	int			i;

	i = 1;
	temp = ph_main->phil_first;
	while (i <= ph_main->num_phil)
	{
		temp->pid = fork();
		if (temp->pid == 0)
			ph_philo_one_philo(temp);
		i++;
		temp = temp->next;
	}
	waitpid(-1, NULL, 0);
	// printf("\n\n\n========\n\n\n");
		// i = 1;
		// temp = ph_main->phil_first;
		// while (i <= ph_main->num_phil)
		// {
		// 	kill(temp->pid, SIGTERM);
		// 	temp = temp->next;
		// 	i++;
		// }
}

void	*ph_philo_one_philo(void *phil)
{
	t_ph_phil	*philo;
	// pthread_t	tid_meat;
	// pthread_t	tid_dead;

	philo = (t_ph_phil *)phil;
	// if (philo->ph_main->num_time != -1)
	// 	pthread_create(&tid_meat, NULL, ph_philo_num_time_full, philo->ph_main);
	// pthread_create(&tid_dead, NULL, ph_philo_is_dead, philo);
	// if (philo->id % 2 == 0)
	// 	ph_usleep(philo->ph_main, (float)philo->ph_main->time_eat * 0.9 + 1);
	while (1)
	{
		ph_philo_is_dead(philo);
		ph_usleep(philo->ph_main, 4);
		if (((philo->ph_main->num_time != -1) && \
			(philo->num_eats < philo->ph_main->num_time)))
		{
			sem_wait(philo->ph_main->forks);
			ph_philo_message(philo->ph_main, philo, 2);
			// sem_wait???
			ph_philo_message(philo->ph_main, philo, 3);
			philo->last_eat = ph_gettime_ms(philo->ph_main);
			ph_philo_message(philo->ph_main, philo, 4);
			ph_usleep(philo->ph_main, philo->ph_main->time_eat);
			philo->num_eats = philo->num_eats + 1;
			sem_post(philo->ph_main->forks);
			ph_philo_message(philo->ph_main, philo, 5);
			ph_usleep(philo->ph_main, philo->ph_main->time_sleep);
			ph_philo_message(philo->ph_main, philo, 6);
		}
		else
			return (NULL);
	}
	return (NULL);
}

void	ph_philo_message(t_phmain *ph_main, t_ph_phil *philo, int message)
{
	int	ph_time;

	ph_time = ph_time_after_start(ph_main);
	if (message == 1)
	{
		printf("%d %d died\n", ph_time, philo->id);
	}	
	else if (message == 2)
		printf("%d %d has taken a fork\n", ph_time, philo->id);
	else if (message == 3)
		printf("%d %d has taken a fork\n", ph_time, philo->id);
	else if (message == 4)
		printf("%d %d is eating\n", ph_time, philo->id);
	else if (message == 5)
		printf("%d %d is sleeping\n", ph_time, philo->id);
	else if (message == 6)
		printf("%d %d is thinking\n", ph_time, philo->id);
}
