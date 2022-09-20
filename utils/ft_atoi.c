/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:43:52 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/20 13:51:10 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !(str[i] >= 9 && str[i] <= 13)
			&& str[i] != 32 && str[i] != '+')
			handle_errors(INCORR_RGB, (char *)str);
		i++;
	}
}

int	ft_atoi(char *str)
{
	int			i;
	int			s;
	long long	res;

	i = 0;
	res = 0;
	s = 1;
	check_only_digit(str);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
		if (res < 0)
			handle_errors(INCORR_RGB, (char *)str);
	}
	res *= s;
	return (res);
}
