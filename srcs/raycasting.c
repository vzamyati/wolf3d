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

void				get_text(t_env *wolf)
{
	if (wolf->ray.hit_side == 1)
	{
		if ((wolf->ray.step_x == -1 && wolf->ray.step_y == -1) ||
			(wolf->ray.step_x == 1 && wolf->ray.step_y == -1))
		{
			if (wolf->map[wolf->ray.map_x][wolf->ray.map_y] == 6)
				wolf->scene.t_n = 0;
		}
		if ((wolf->ray.step_x == -1 && wolf->ray.step_y == 1) ||
			(wolf->ray.step_x == 1 && wolf->ray.step_y == 1))
		{
			if (wolf->map[wolf->ray.map_x][wolf->ray.map_y] == 6)
				wolf->scene.t_n = 0;
		}
		else
		{
			if (wolf->map[wolf->ray.map_x][wolf->ray.map_y] == 6)
				wolf->scene.t_n = 9;
		}
	}
}

void				img_texture(t_env *wolf, int y, int x)
{
	int				i;

	get_text(wolf);
	i = y * 256 - W_HEIGHT * 128 + wolf->scene.height * 128;
	wolf->test.t_y = ((i * TEXT_W / wolf->scene.height) / 256);
	wolf->data[4 * (W_WIDTH * y + x)] = wolf->texture
	[wolf->scene.t_n].data[(4 * (TEXT_W * wolf->test.t_y + wolf->test.t_x))];
	wolf->data[4 * (W_WIDTH * y + x) + 1] = wolf->texture
	[wolf->scene.t_n].data[(4 * (TEXT_W * wolf->test.t_y +
		wolf->test.t_x)) + 1];
	wolf->data[4 * (W_WIDTH * y + x) + 2] = wolf->texture
	[wolf->scene.t_n].data[(4 * (TEXT_W * wolf->test.t_y +
		wolf->test.t_x)) + 2];
}

void				img_pixel(t_env *wolf, int x, int y, unsigned int c)
{
	int				i;

	i = (x * 4) + (y * wolf->sizeline);
	wolf->data[i++] = c;
	wolf->data[i++] = c >> 8;
	wolf->data[i] = c >> 16;
}

void				draw_line(t_env *wolf, int x, int start, int end)
{
	int				i;

	i = -1;
	while (++i < start)
		img_pixel(wolf, x, i, wolf->ceil);
	i--;
	while (++i <= end && i < W_WIDTH)
		img_texture(wolf, i, x);
	i--;
	while (++i < W_HEIGHT)
		img_pixel(wolf, x, i, wolf->floor);
}

void				ray_draw(t_env *wolf, int x)
{
	wolf->scene.height = (int)(W_HEIGHT / wolf->ray.perpwalldist);
	wolf->scene.start = -wolf->scene.height / 2 + W_HEIGHT / 2;
	if (wolf->scene.start < 0)
		wolf->scene.start = 0;
	wolf->scene.end = wolf->scene.height / 2 + W_HEIGHT / 2;
	if (wolf->scene.end < 0)
		wolf->scene.end = 0;
	texture_n(wolf);
	wolf->test.t_num = wolf->map[wolf->ray.map_x][wolf->ray.map_y] - 1;
	if (wolf->ray.hit_side == 0)
		wolf->test.wallx = wolf->ray.position.y + wolf->ray.perpwalldist * wolf->ray.direct.y;
	else
		wolf->test.wallx = wolf->ray.position.x + wolf->ray.perpwalldist * wolf->ray.direct.x;
	wolf->test.wallx -= floor((wolf->test.wallx));
	wolf->test.t_x = (int)(wolf->test.wallx * (float)TEXT_W);
	if (wolf->ray.hit_side == 0 && wolf->ray.direct.x > 0)
		wolf->test.t_x = TEXT_W - wolf->test.t_x - 1;
	if (wolf->ray.hit_side == 1 && wolf->ray.direct.y < 0)
		wolf->test.t_x = TEXT_W - wolf->test.t_x - 1;
	draw_line(wolf, x, wolf->scene.start, wolf->scene.end);
}

void		ray_dist(t_env *wolf)
{
	while (wolf->ray.hit == 0)
	{
		if (wolf->ray.side.x < wolf->ray.side.y)
		{
			wolf->ray.side.x += wolf->ray.delta.x;
			wolf->ray.map_x += wolf->ray.step_x;
			wolf->ray.hit_side = 0;
		}
		else
		{
			wolf->ray.side.y += wolf->ray.delta.y;
			wolf->ray.map_y += wolf->ray.step_y;
			wolf->ray.hit_side = 1;
		}
		if (wolf->map[wolf->ray.map_x][wolf->ray.map_y] > 0)
		{
			wolf->ray.hit = 1;
			if (wolf->ray.hit_side == 0)
				wolf->ray.perpwalldist = (wolf->ray.map_x - wolf->ray.position.x +
					(1 - wolf->ray.step_x) / 2) / wolf->ray.direct.x;
			else
				wolf->ray.perpwalldist = (wolf->ray.map_y - wolf->ray.position.y +
					(1 - wolf->ray.step_y) / 2) / wolf->ray.direct.y;
		}
	}
}

void	ray_step(t_env *wolf)
{
	if (wolf->ray.direct.x < 0)
	{
		wolf->ray.step_x = -1;
		wolf->ray.side.x = (wolf->ray.position.x - (int)wolf->ray.position.x) *
		wolf->ray.delta.x;
	}
	else
	{
		wolf->ray.step_x = 1;
		wolf->ray.side.x = ((int)wolf->ray.position.x + 1 - wolf->ray.position.x) *
		wolf->ray.delta.x;
	}
	if (wolf->ray.direct.y < 0)
	{
		wolf->ray.step_y = -1;
		wolf->ray.side.y = (wolf->ray.position.y - (int)wolf->ray.position.y) *
		wolf->ray.delta.y;
	}
	else
	{
		wolf->ray.step_y = 1;
		wolf->ray.side.y = ((int)wolf->ray.position.y + 1 - wolf->ray.position.y) *
		wolf->ray.delta.y;
	}
}

void	init_ray(t_env *wolf, int x)
{
	wolf->ray.camera = 2 * x / (double)W_WIDTH - 1;
	wolf->ray.direct.x = wolf->player.direct.x + wolf->player.plane.x * wolf->ray.camera;
	wolf->ray.direct.y = wolf->player.direct.y + wolf->player.plane.y * wolf->ray.camera;
	wolf->ray.map_x = (int)wolf->ray.position.x;
	wolf->ray.map_y = (int)wolf->ray.position.y;
	wolf->ray.delta.x = sqrt(1 + (wolf->ray.direct.y * wolf->ray.direct.y) / (wolf->ray.direct.x * wolf->ray.direct.x));
	wolf->ray.delta.y = sqrt(1 + (wolf->ray.direct.x * wolf->ray.direct.x) / (wolf->ray.direct.y * wolf->ray.direct.y));
	wolf->ray.hit = 0;
	wolf->ray.hit_side = 0;
}

void	raycasting(t_env *wolf)
{
	int x;

	wolf->ray.position.x = wolf->player.position.x;
	wolf->ray.position.y = wolf->player.position.y;
	x = -1;
	while (++x < W_WIDTH)
	{
		init_ray(wolf, x);
		ray_step(wolf);
		ray_dist(wolf);
		ray_draw(wolf, x);
	}
}