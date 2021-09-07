/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:31:25 by eboris            #+#    #+#             */
/*   Updated: 2021/09/07 16:54:14 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_STRUCTS_H
# define PH_STRUCTS_H

typedef struct s_phmain
{
	int	num_phil;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	num_time;
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
void	ph_struct_args_error(t_phmain *ph_main, int error);

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
