/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:55:06 by vzamyati          #+#    #+#             */
/*   Updated: 2018/08/09 14:55:07 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		get_position(t_env *wolf, int x, int y)
{
	if (x < 0 || y < 0 || x > wolf->map_width - 1 || y > wolf->map_height - 1)
		return (0);
	return (wolf->map[y][x]);
}

void		place_player(t_env *wolf)
{
	int		i;
	int		j;
	int		v;

	i = -1;
	j = -1;
	v = 0;
	while (++i < wolf->map_height)
	{
		j = -1;
		while (++j < wolf->map_width)
			if (!(v = get_position(wolf, j, i)))
				break ;
		if (!v)
			break ;
	}
	wolf->player.pos.x = j + 0.5;
	wolf->player.pos.y = i + 0.5;
}

void		init_player(t_env *wolf)
{
	place_player(wolf);
	wolf->player.s_shift = 0.2;
	wolf->player.dirt.x = 1;
	wolf->player.dirt.y = 0;
	wolf->player.plane.x = 0;
	wolf->player.plane.y = 0.66;
	wolf->player.flag.up = 0;
	wolf->player.flag.down = 0;
	wolf->player.flag.left = 0;
	wolf->player.flag.right = 0;
	wolf->player.flag.shift = 0;
	wolf->player.time = 0;
	wolf->player.oldtime = 0;
	wolf->flag.info = 1;
	wolf->flag.music = 0;
	load_textures(wolf);
}