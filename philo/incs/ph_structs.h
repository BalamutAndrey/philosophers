/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:31:25 by eboris            #+#    #+#             */
/*   Updated: 2021/09/14 14:52:03 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_STRUCTS_H
# define PH_STRUCTS_H

typedef struct s_ph_phil t_ph_phil;
typedef struct s_phmain t_phmain;

typedef struct		s_ph_phil
{
	int				id;
	pthread_mutex_t	fork;
	pthread_mutex_t	*status;
	pthread_mutex_t	*meals;
	t_ph_phil		*prev;
	t_ph_phil		*next;
	u_int64_t		last_eat;
	int				num_eats;
	t_phmain		*ph_main;
}					t_ph_phil;

typedef struct	s_phmain
{
	int			num_phil;
	u_int64_t	time_die;
	u_int64_t	time_eat;
	u_int64_t	time_sleep;
	int			num_time;
	u_int64_t	time_think;
	u_int64_t	time_start_prog;
	t_ph_phil	*phil_first;
}				t_phmain;

/*
** ph_struct_add.c
*/
t_phmain	*ph_struct_add(int argc, char **argv);

/*
** ph_struct_add.c
*/
void	ph_struct_add_args(t_phmain *ph_main, int argc, char **argv);
int		ph_struct_add_check(t_phmain *ph_main, char *str, int param);

/*
** ph_struct_remove.c
*/
void	ph_struct_add_args(t_phmain *ph_main, int argc, char **argv);
void	ph_struct_args_error(t_phmain *ph_main, int error);

/*
** ph_struct_remove.c
*/
void 		ph_struct_remove(t_phmain **ph_main);

/*
** ph_struct_add_philo.c
*/
void	ph_struct_add_philo(t_phmain *ph_main);
t_ph_phil	*ph_struct_add_philo_phil(t_phmain *ph_main, int i);

#endif
