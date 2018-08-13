/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 14:42:45 by vzamyati          #+#    #+#             */
/*   Updated: 2018/08/11 14:42:46 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void	put_floor(t_env *w)
{
	w->data[4 * (W_WIDTH * w->rayc.y + w->rayc.x)] = w->texture
	[7].data[(4 * (w->texture->width * w->rayc.floor_texy +
		w->rayc.floor_texx))] >> 1 & 8355711;
	w->data[4 * (W_WIDTH * w->rayc.y + w->rayc.x) + 1] = w->texture
	[7].data[(4 * (w->texture->width * w->rayc.floor_texy +
		w->rayc.floor_texx)) + 1] >> 1 & 8355711;
	w->data[4 * (W_WIDTH * w->rayc.y + w->rayc.x) + 2] = w->texture
	[7].data[(4 * (w->texture->width * w->rayc.floor_texy +
		w->rayc.floor_texx)) + 2] >> 1 & 8355711;
}

void	put_ceil(t_env *w)
{
	w->data[4 * (W_WIDTH * (W_HEIGHT - w->rayc.y) + w->rayc.x)] = w->texture
	[8].data[(4 * (w->texture->width * w->rayc.floor_texy +
		w->rayc.floor_texx))];
	w->data[4 * (W_WIDTH * (W_HEIGHT - w->rayc.y) + w->rayc.x) + 1] = w->texture
	[8].data[(4 * (w->texture->width * w->rayc.floor_texy +
		w->rayc.floor_texx)) + 1];
	w->data[4 * (W_WIDTH * (W_HEIGHT - w->rayc.y) + w->rayc.x) + 2] = w->texture
	[8].data[(4 * (w->texture->width * w->rayc.floor_texy +
		w->rayc.floor_texx)) + 2];
}

void	lets_draw_floor2(t_env *w)
{
	double		c_dist;
	double		weight;
	double		c_fx;
	double		c_fy;

	w->rayc.dist_wall = w->rayc.pwd;
	w->rayc.dist_player = 0.0;
	if (w->rayc.end < 0)
		w->rayc.end = W_HEIGHT;
	w->rayc.y = w->rayc.end + 1;
	while (w->rayc.y < W_HEIGHT)
	{
		c_dist = W_HEIGHT / (2.0 * w->rayc.y - W_HEIGHT);
		weight = (c_dist - w->rayc.dist_player) /
		(w->rayc.dist_wall - w->rayc.dist_player);
		c_fx = weight * w->rayc.floorxwall + (1.0 - weight) * w->rayc.pos.x;
		c_fy = weight * w->rayc.floorywall + (1.0 - weight) * w->rayc.pos.y;
		w->rayc.floor_texx = (int)(c_fx *
			w->texture->width) % w->texture->width;
		w->rayc.floor_texy = (int)(c_fy *
			w->texture->height) % w->texture->height;
		put_floor(w);
		put_ceil(w);
		w->rayc.y++;
	}
}

void	lets_draw_floor(t_env *w)
{
	if (w->rayc.hit_side == 0 && w->rayc.dirt.x > 0)
	{
		w->rayc.floorxwall = w->rayc.map_x;
		w->rayc.floorywall = w->rayc.map_y + w->rayc.wall_x;
	}
	else if (w->rayc.hit_side == 0 && w->rayc.dirt.x < 0)
	{
		w->rayc.floorxwall = w->rayc.map_x + 1.0;
		w->rayc.floorywall = w->rayc.map_y + w->rayc.wall_x;
	}
	else if (w->rayc.hit_side == 1 && w->rayc.dirt.y > 0)
	{
		w->rayc.floorxwall = w->rayc.map_x + w->rayc.wall_x;
		w->rayc.floorywall = w->rayc.map_y;
	}
	else
	{
		w->rayc.floorxwall = w->rayc.map_x + w->rayc.wall_x;
		w->rayc.floorywall = w->rayc.map_y + 1.0;
	}
	lets_draw_floor2(w);
}
