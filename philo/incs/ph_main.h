/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:05:32 by eboris            #+#    #+#             */
/*   Updated: 2021/09/16 11:51:31 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_MAIN_H
# define PH_MAIN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "ph_structs.h"
# include "ph_funcs.h"
# include "ph_philo.h"

/*
** ph_main.c
*/
int			main(int argc, char **argv);

/*
** ph_exit.c
*/
void		ph_exit(t_phmain *ph_main, int error);

/*
** ph_errors.c
*/
void		ph_exit_print_error(int error);
void		ph_exit_print_error_usage(void);
void		ph_struct_args_error(t_phmain *ph_main, int error);

/*
** ph_time.c
*/
u_int64_t	ph_gettime_ms(t_phmain *ph_main);
void		ph_usleep(t_phmain *ph_main, u_int64_t time);
u_int64_t	ph_time_after_start(t_phmain *ph_main);

#endif
