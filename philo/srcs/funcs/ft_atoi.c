/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:48:29 by eboris            #+#    #+#             */
/*   Updated: 2021/09/07 15:49:42 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_spaces(const char *str)
{
	char	*res;
	int		i;

	i = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v') ||
		(str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
		i++;
	if ((str[i] == '+') && (str[i + 1] >= '0') && (str[i + 1] <= '9'))
		i++;
	res = &((char *)str)[i];
	return (res);
}

int			ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;
	char	*nstr;

	i = 0;
	res = 0;
	sign = 1;
	nstr = ft_spaces(str);
	if (nstr[i] == '-' && nstr[i + 1] >= '0' && nstr[i + 1] <= '9')
	{
		sign = -1;
		i++;
	}
	while (nstr[i] >= '0' && nstr[i] <= '9')
	{
		if ((res * 10 + (nstr[i] - '0')) / 10 != res)
			return (sign == -1 ? 0 : -1);
		res = res * 10 + (nstr[i] - '0');
		i++;
	}
	return ((int)res * sign);
}