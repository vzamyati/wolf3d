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

#include "w3d.h"

void		set_texture(t_env *w)
{
	if (w->rayc.hit_side == 0)
		w->rayc.wall_x = w->rayc.pos.y + w->rayc.pwd * w->rayc.dirt.y;
	else
		w->rayc.wall_x = w->rayc.pos.x + w->rayc.pwd * w->rayc.dirt.x;
	w->rayc.wall_x -= floor((w->rayc.wall_x));
	w->rayc.texture_x = (int)(w->rayc.wall_x * (float)TEXTURE_WIDTH);
	if (w->rayc.hit_side == 0 && w->rayc.dirt.x > 0)
		w->rayc.texture_x = TEXTURE_WIDTH - w->rayc.texture_x - 1;
	if (w->rayc.hit_side == 1 && w->rayc.dirt.y < 0)
		w->rayc.texture_x = TEXTURE_WIDTH - w->rayc.texture_x - 1;
	w->player.oldtime = w->player.time;
	w->player.time = clock();
	w->player.frametime = (w->player.time - w->player.oldtime) / 1000.0;
	w->player.s_move = w->player.frametime * 5.0;
	w->player.s_rot = w->player.frametime * 1.5;
	if (w->flag.texture == 0)
		lets_draw_walls(w, w->rayc.x, w->rayc.start, w->rayc.end, w->rayc.texture_nb);
	else
		lets_draw_compas(w, w->rayc.x, w->rayc.start, w->rayc.end);
}

void		ray_draw(t_env *w)
{
	w->rayc.height = (int)(W_HEIGHT / w->rayc.pwd);
	w->rayc.start = -w->rayc.height / 2 + W_HEIGHT / 2;
	if (w->rayc.start < 0)
		w->rayc.start = 0;
	w->rayc.end = w->rayc.height / 2 + W_HEIGHT / 2;
	if (w->rayc.end >= W_HEIGHT)
		w->rayc.end = W_HEIGHT - 1;
	w->rayc.texture_nb = w->map[w->rayc.map_x][w->rayc.map_y] - 1;
	get_texture(w);
}

void		ray_dist(t_env *w)
{
	while (w->rayc.hit == 0)
	{
		if (w->rayc.side.x < w->rayc.side.y)
		{
			w->rayc.side.x += w->rayc.delta.x;
			w->rayc.map_x += w->rayc.step_x;
			w->rayc.hit_side = 0;
		}
		else
		{
			w->rayc.side.y += w->rayc.delta.y;
			w->rayc.map_y += w->rayc.step_y;
			w->rayc.hit_side = 1;
		}
		if (w->map[w->rayc.map_x][w->rayc.map_y] > 0)
			w->rayc.hit = 1;
	}
	if (w->rayc.hit_side == 0)
		w->rayc.pwd = (w->rayc.map_x - w->rayc.pos.x +
			(1 - w->rayc.step_x) / 2) / w->rayc.dirt.x;
	else
		w->rayc.pwd = (w->rayc.map_y - w->rayc.pos.y +
			(1 - w->rayc.step_y) / 2) / w->rayc.dirt.y;
}

void		ray_step(t_env *w)
{
	if (w->rayc.dirt.x < 0)
	{
		w->rayc.step_x = -1;
		w->rayc.side.x = (w->rayc.pos.x -
			(int)w->rayc.pos.x) * w->rayc.delta.x;
	}
	else
	{
		w->rayc.step_x = 1;
		w->rayc.side.x = ((int)w->rayc.pos.x + 1.0 -
			w->rayc.pos.x) * w->rayc.delta.x;
	}
	if (w->rayc.dirt.y < 0)
	{
		w->rayc.step_y = -1;
		w->rayc.side.y = (w->rayc.pos.y -
			(int)w->rayc.pos.y) * w->rayc.delta.y;
	}
	else
	{
		w->rayc.step_y = 1;
		w->rayc.side.y = ((int)w->rayc.pos.y + 1.0 -
			w->rayc.pos.y) * w->rayc.delta.y;
	}
}

void		raycasting(t_env *w)
{
	w->rayc.x = -1;
	w->rayc.y = 0;
	w->rayc.d = 0;
	while (++w->rayc.x < W_WIDTH)
	{
		w->rayc.camera = 2 * w->rayc.x / (double)W_WIDTH - 1;
		w->rayc.pos.x = w->player.pos.x;
		w->rayc.pos.y = w->player.pos.y;
		w->rayc.dirt.x = w->player.dirt.x +
		w->player.plane.x * w->rayc.camera;
		w->rayc.dirt.y = w->player.dirt.y +
		w->player.plane.y * w->rayc.camera;
		w->rayc.map_x = (int)w->rayc.pos.x;
		w->rayc.map_y = (int)w->rayc.pos.y;
		w->rayc.delta.x = sqrt(1 + (w->rayc.dirt.y * w->rayc.dirt.y) /
			(w->rayc.dirt.x * w->rayc.dirt.x));
		w->rayc.delta.y = sqrt(1 + (w->rayc.dirt.x * w->rayc.dirt.x) /
			(w->rayc.dirt.y * w->rayc.dirt.y));
		w->rayc.hit = 0;
		ray_step(w);
		ray_dist(w);
		ray_draw(w);
		set_texture(w);
		lets_draw_floor(w);
	}
}
