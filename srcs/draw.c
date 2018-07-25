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

#include "wolf3d.h"

void				get_text(t_env *wolf)
{
	if (wolf->rayc.hit_side == 1)
	{
		if ((wolf->rayc.step_x == -1 && wolf->rayc.step_y == -1) ||
			(wolf->rayc.step_x == 1 && wolf->rayc.step_y == -1))
		{
			if (wolf->map[wolf->rayc.map_x][wolf->rayc.map_y] == 6)
				wolf->rayc.texture_nb = 0;
		}
		if ((wolf->rayc.step_x == -1 && wolf->rayc.step_y == 1) ||
			(wolf->rayc.step_x == 1 && wolf->rayc.step_y == 1))
		{
			if (wolf->map[wolf->rayc.map_x][wolf->rayc.map_y] == 6)
				wolf->rayc.texture_nb = 0;
		}
		else
		{
			if (wolf->map[wolf->rayc.map_x][wolf->rayc.map_y] == 6)
				wolf->rayc.texture_nb = 9;
		}
	}
}

void				draw_texture(t_env *wolf, int y, int x)
{
	int				i;

	get_text(wolf);
	i = y * 256 - W_HEIGHT * 128 + wolf->rayc.height * 128;
	wolf->rayc.texture_y = ((i * TEXTURE_WIDTH / wolf->rayc.height) / 256);
	wolf->data[4 * (W_WIDTH * y + x)] = wolf->texture
	[wolf->rayc.texture_nb].data[(4 * (TEXTURE_WIDTH * 
		wolf->rayc.texture_y + wolf->rayc.texture_x))];
	wolf->data[4 * (W_WIDTH * y + x) + 1] = wolf->texture
	[wolf->rayc.texture_nb].data[(4 * (TEXTURE_WIDTH * wolf->rayc.texture_y +
		wolf->rayc.texture_x)) + 1];
	wolf->data[4 * (W_WIDTH * y + x) + 2] = wolf->texture
	[wolf->rayc.texture_nb].data[(4 * (TEXTURE_WIDTH * wolf->rayc.texture_y +
		wolf->rayc.texture_x)) + 2];
}

void				draw_pixel(t_env *wolf, int x, int y, unsigned int c)
{
	int				i;

	i = (x * 4) + (y * wolf->sizeline);
	wolf->data[i++] = c;
	wolf->data[i++] = c >> 8;
	wolf->data[i] = c >> 16;
}

void				lets_draw(t_env *wolf, int x, int start, int end)
{
	int				i;

	i = -1;
	while (++i < start)
		draw_pixel(wolf, x, i, wolf->ceil);
	i--;
	while (++i <= end && i < W_WIDTH)
		draw_texture(wolf, i, x);
	i--;
	while (++i < W_HEIGHT)
		draw_pixel(wolf, x, i, wolf->floor);
}
