/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:30:28 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/09 16:39:04 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_devide(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 15)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_itoh(unsigned long int nb)
{
	int		i;
	int		devide;
	char	*base;
	char	*res;

	i = 0;
	devide = ft_devide(nb);
	base = "0123456789abcdef";
	res = malloc(sizeof(char) * devide + 1);
	if (!res)
		handle_errors(MALLOC_F, 0);
	if (i == 0)
	{
		res[0] = '0';
		res[1] = 'x';
		i = 2;
	}
	else
	{
		if (nb >= 16)
		{
			ft_itoh(nb / 16);
			ft_itoh(nb % 16);
		}
		else
		{
			res[i] = base[nb];
			i++;
		}
	}
	return (res);
}

void	error_rgb(char *rgb)
{
	int		i;
	int		integer;
	char	**cpy;
	char	*tmp;

	i = 0;
	cpy = ft_split(rgb, ',');
	while (cpy[i])
	{
		integer = ft_atoi(cpy[i]);
		if (integer < 0 || integer > 255)
			handle_errors(INCORR_RGB, rgb);
		tmp = ft_itoh(integer);
		rgb = ft_strjoin(rgb, tmp);
		free (tmp);
		i++;
	}
	rgb[ft_strlen(rgb) + 1] = '\0';
	free_split(cpy);
	// printf("rgb = %s\n", rgb);
}

void	check_error_name(char *av)
{
	int		i;
	int		j;
	char	end[5];

	i = ft_strlen(av) - 1;
	j = 0;
	while (j < 4 && i > 0)
	{
		end[j] = av[i];
		i--;
		j++;
	}
	end[j] = '\0';
	if (!ft_strcmp(end, "buc."))
		handle_errors(WRONG_NAME, av);
}
