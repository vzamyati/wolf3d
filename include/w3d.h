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

#ifndef		WOLF3D_H
# define	WOLF3D_H

# include "../libft/include/libft.h"
# include "../../minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>

# define W_HEIGHT		900
# define W_WIDTH 		900
# define TEXTURE_WIDTH	64
# define TEXTURE_HEIGHT	64

# define ESC			53

# define Q				12
# define W				13
# define S				1
# define A				0
# define D				2

# define SHIFT1			257
# define SHIFT2			258

# define ARR_UP			126
# define ARR_DOWN		125
# define ARR_LEFT		123
# define ARR_RIGHT		124
# define NEXT			47
# define PREV			43
# define OFF			31
# define RESTART		15
# define INFO 			34

typedef struct 			s_var
{
	double				x;
	double				y;
}						t_var;

typedef struct 			s_flag
{
	int 				info;
	int 				music;
	int 				up;
	int 				down;
	int 				left;
	int 				right;
	int 				shift;
}						t_flag;

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
	t_flag				flag;
	float				s_move;
	float				s_rot;
	float				s_shift;
	double				time;
	double				oldtime;
	double				frametime;
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
	float				camera;
	float				pwd;
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
	double				floorxwall;
	double				floorywall;
	double				dist_wall;
	double				dist_player;
	int 				floor_texx;
	int 				floor_texy;
	int 				x;
	int 				y;
	int 				d;
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
	int 				fps;
	char				*speed;
	t_player			player;
	t_textur			*texture;
	t_ray				rayc;
	t_flag				flag;
}						t_env;

int			f_exit(t_env *wolf);
int			key_press(int key, t_env *wolf);
void		delete_env(t_env **wolf);
t_env		*init_env(void);
void		init_img(t_env *wolf);
void		ft_error(char *reason);
void 		open_file(char *line, t_env *wolf);
void		init_player(t_env *wolf);
void		load_textures(t_env *wolf);
void		raycasting(t_env *wolf);
void		get_texture(t_env *wolf);
void		lets_draw_walls(t_env *wolf, int x, int start, int end);
void		draw(t_env *wolf);
int 		expose(t_env *wolf);
int			game_loop(t_env *wolf);
int			key_release(int key, t_env *wolf);
void		draw(t_env *wolf);
void		key_up(t_env *wolf);
void		key_down(t_env *wolf);
void		key_left(t_env *wolf);
void		key_right(t_env *wolf);
void		cross(t_env *wolf);
void		show_info(t_env *wolf);
void		place_player(t_env *wolf);
void		change_music(int key, t_env *wolf);
void		fps(t_env *wolf);
int			get_position(t_env *wolf, int x, int y);
void		lets_draw_floor(t_env *w);

#endif