/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:34:44 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/13 18:08:17 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	add_new_pos(t_pos *pos, double x, double y);
int		is_personage(char c);
int		ft_destroy_all(t_game *game);

int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
void	free_split(char **split);
int		ft_atoi(t_game *game, char *str);
int		ft_isdigit(int c);
t_pos	find_pos(char *map, int i);
int		max_vert(char **map);
int		max_hor(char **map, int i);
char	is_north(double ray);
char	is_west(double ray);

// raycasting

int		is_wall(t_game *game, int x, int y);
void	calcul_ray_len(t_ray *ray, t_pos player, t_pos *pos, double *len);
int		is_hor_closer(t_game *game, t_ray *ray);
void	set_final_pos(t_game *game, t_ray *ray);
int		is_outside_map(int x, int y, char **map);

//display

int		is_inside_map(t_game *game, int x, int y);
void	minimap_background(t_game *game);
void	little_square(t_game *game, int color, t_pos pos);
void	ft_draw_line(t_game *game, double angle, t_pos pos, int len);
int		is_in_screen(double x, double y);

#endif
