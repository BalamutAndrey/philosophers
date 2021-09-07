/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:05:32 by eboris            #+#    #+#             */
/*   Updated: 2021/09/07 15:07:12 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_MAIN_H
# define PH_MAIN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include "ph_structs.h"
# include "ph_funcs.h"

/*
** ph_main.c
*/
int		main(int argc, char **argv);

/*
** ph_exit.c
*/
void	ph_exit(t_phmain *ph_main, int error);

/*
** ph_errors.c
*/
void	ph_exit_print_error(int	error);
void	ph_exit_print_error_usage(void);

#endif
