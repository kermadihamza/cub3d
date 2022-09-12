/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:09:03 by hakermad          #+#    #+#             */
/*   Updated: 2022/09/12 19:13:26 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_mlx_pixel_put(t_color *color, int x, int y, int num_color)
{
	char	*dst;

	dst = color->addr + (y * color->line_length + x * (color->bpp / 8));
	*(unsigned int *)dst = num_color;
}
