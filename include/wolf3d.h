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
# define TEXT_W			64

# define ESC			53
# define Q				12

typedef struct 			s_var
{
	double				x;
	double				y;
}						t_var;

typedef struct	s_test
{
	int			t_num; // textures number
	float		wallx;
	int			t_x; 
	int			t_y;
}				t_test;

typedef struct	s_scene
{
	int			height;
	int			start;
	int			end;
	int			t_n;
}				t_scene;

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
	t_var				map;
	int 				map_x;
	int 				map_y;
	int 				step_x;
	int 				step_y;
	double				camera;
	double				perpwalldist;
	int					hit;
	int					hit_side;
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
	int 				color;
	t_player			player;
	t_textur			*texture;
	t_ray				ray;
	t_scene				scene;
	t_test				test;
	int 				line_height;
	int 				draw_start;
	int 				draw_end;
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
void	texture_n(t_env *wolf);

#endif