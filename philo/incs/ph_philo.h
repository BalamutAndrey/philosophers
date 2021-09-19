/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:00:33 by eboris            #+#    #+#             */
/*   Updated: 2021/09/16 16:04:21 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_PHILO_H
# define PH_PHILO_H

/*
** ph_philo_pthreads.c
*/
void	ph_philo_pthreads(t_phmain *ph_main);
void	ph_philo_pthread_create(t_phmain *ph_main, pthread_mutex_t *status, \
			pthread_mutex_t *meals, pthread_t *tid);
void	*ph_philo_one_philo(void *phil);
void	ph_philo_message(t_phmain *ph_main, t_ph_phil *philo, int message);

/*
** ph_philo_pthreads_check.c
*/
void	*ph_philo_is_dead(void *phil);
void	*ph_philo_num_time_full(void *phmain);
#endif
