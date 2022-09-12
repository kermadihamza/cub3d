/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:34:44 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/12 19:32:29 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		is_personage(char c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
void	free_split(char **split);
int		ft_atoi(char *str);
int		ft_isdigit(int c);

#endif
