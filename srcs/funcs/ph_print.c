/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:34:11 by eboris            #+#    #+#             */
/*   Updated: 2021/02/18 14:37:01 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph_main.h"

void	ph_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ph_putstr_fd(char const *s, int fd)
{
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			ph_putchar_fd(s[i], fd);
			i++;
		}
	}
}

void	ph_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ph_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			n = n * -1;
			ph_putchar_fd('-', fd);
		}
		if (n > 9)
			ph_putnbr_fd(n / 10, fd);
		ph_putchar_fd(n % 10 + '0', fd);
	}
}
