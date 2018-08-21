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

#include "w3d.h"

int		game_loop(t_env *w)
{
	(w->player.flag.up) ? key_up(w) : 42;
	(w->player.flag.down) ? key_down(w) : 42;
	(w->player.flag.left) ? key_left(w) : 42;
	(w->player.flag.right) ? key_right(w) : 42;
	raycasting(w);
	draw(w);
	return (0);
}

int		mouse_hook(int key, int x, int y, t_env *w)
{
	(void)x;
	(void)y;
	if (key == 1 && w->flag.weapon == 1)
		shoot(w);
	return (0);
}

int		key_press2(int key, t_env *w)
{
	if (key == INFO)
	{
		if (w->flag.info == 0)
			w->flag.info = 1;
		else
			w->flag.info = 0;
	}
	if (key == WEAPON)
	{
		if (w->flag.weapon == 0)
			w->flag.weapon = 1;
		else
			w->flag.weapon = 0;
	}
	if (key == TEXTURE)
	{
		if (w->flag.texture == 0)
			w->flag.texture = 1;
		else
			w->flag.texture = 0;
	}
	return (0);
}

int		key_press(int key, t_env *w)
{
	if (key == ESC || key == Q)
		f_exit(w);
	if (key == W || key == ARR_UP)
		w->player.flag.up = 1;
	if (key == S || key == ARR_DOWN)
		w->player.flag.down = 1;
	if (key == A || key == ARR_LEFT)
		w->player.flag.left = 1;
	if (key == D || key == ARR_RIGHT)
		w->player.flag.right = 1;
	if (key == SHIFT1 || key == SHIFT2)
		w->player.flag.shift = 1;
	if (key == NEXT || key == PREV || key == OFF)
		change_music(key, w);
	if (key == RESTART)
		place_player(w);
	key_press2(key, w);
	return (0);
}

int		key_release(int key, t_env *w)
{
	if (key == W || key == ARR_UP)
		w->player.flag.up = 0;
	if (key == S || key == ARR_DOWN)
		w->player.flag.down = 0;
	if (key == A || key == ARR_LEFT)
		w->player.flag.left = 0;
	if (key == D || key == ARR_RIGHT)
		w->player.flag.right = 0;
	if (key == SHIFT1 || key == SHIFT2)
		w->player.flag.shift = 0;
	return (0);
}
