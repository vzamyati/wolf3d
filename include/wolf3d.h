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

# include "../libft/include/libft.h"
# include "../../minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define W_HEIGHT		800
# define W_WIDTH 		800
# define TEXTURE_WIDTH	64

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
	char				*data;
	int 				bpp;
	int 				sizeline;
	int 				endian;
	int 				width;
	int 				height;
}						t_textur;

typedef struct 			s_player
{
	t_var 				pos;
	t_var				dirt;
	t_var				plane;
	double				s_move;
	double				s_turn;
	double				s_shift;
	int 				up;
	int 				down;
	int 				left;
	int 				right;
	int 				shift;
}						t_player;

typedef struct 			s_ray
{
	t_var				pos;
	t_var				dirt;
	t_var				delta;
	t_var				side;
	t_var				map;
	int 				map_x;
	int 				map_y;
	int 				step_x;
	int 				step_y;
	double				camera;
	double				pwd;
	int					hit;
	int					hit_side;
	int					height;
	int					start;
	int					end;
	int					texture_nb;
	int					t_num;
	float				wall_x;
	int					texture_x; 
	int					texture_y;
}						t_ray;


typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int 				bpp;
	int 				sizeline;
	int 				endian;
	int 				**map;
	int 				map_height;
	int 				map_width;
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
void		make_map(int fd, t_env *wolf);
void		read_map_data(int fd, t_env *wolf);
void 		open_file(char *line, t_env *wolf);
t_player	init_player(void);
void		textures(t_env *wolf);
void		raycasting(t_env *wolf);
void		get_texture(t_env *wolf);
void		lets_draw(t_env *wolf, int x, int start, int end);

#endif