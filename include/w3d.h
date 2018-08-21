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

#ifndef W3D_H
# define W3D_H

# include "../libft/include/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include <signal.h>

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
# define WEAPON 		14
# define TEXTURE		49

typedef struct	s_var
{
	double		x;
	double		y;
}				t_var;

typedef struct	s_flag
{
	int			info;
	int			music;
	int			up;
	int			down;
	int			left;
	int			right;
	int			shift;
	int			weapon;
	int			texture;
}				t_flag;

typedef struct	s_textur
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	int			width;
	int			height;
}				t_textur;

typedef struct	s_player
{
	t_var		pos;
	t_var		dirt;
	t_var		plane;
	t_flag		flag;
	float		s_move;
	float		s_rot;
	float		s_shift;
	double		time;
	double		oldtime;
	double		frametime;
}				t_player;

typedef struct	s_ray
{
	t_var		pos;
	t_var		dirt;
	t_var		delta;
	t_var		side;
	t_var		map;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	float		camera;
	float		pwd;
	int			hit;
	int			hit_side;
	int			height;
	int			start;
	int			end;
	int			texture_nb;
	int			t_num;
	float		wall_x;
	int			texture_x;
	int			texture_y;
	double		floorxwall;
	double		floorywall;
	double		dist_wall;
	double		dist_player;
	int			floor_texx;
	int			floor_texy;
	int			x;
	int			y;
	int			d;
}				t_ray;

typedef struct	s_weapon
{
	void		*shotgun;
	int			width;
	int			height;
	t_textur	*shots;
}				t_weapon;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	int			**map;
	int			map_height;
	int			map_width;
	int			ceil;
	int			floor;
	int			fps;
	char		*speed;
	t_player	player;
	t_textur	*texture;
	t_ray		rayc;
	t_flag		flag;
	t_weapon	weapon;
}				t_env;

/*
** adds.c
*/
void			cross(t_env *w);
void			show_info(t_env *w);
void			change_music(int key, t_env *w);
void			fps(t_env *w);
/*
** clean.c
*/
void			delete_env(t_env **w);
int				f_exit(t_env *w);
void			ft_error(char *reason);
/*
** draw.c
*/
void			lets_draw_walls(t_env *w, int x, int texture_nb);
void			lets_draw_compas(t_env *w, int x);
void			draw(t_env *w);
void			shoot(t_env *w);
/*
** events.c
*/
int				game_loop(t_env *w);
int				mouse_hook(int key, int x, int y, t_env *w);
int				key_press(int key, t_env *w);
int				key_release(int key, t_env *w);
/*
** floor_ceil.c
*/
void			lets_draw_floor(t_env *w);
void			lets_draw_floor2(t_env *w);
void			put_ceil(t_env *w);
void			put_floor(t_env *w);
/*
** map.c
*/
void			make_map(char *av, int i, t_env *w);
void			check_value(t_env *w, int i, int j);
void			validate_map2(t_env *w);
int				check_position(t_env *w);
void			validate_map1(char *buf, int i, t_env *w);
/*
** moves.c
*/
void			key_up(t_env *w);
void			key_down(t_env *w);
void			key_left(t_env *w);
void			key_right(t_env *w);
/*
** player.c
*/
void			init_player(t_env *w);
void			place_player(t_env *w);
int				get_position(t_env *w, int x, int y);
/*
** raycasting.c
*/
void			raycasting(t_env *w);
void			ray_step(t_env *w);
void			ray_dist(t_env *w);
void			ray_draw(t_env *w);
void			set_texture(t_env *w);
/*
** texture.c
*/
void			get_texture(t_env *w);
void			load_textures(t_env *w);
void			load_textures2(t_env *w);

#endif
