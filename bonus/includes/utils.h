/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:34:44 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/02 16:16:16 by lrondia          ###   ########.fr       */
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
t_pos	posi(double x, double y);
int		max_vert(char **map);
int		max_hor(char **map, int i);
int		is_north(double ray);
int		is_west(double ray);
int		is_map_letter(char c);

// raycasting

int		is_wall(t_game *game, int x, int y);
int		is_door(t_game *game, int x, int y);
int		is_outside_map(int x, int y, char **map);
int		is_same_tile(t_pos p1, t_pos p2);

//display

void	minimap_background(t_game *game);
void	little_square(t_game *game, int color, t_pos pos);
void	ft_draw_line(t_game *game, double angle, t_pos pos, int len);
int		is_in_screen(double x, double y);
int		is_near_evil(t_pos p, t_pos e, int dist);

void	bloc_transfer(t_img *src, t_img *dst, t_pos d, t_rect r);
t_rect	init_rect(int x, int y, int width, int height);

#endif
