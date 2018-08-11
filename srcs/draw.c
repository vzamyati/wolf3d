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

void		weapon(t_env *w)
{
	int a;
	int b;
	int x;
	int y;

	w->weapon.shotgun = mlx_xpm_file_to_image(w->mlx,
		"textures/makarov.xpm", &a, &b);
	x = (W_WIDTH / 2) - (a / 2);
	y = W_HEIGHT - b;
	mlx_put_image_to_window(w->mlx, w->win, w->weapon.shotgun, W_WIDTH / 2, W_HEIGHT / 2);
}

void		draw(t_env *w)
{
	mlx_clear_window(w->mlx, w->win);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	if (w->flag.info == 1)
		show_info(w);
	cross(w);
	fps(w);
	weapon(w);
}
