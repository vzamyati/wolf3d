/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:53:14 by vzamyati          #+#    #+#             */
/*   Updated: 2018/08/09 14:53:16 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	cross(t_env *wolf)
{
	mlx_pixel_put(wolf->mlx, wolf->win, W_WIDTH / 2 - 1, W_HEIGHT / 2, 0xFFFFFF);
	mlx_pixel_put(wolf->mlx, wolf->win, W_WIDTH / 2 - 2, W_HEIGHT / 2, 0xFFFFFF);
	mlx_pixel_put(wolf->mlx, wolf->win, W_WIDTH / 2 - 3, W_HEIGHT / 2, 0xFFFFFF);
	mlx_pixel_put(wolf->mlx, wolf->win, W_WIDTH / 2 + 1, W_HEIGHT / 2, 0xFFFFFF);
	mlx_pixel_put(wolf->mlx, wolf->win, W_WIDTH / 2 + 2, W_HEIGHT / 2, 0xFFFFFF);
	mlx_pixel_put(wolf->mlx, wolf->win, W_WIDTH / 2 + 3, W_HEIGHT / 2, 0xFFFFFF);
	mlx_pixel_put(wolf->mlx, wolf->win, W_WIDTH / 2, (W_HEIGHT / 2) - 1, 0xFFFFFF);
	mlx_pixel_put(wolf->mlx, wolf->win, W_WIDTH / 2, (W_HEIGHT / 2) - 2, 0xFFFFFF);
	mlx_pixel_put(wolf->mlx, wolf->win, W_WIDTH / 2, (W_HEIGHT / 2) - 3, 0xFFFFFF);
	mlx_pixel_put(wolf->mlx, wolf->win, W_WIDTH / 2, (W_HEIGHT / 2) + 1, 0xFFFFFF);
	mlx_pixel_put(wolf->mlx, wolf->win, W_WIDTH / 2, (W_HEIGHT / 2) + 2, 0xFFFFFF);
	mlx_pixel_put(wolf->mlx, wolf->win, W_WIDTH / 2, (W_HEIGHT / 2) + 3, 0xFFFFFF);
}

void	show_info(t_env *wolf)
{
	mlx_string_put(wolf->mlx, wolf->win, 10, 10, 0xFFFFFF,
		"MOVE = W A S D || arrows");
	mlx_string_put(wolf->mlx, wolf->win, 10, 30, 0xFFFFFF,
		"SPRINT = SHIFT LEFT || RIGHT");
	mlx_string_put(wolf->mlx, wolf->win, 10, 50, 0xFFFFFF, "SHOW/HIDE INFO = I");
	mlx_string_put(wolf->mlx, wolf->win, 10, 70, 0xFFFFFF,
		"MUSIC CHANGE = < || >");
	mlx_string_put(wolf->mlx, wolf->win, 10, 90, 0xFFFFFF, "MUSIC OFF = O");
	mlx_string_put(wolf->mlx, wolf->win, 10, 110, 0xFFFFFF, "RESTART = R");
	mlx_string_put(wolf->mlx, wolf->win, 10, 130, 0xFFFFFF, "QUIT = ESC || Q");
}

void		change_music(int key, t_env *wolf)
{
	if (key == OFF)
		(wolf->flag.music == 1) ? system("pkill afplay") : 0;
	if (key == NEXT)
	{
		wolf->flag.music = 1;
		system("pkill afplay");
		system("afplay music/hero.mp3&");
	}
	if (key == PREV)
	{
		wolf->flag.music = 1;
		system("pkill afplay");
		system("afplay music/rising_sun.mp3&");
	}
}

void	fps(t_env *wolf)
{
	wolf->fps = (int)(1.0 / wolf->player.frametime);
	wolf->speed = ft_itoa(wolf->fps);
	mlx_string_put(wolf->mlx, wolf->win, W_WIDTH - 70, 0, 0xFFFF00, "FPS: ");
	mlx_string_put(wolf->mlx, wolf->win, W_WIDTH - 30, 0, 0xFFFF00, wolf->speed);
}
