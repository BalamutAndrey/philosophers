/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:00:33 by eboris            #+#    #+#             */
/*   Updated: 2021/09/20 16:05:47 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_PHILO_H
# define PH_PHILO_H

/*
** ph_philo_fork_process.c
*/
void	ph_philo_fork_process(t_phmain *ph_main);
void	*ph_philo_one_philo(void *phil);
void	ph_philo_message(t_phmain *ph_main, t_ph_phil *philo, int message);

/*
** ph_philo_pthreads_check.c
*/
void	*ph_philo_is_dead(void *phil);
void	*ph_philo_num_time_full(void *phmain);
#endif
