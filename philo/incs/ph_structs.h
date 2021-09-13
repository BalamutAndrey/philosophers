/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:31:25 by eboris            #+#    #+#             */
/*   Updated: 2021/09/13 15:31:33 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_STRUCTS_H
# define PH_STRUCTS_H

typedef struct s_ph_phil
{
	;
}	t_ph_phil;

typedef struct s_phmain
{
	int			num_phil;
	u_int64_t	time_die;
	u_int64_t	time_eat;
	u_int64_t	time_sleep;
	int			num_time;
	u_int64_t	time_think;
}	t_phmain;

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

#endif
