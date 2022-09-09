/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:43:52 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/09 16:11:52 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// static int	ft_handle_overflow(int res, int s)
// {
// 	if (res == INT_MIN)
// 		return (INT_MIN);
// 	if (s == 1)
// 		return (-1);
// 	else
// 		return (0);
// }

int	ft_atoi(const char *str)
{
	int			i;
	int			s;
	long long	res;

	i = 0;
	res = 0;
	s = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
		if (res < 0)
			handle_errors(INCORR_RGB, (char *)str);
			// return (ft_handle_overflow(res, s));
	}
	res *= s;
	return (res);
}
