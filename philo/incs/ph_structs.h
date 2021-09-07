/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:31:25 by eboris            #+#    #+#             */
/*   Updated: 2021/02/20 08:17:47 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_STRUCTS_H
# define PH_STRUCTS_H

typedef struct s_phmain
{
	int	i;
}	t_phmain;

/*
** ph_struct_add.c
*/
t_phmain		*ph_struct_add(void);

/*
** ph_struct_remove.c
*/
void			ph_struct_remove(void);

#endif
