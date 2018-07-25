/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:29:41 by vzamyati          #+#    #+#             */
/*   Updated: 2018/07/19 18:29:44 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				ray_draw(t_env *wolf, int x)
{
	textures(wolf);
	wolf->rayc.height = (int)(W_HEIGHT / wolf->rayc.pwd);
	wolf->rayc.start = -wolf->rayc.height / 2 + W_HEIGHT / 2;
	if (wolf->rayc.start < 0)
		wolf->rayc.start = 0;
	wolf->rayc.end = wolf->rayc.height / 2 + W_HEIGHT / 2;
	if (wolf->rayc.end < 0)
		wolf->rayc.end = 0;
	wolf->rayc.texture_nb = wolf->map[wolf->rayc.map_x][wolf->rayc.map_y] - 1;
	if (wolf->rayc.hit_side == 0)
		wolf->rayc.wall_x = wolf->rayc.pos.y + wolf->rayc.pwd * wolf->rayc.dirt.y;
	else
		wolf->rayc.wall_x = wolf->rayc.pos.x + wolf->rayc.pwd * wolf->rayc.dirt.x;
	wolf->rayc.wall_x -= floor((wolf->rayc.wall_x));
	wolf->rayc.texture_x = (int)(wolf->rayc.wall_x * (float)TEXTURE_WIDTH);
	if (wolf->rayc.hit_side == 0 && wolf->rayc.dirt.x > 0)
		wolf->rayc.texture_x = TEXTURE_WIDTH - wolf->rayc.texture_x - 1;
	if (wolf->rayc.hit_side == 1 && wolf->rayc.dirt.y < 0)
		wolf->rayc.texture_x = TEXTURE_WIDTH - wolf->rayc.texture_x - 1;
	lets_draw(wolf, x, wolf->rayc.start, wolf->rayc.end);
}

void		ray_dist(t_env *wolf)
{
	while (wolf->rayc.hit == 0)
	{
		if (wolf->rayc.side.x < wolf->rayc.side.y)
		{
			wolf->rayc.side.x += wolf->rayc.delta.x;
			wolf->rayc.map_x += wolf->rayc.step_x;
			wolf->rayc.hit_side = 0;
		}
		else
		{
			wolf->rayc.side.y += wolf->rayc.delta.y;
			wolf->rayc.map_y += wolf->rayc.step_y;
			wolf->rayc.hit_side = 1;
		}
		if (wolf->map[wolf->rayc.map_x][wolf->rayc.map_y] > 0)
		{
			wolf->rayc.hit = 1;
			if (wolf->rayc.hit_side == 0)
				wolf->rayc.pwd = (wolf->rayc.map_x - wolf->rayc.pos.x +
					(1 - wolf->rayc.step_x) / 2) / wolf->rayc.dirt.x;
			else
				wolf->rayc.pwd = (wolf->rayc.map_y - wolf->rayc.pos.y +
					(1 - wolf->rayc.step_y) / 2) / wolf->rayc.dirt.y;
		}
	}
}

void	ray_step(t_env *wolf)
{
	if (wolf->rayc.dirt.x < 0)
	{
		wolf->rayc.step_x = -1;
		wolf->rayc.side.x = (wolf->rayc.pos.x -
			(int)wolf->rayc.pos.x) * wolf->rayc.delta.x;
	}
	else
	{
		wolf->rayc.step_x = 1;
		wolf->rayc.side.x = ((int)wolf->rayc.pos.x + 1 -
			wolf->rayc.pos.x) * wolf->rayc.delta.x;
	}
	if (wolf->rayc.dirt.y < 0)
	{
		wolf->rayc.step_y = -1;
		wolf->rayc.side.y = (wolf->rayc.pos.y -
			(int)wolf->rayc.pos.y) * wolf->rayc.delta.y;
	}
	else
	{
		wolf->rayc.step_y = 1;
		wolf->rayc.side.y = ((int)wolf->rayc.pos.y + 1 -
			wolf->rayc.pos.y) * wolf->rayc.delta.y;
	}
}

void	raycasting(t_env *wolf)
{
	int x;

	x = -1;
	while (++x < W_WIDTH)
	{
		wolf->rayc.camera = 2 * x / (double)W_WIDTH - 1;
		wolf->rayc.pos.x = wolf->player.pos.x;
		wolf->rayc.pos.y = wolf->player.pos.y;
		wolf->rayc.dirt.x = wolf->player.dirt.x +
		wolf->player.plane.x * wolf->rayc.camera;
		wolf->rayc.dirt.y = wolf->player.dirt.y +
		wolf->player.plane.y * wolf->rayc.camera;
		wolf->rayc.map_x = (int)wolf->rayc.pos.x;
		wolf->rayc.map_y = (int)wolf->rayc.pos.y;
		wolf->rayc.delta.x = sqrt(1 + (wolf->rayc.dirt.y * wolf->rayc.dirt.y) /
			(wolf->rayc.dirt.x * wolf->rayc.dirt.x));
		wolf->rayc.delta.y = sqrt(1 + (wolf->rayc.dirt.x * wolf->rayc.dirt.x) /
			(wolf->rayc.dirt.y * wolf->rayc.dirt.y));
		wolf->rayc.hit = 0;
		wolf->rayc.hit_side = 0;
		ray_step(wolf);
		ray_dist(wolf);
		ray_draw(wolf, x);
	}
}
