/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:09:38 by vzamyati          #+#    #+#             */
/*   Updated: 2018/07/03 14:09:41 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	WOLF3D_H
# define	WOLF3D_H

# include "./libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define W_HEIGHT		800
# define W_WIDTH 		800

# define ESC			53
# define Q				12

typedef struct 			s_var
{
	double				x;
	double				y;
}						t_var;

typedef struct 			s_textur
{
	void				*ptr;
	void				*data;
	int 				bpp;
	int 				sizeline;
	int 				endian;
	int 				width;
	int 				height;
}						t_textur;

typedef struct 			s_player
{
	double				s_move;
	double				s_turn;
	double				s_shift;
	int 				up;
	int 				down;
	int 				left;
	int 				right;
	int 				shift;
	t_var 				position;
	t_var				direct;
	t_var				plane;
}						t_player;

typedef struct 			s_ray
{
	t_var				position;
	t_var				direct;
	t_var				delta;
	t_var				side;
	int 				map_x;
	int 				map_y;
	int 				step_x;
	int 				step_y;
	float				camera;
	float				dist;
	int					hit;
	int					hit_side;
}						t_ray;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	void				*data;
	int 				bpp;
	int 				sizeline;
	int 				endian;
	int 				**map;
	int 				m_height;
	int 				m_width;
	int 				ceil;
	int 				floor;
	t_player			player;
	t_textur			*texture;
	t_ray				rayc;
}						t_env;

int			f_exit(t_env *wolf);
int			key_events(int key, t_env *wolf);
void		delete_env(t_env **wolf);
t_env		*init_env(void);
void		ft_error(char *reason);
void		make_map2(char *line, int **map, int i, t_env *wolf);
void		make_map(int fd, t_env *wolf);
void		read_map_data(int fd, t_env *wolf);
void 		open_file(char *line, t_env *wolf);
t_player	init_player(void);
void		texture(t_env *wolf);
void		raycasting(t_env *wolf);
void		calculate_ray(t_env *wolf, int x);
void		step(t_env *wolf);

#endif