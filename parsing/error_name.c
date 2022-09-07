/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:30:28 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/07 15:34:21 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
