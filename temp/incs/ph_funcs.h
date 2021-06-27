/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_funcs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:37:53 by eboris            #+#    #+#             */
/*   Updated: 2021/02/18 17:34:12 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_FUNCS_H
# define PH_FUNCS_H

/*
** ph_print.c
*/
void	ph_putchar_fd(char c, int fd);
void	ph_putstr_fd(char const *s, int fd);
void	ph_putnbr_fd(int n, int fd);

/*
** ph_malloc.c
*/
void	*ph_memalloc(size_t size);

#endif
