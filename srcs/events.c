/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:25:57 by vzamyati          #+#    #+#             */
/*   Updated: 2018/07/06 16:25:58 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			f_exit(t_env *wolf)
{
	if (wolf != NULL)
		mlx_destroy_window(wolf->mlx, wolf->win);
	exit(0);
	return (0);
}

void		key_up(t_env *wolf)
{
	if (wolf->player.shift)
	{
		if (wolf->map[(int)(wolf->player.pos.x + wolf->player.dirt.x *
		wolf->player.s_shift)][(int)wolf->player.pos.y] == 0)
			wolf->player.pos.x += wolf->player.dirt.x * wolf->player.s_shift;
		if (wolf->map[(int)wolf->player.pos.x][(int)(wolf->player.pos.y +
		wolf->player.dirt.y * wolf->player.s_shift)] == 0)
			wolf->player.pos.y += wolf->player.dirt.y * wolf->player.s_shift;
	}
	else
	{
		if (wolf->map[(int)(wolf->player.pos.x + wolf->player.dirt.x *
		wolf->player.s_move)][(int)wolf->player.pos.y] == 0)
			wolf->player.pos.x += wolf->player.dirt.x * wolf->player.s_move;
		if (wolf->map[(int)wolf->player.pos.x][(int)(wolf->player.pos.y +
		wolf->player.dirt.y * wolf->player.s_move)] == 0)
			wolf->player.pos.y += wolf->player.dirt.y * wolf->player.s_move;
	}
}

void		key_down(t_env *wolf)
{
	if (wolf->map[(int)(wolf->player.pos.x - wolf->player.dirt.x *
	wolf->player.s_move)][(int)wolf->player.pos.y] == 0)
		wolf->player.pos.x -= wolf->player.dirt.x * wolf->player.s_move;
	if (wolf->map[(int)wolf->player.pos.x][(int)(wolf->player.pos.y -
	wolf->player.dirt.y * wolf->player.s_move)] == 0)
		wolf->player.pos.y -= wolf->player.dirt.y * wolf->player.s_move;
}

void		key_left(t_env *wolf)
{
	t_var	tmp;

	tmp.x = wolf->player.dirt.x;
	wolf->player.dirt.x = wolf->player.dirt.x * cos(wolf->player.s_turn) -
	wolf->player.dirt.y * sin(wolf->player.s_turn);
	wolf->player.dirt.y = tmp.x * sin(wolf->player.s_turn) +
	wolf->player.dirt.y * cos(wolf->player.s_turn);
	tmp.x = wolf->player.plane.x;
	wolf->player.plane.x = wolf->player.plane.x * cos(wolf->player.s_turn) -
	wolf->player.plane.y * sin(wolf->player.s_turn);
	wolf->player.plane.y = tmp.x * sin(wolf->player.s_turn) +
	wolf->player.plane.y * cos(wolf->player.s_turn);
}

void		key_right(t_env *wolf)
{
	t_var	tmp;

	tmp.x = wolf->player.dirt.x;
	wolf->player.dirt.x = wolf->player.dirt.x * cos(-wolf->player.s_turn) -
	wolf->player.dirt.y * sin(-wolf->player.s_turn);
	wolf->player.dirt.y = tmp.x * sin(-wolf->player.s_turn) +
	wolf->player.dirt.y * cos(-wolf->player.s_turn);
	tmp.x = wolf->player.plane.x;
	wolf->player.plane.x = wolf->player.plane.x * cos(-wolf->player.s_turn) -
	wolf->player.plane.y * sin(-wolf->player.s_turn);
	wolf->player.plane.y = tmp.x * sin(-wolf->player.s_turn) +
	wolf->player.plane.y * cos(-wolf->player.s_turn);
}

int			key_press(int key, t_env *wolf)
{
	if (key == ESC || key == Q)
		f_exit(wolf);
	if (key == W)
		wolf->player.up = 1;
	if (key == S)
		wolf->player.down = 1;
	if (key == A)
		wolf->player.left = 1;
	if (key == D)
		wolf->player.right = 1;
	if (key == SHIFT)
		wolf->player.shift = 1;
	return (0);
}

int			key_release(int key, t_env *wolf)
{
	if (key == W)
		wolf->player.up = 0;
	if (key == S)
		wolf->player.down = 0;
	if (key == A)
		wolf->player.left = 0;
	if (key == D)
		wolf->player.right = 0;
	if (key == SHIFT)
		wolf->player.shift = 0;
	return (0);
}

int		game_loop(t_env *wolf)
{
	if (wolf->player.up)
		key_up(wolf);
	if (wolf->player.down)
		key_down(wolf);
	if (wolf->player.left)
		key_left(wolf);
	if (wolf->player.right)
		key_right(wolf);
	raycasting(wolf);
	draw(wolf);
	return (0);
}