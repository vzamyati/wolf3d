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

void				draw_texture(t_env *wolf, int y, int x)
{
	int				i;

	i = y * 256 - W_HEIGHT * 128 + wolf->rayc.height * 128;
	wolf->rayc.texture_y = ((i * TEXTURE_HEIGHT / wolf->rayc.height) / 256);
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

void	draw(t_env *wolf)
{
	mlx_clear_window(wolf->mlx, wolf->win);
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->img, 0, 0);
	if (wolf->flag.info == 1)
		show_info(wolf);
	cross(wolf);
	fps(wolf);
}