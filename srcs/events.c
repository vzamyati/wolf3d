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

int		game_loop(t_env *wolf)
{
	(wolf->player.flag.up) ? key_up(wolf) : 42;
	(wolf->player.flag.down) ? key_down(wolf) : 42;
	(wolf->player.flag.left) ? key_left(wolf) : 42;
	(wolf->player.flag.right) ? key_right(wolf) : 42;
	raycasting(wolf);
	draw(wolf);
	return (0);
}

int			key_press(int key, t_env *wolf)
{
	if (key == ESC || key == Q)
		f_exit(wolf);
	if (key == W || key == ARR_UP)
		wolf->player.flag.up = 1;
	if (key == S || key == ARR_DOWN)
		wolf->player.flag.down = 1;
	if (key == A || key == ARR_LEFT)
		wolf->player.flag.left = 1;
	if (key == D || key == ARR_RIGHT)
		wolf->player.flag.right = 1;
	if (key == SHIFT1 || key == SHIFT2)
		wolf->player.flag.shift = 1;
	if (key == NEXT || key == PREV || key == OFF)
		change_music(key, wolf);
	if (key == RESTART)
		place_player(wolf);
	if (key == INFO)
		(wolf->flag.info == 0) ? (wolf->flag.info = 1) : (wolf->flag.info = 0);
	return (0);
}

int			key_release(int key, t_env *wolf)
{
	if (key == W || key == ARR_UP)
		wolf->player.flag.up = 0;
	if (key == S || key == ARR_DOWN)
		wolf->player.flag.down = 0;
	if (key == A || key == ARR_LEFT)
		wolf->player.flag.left = 0;
	if (key == D || key == ARR_RIGHT)
		wolf->player.flag.right = 0;
	if (key == SHIFT1 || key == SHIFT2)
		wolf->player.flag.shift = 0;
	return (0);
}
