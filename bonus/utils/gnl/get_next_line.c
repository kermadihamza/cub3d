/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:47:14 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/20 13:51:36 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*new_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof (char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}	
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	free (str);
	return (line);
}

void	new_buffer(char *str, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (!buffer)
		return ;
	while (str[i])
	{
		buffer[j] = str[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}

char	*read_line(int fd, char *line)
{
	int		nbytes;
	char	*temp;

	nbytes = BUFFER_SIZE;
	temp = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	temp[0] = '\0';
	if (!read_with_temp(&nbytes, &temp, fd, &line))
		return (NULL);
	if (nbytes == 0 && line[0] == '\0' && temp && line)
	{
		free (temp);
		free (line);
		return (NULL);
	}
	if (temp)
		free (temp);
	return (line);
}

int	read_with_temp(int *nbytes, char **temp, int fd, char **line)
{
	while (!ft_strchr(*line, '\n') && *nbytes == BUFFER_SIZE)
	{
		*nbytes = read(fd, *temp, BUFFER_SIZE);
		if (*nbytes == -1)
		{
			free (*line);
			free (*temp);
			return (0);
		}
		(*temp)[*nbytes] = '\0';
		*line = ft_strjoin(*line, *temp);
		if (!line)
			return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof (char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	line = ft_strjoin(line, buffer);
	if (!line)
		return (NULL);
	line = read_line(fd, line);
	if (!line)
		return (NULL);
	new_buffer(line, buffer);
	line = new_line(line);
	return (line);
}
