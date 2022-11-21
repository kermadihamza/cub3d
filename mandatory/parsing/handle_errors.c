/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:15:48 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/21 11:57:21 by hakermad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_file_arg_error(int error, char *str)
{
	if (error == NB_ARGUMENTS)
		write(2, "Error.\nWrong number of arguments.\n", 35);
	else if (error == WRONG_NAME)
	{
		write (2, "Error.\nWrong file name : ", 25);
		write (2, str, ft_strlen(str));
		write (2, "\nChange it now.\n", 16);
	}
}

void	handle_syntax_error(int error, char *str)
{	
	if (error == INCORR_RGB)
	{
		write(2, "Error.\nRGB format is incorrect : ", 33);
		write (2, str, ft_strlen(str));
		write (2, "\nChange it now.\n", 16);
	}
	else if (error == SYNTAX_ERR)
	{
		write(2, "Error.\nSyntax error in the file : ", 34);
		write (2, str, ft_strlen(str));
		write (2, "\nChange it now.\n", 16);
	}
	else if (error == SPRITE_ERR)
	{	
		write(2, "Error.\nThis file does not exist/is corrupted :\n", 47);
		write (2, str, ft_strlen(str));
		write (2, "\nChange it.\n", 12);
	}
}

void	handle_map_error(int error, char *str)
{	
	if (error == NB_ELEMENTS)
		write(2,
			"Error.\nThere is too few or too many character(s). Fix it.\n", 58);
	else if (error == OTHER_CHAR)
	{
		write(2, "Error.\nIncorrect character in the map : ", 40);
		write (2, &str[0], 1);
		write (2, "\nFix it now.\n", 13);
	}
	else if (error == OPEN_WALL)
	{	
		write(2, "Error.\nA wall of the map is open :\n", 35);
		write (2, str, ft_strlen(str));
		write (2, "\nClose it.\n", 11);
	}
	else if (error == UNEXIST_MAP)
		write(2, "Error.\nThis map does not exit. Change it now.\n", 46);
}

void	handle_parse_error(int error)
{
	if (error == PARSE)
		write(2, "Need NO/SO/WE/EA and F/C color.\n", 32);
}

void	handle_errors(t_game *game, int error, char *str)
{
	handle_parse_error(error);
	handle_map_error(error, str);
	handle_syntax_error(error, str);
	handle_file_arg_error(error, str);
	ft_destroy_all(game);
}
