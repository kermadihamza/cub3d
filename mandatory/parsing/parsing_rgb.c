/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:46:21 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/10 14:41:43 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_rgb(t_game *game, char *rgb, int *color)
{
	int		i;
	int		integer;
	char	**cpy;

	i = 0;
	cpy = ft_split(rgb, ',');
	while (cpy[i])
	{
		integer = ft_atoi(game, cpy[i]);
		if (integer < 0 || integer > 255)
			handle_errors(game, INCORR_RGB, cpy[i]);
		if (i == 0)
			*color += integer * 256 * 256;
		else if (i == 1)
			*color += integer * 256;
		else
			*color += integer;
		i++;
	}
	if (i != 3)
		handle_errors(game, INCORR_RGB, rgb);
	free_split(cpy);
}