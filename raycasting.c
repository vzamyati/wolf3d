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

void	raycasting(t_env *wolf)
{
	int x;

	x = -1;
	wolf->rayc.position.x = wolf->player.position.x;
	wolf->rayc.position.y = wolf->player.position.y;
	while (++x < W_WIDTH)
	{
		calculate_ray(wolf, x);
		step(wolf);
		dda(wolf);
		ceil_color(wolf);
		draw_walls(wolf, x);
	}
}

void	calculate_ray(t_env *wolf, int x)
{
	wolf->rayc.camera = 2 * x / (double)(W_WIDTH) - 1;
	wolf->rayc.direct.x = wolf->player.direct.x + wolf->player.plane.x
	* wolf->rayc.camera;
	wolf->rayc.direct.y = wolf->player.direct.y + wolf->player.plane.y
	* wolf->rayc.camera;
	wolf->rayc.map_x = (int)wolf->rayc.position.x;
	wolf->rayc.map_y = (int)wolf->rayc.position.y;
	wolf->rayc.delta.x = sqrt(1 + (wolf->rayc.direct.y * wolf->rayc.direct.y) /
		(wolf->rayc.direct.x * wolf->rayc.direct.x));
	wolf->rayc.delta.y = sqrt(1 + (wolf->rayc.direct.x * wolf->rayc.direct.x) /
		(wolf->rayc.direct.y * wolf->rayc.direct.y));
	wolf->rayc.hit = 0;
	wolf->rayc.hit_side = 0;
}

void	step(t_env *wolf)
{
	if (wolf->rayc.direct.x < 0)
	{
		wolf->rayc.step_x = -1;
		wolf->rayc.side.x = (wolf->rayc.position.x - (int)wolf->rayc.position.x) * 
			wolf->rayc.delta.x;
	}
	else
	{
		wolf->rayc.step_x = 1;
		wolf->rayc.side.x = ((int)wolf->rayc.position.x + 1 - wolf->rayc.position.x) * 
			wolf->rayc.delta.x;
	}
	if (wolf->rayc.direct.y < 0)
	{
		wolf->rayc.step_y = -1;
		wolf->rayc.side.y = (wolf->rayc.position.y - (int)wolf->rayc.position.y) * 
			wolf->rayc.delta.y;
	}
	else
	{
		wolf->rayc.step_y = 1;
		wolf->rayc.side.y = ((int)wolf->rayc.position.y + 1 - wolf->rayc.position.y) * 
			wolf->rayc.delta.y;
	}
}

void	dda(t_env *wolf)
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
			wolf->rayc.hit = 1;
	}
	if (wolf->rayc.hit_side == 0)
		wolf->rayc.perpwalldist = (wolf->rayc.map_x - wolf->rayc.position.x +
			(1 - wolf->rayc.step_x) / 2) / wolf->rayc.direct.x;
	else
		wolf->rayc.perpwalldist = (wolf->rayc.map_y - wolf->rayc.position.y +
			(1 - wolf->rayc.step_y) / 2) / wolf->rayc.direct.y;
}

void	draw_walls(t_env *wolf, int x)
{
	wolf->line_height = (int)(W_HEIGHT / wolf->rayc.perpwalldist);
	wolf->draw_start = (-(wolf->line_height) / 2 + W_HEIGHT / 2);
	if (wolf->draw_start < 0)
		wolf->draw_start = 0;
	wolf->draw_end = wolf->line_height / 2 + W_HEIGHT / 2;
	if (wolf->draw_end >= wolf->line_height)
		wolf->draw_end = wolf->line_height - 1;
	pick_texture(wolf);
	if (wolf->rayc.hit_side == 0)
		wolf->image.wallx = wolf->rayc.position.y + wolf->rayc.perpwalldist * wolf->rayc.direct.y;
	else
		wolf->image.wallx = wolf->rayc.position.y +  wolf->rayc.perpwalldist * wolf->rayc.direct.x;
	wolf->image.wallx -= floor(wolf->image.wallx);
	wolf->image.texture_x = (int)(wolf->image.wallx * (double)64);
	if (wolf->rayc.hit_side == 0 && wolf->rayc.direct.x > 0)
		wolf->image.texture_x = 64 - wolf->image.texture_x - 1;
	if (wolf->rayc.hit_side == 1 && wolf->rayc.direct.y < 0)
		wolf->image.texture_x = 64 - wolf->image.texture_x - 1;
	final_draw(wolf, x, wolf->draw_start, wolf->draw_end);
}

void	pick_texture(t_env *wolf)
{
	if (wolf->map[wolf->rayc.map_x][wolf->rayc.map_y] == 1)
		wolf->image.texture_n = 0;
}

void	ceil_color(t_env *wolf)
{
	if (wolf->player.position.x < 23 && wolf->player.position.y < 33)
		wolf->ceil = 0x000000;
	else
		wolf->ceil = 0xffffff;
}


