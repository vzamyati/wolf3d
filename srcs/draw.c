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

void		lets_draw_walls(t_env *w, int x, int texture_nb)
{
	w->rayc.y = w->rayc.start;
	while (w->rayc.y <= w->rayc.end && w->rayc.y < W_WIDTH)
	{
		w->rayc.d = w->rayc.y * 256 - W_HEIGHT * 128 + w->rayc.height * 128;
		w->rayc.texture_y = ((w->rayc.d * TEXTURE_HEIGHT /
			w->rayc.height) / 256);
		w->data[4 * (W_WIDTH * w->rayc.y + x)] = w->texture
		[texture_nb].data[(4 * (TEXTURE_WIDTH *
			w->rayc.texture_y + w->rayc.texture_x))];
		w->data[4 * (W_WIDTH * w->rayc.y + x) + 1] = w->texture
		[texture_nb].data[(4 * (TEXTURE_WIDTH * w->rayc.texture_y +
			w->rayc.texture_x)) + 1];
		w->data[4 * (W_WIDTH * w->rayc.y + x) + 2] = w->texture
		[texture_nb].data[(4 * (TEXTURE_WIDTH * w->rayc.texture_y +
			w->rayc.texture_x)) + 2];
		w->rayc.y++;
	}
}

void		lets_draw_compas(t_env *w, int x)
{
	w->rayc.y = w->rayc.start;
	while (w->rayc.y <= w->rayc.end && w->rayc.y < W_WIDTH)
	{
		if (w->rayc.step_x < 0)
			lets_draw_walls(w, x, 0);
		else
			lets_draw_walls(w, x, 1);
		if (w->rayc.hit_side == 1)
		{
			if (w->rayc.step_y < 0)
				lets_draw_walls(w, x, 2);
			else
				lets_draw_walls(w, x, 3);
		}
	}
}

void		shoot(t_env *w)
{
	int x;
	int y;

	x = (W_WIDTH / 2) - (w->weapon.width / 2);
	y = W_HEIGHT - w->weapon.height;
	mlx_put_image_to_window(w->mlx, w->win, w->weapon.shots[0].ptr, x + 100, y);
}

void		weapon(t_env *w)
{
	int x;
	int y;

	x = (W_WIDTH / 2) - (w->weapon.width / 2);
	y = W_HEIGHT - w->weapon.height;
	mlx_put_image_to_window(w->mlx, w->win, w->weapon.shotgun, x + 100, y);
}

void		draw(t_env *w)
{
	mlx_clear_window(w->mlx, w->win);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	if (w->flag.info == 1)
		show_info(w);
	fps(w);
	if (w->flag.weapon == 1)
	{
		cross(w);
		weapon(w);
	}
}
