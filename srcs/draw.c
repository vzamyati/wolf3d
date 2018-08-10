/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 18:15:07 by vzamyati          #+#    #+#             */
/*   Updated: 2018/07/25 18:15:08 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"


void		lets_draw_walls(t_env *w, int x, int start, int end)
{
	w->rayc.y = start;
	while (w->rayc.y <= end && w->rayc.y < W_WIDTH)
	{
		w->rayc.d = w->rayc.y * 256 - W_HEIGHT * 128 + w->rayc.height * 128;
		w->rayc.texture_y = ((w->rayc.d * TEXTURE_HEIGHT / w->rayc.height) / 256);
		w->data[4 * (W_WIDTH * w->rayc.y + x)] = w->texture
		[w->rayc.texture_nb].data[(4 * (TEXTURE_WIDTH *
			w->rayc.texture_y + w->rayc.texture_x))];
		w->data[4 * (W_WIDTH * w->rayc.y + x) + 1] = w->texture
		[w->rayc.texture_nb].data[(4 * (TEXTURE_WIDTH * w->rayc.texture_y +
			w->rayc.texture_x)) + 1];
		w->data[4 * (W_WIDTH * w->rayc.y + x) + 2] = w->texture
		[w->rayc.texture_nb].data[(4 * (TEXTURE_WIDTH * w->rayc.texture_y +
			w->rayc.texture_x)) + 2];
		w->rayc.y++;
	}
}

void	pixel_put(t_env *w, int x, int y, int color)
{
	int				i;

	i = (x * 4) + (y * w->sizeline);
	w->data[i++] = color;
	w->data[i++] = color >> 8;
	w->data[i] = color >> 16;
}

void			lets_draw_floor2(t_env *w)
{
	double		current_dist;
	double 		weight;
	double		curr_floorx;
	double		curr_floory;

	w->rayc.dist_wall = w->rayc.pwd;
	w->rayc.dist_player = 0.0;
	if (w->rayc.end < 0)
		w->rayc.end = W_HEIGHT;
	w->rayc.y = w->rayc.end + 1;
	while (w->rayc.y < W_HEIGHT)
	{
		current_dist = W_HEIGHT / (2.0 * w->rayc.y - W_HEIGHT);
		weight = (current_dist - w->rayc.dist_player) / (w->rayc.dist_wall - w->rayc.dist_player);
        curr_floorx = weight * w->rayc.floorxwall + (1.0 - weight) * w->rayc.pos.x;
       	curr_floory = weight * w->rayc.floorywall + (1.0 - weight) * w->rayc.pos.y;
        w->rayc.floor_texx = (int)(curr_floorx * TEXTURE_WIDTH) % TEXTURE_WIDTH;
        w->rayc.floor_texy = (int)(curr_floory * TEXTURE_HEIGHT) % TEXTURE_HEIGHT;
        pixel_put(w, w->rayc.x, w->rayc.y, (w->texture[7].data[(4 * (TEXTURE_WIDTH * w->rayc.floor_texy +
			w->rayc.floor_texx))] >> 1) & 8355711);
        pixel_put(w, w->rayc.x, W_HEIGHT - w->rayc.y, w->texture[7].data[(4 * (TEXTURE_WIDTH * w->rayc.floor_texy +
			w->rayc.floor_texx))]);
        w->rayc.y++;
	}
}


void			lets_draw_floor(t_env *w)
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
		w->rayc.floorywall= w->rayc.map_y + 1.0;
	}
	lets_draw_floor2(w);
}

void		draw(t_env *w)
{
	mlx_clear_window(w->mlx, w->win);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	if (w->flag.info == 1)
		show_info(w);
	cross(w);
	fps(w);
}
