/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:30:28 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/12 14:27:39 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_rgb(char *rgb, int *color)
{
	int		i;
	int		integer;
	char	**cpy;

	i = 0;
	cpy = ft_split(rgb, ',');
	while (cpy[i])
	{
		integer = ft_atoi(cpy[i]);
		if (integer < 0 || integer > 255)
			handle_errors(INCORR_RGB, cpy[i]);
		if (i == 0)
			*color += integer * 256 * 256;
		else if (i == 1)
			*color += integer * 256;
		else
			*color += integer;
		i++;
	}
	if (i != 3)
		handle_errors(INCORR_RGB, rgb);
	free_split(cpy);
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
