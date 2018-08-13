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

#include "w3d.h"

int			get_position(t_env *w, int x, int y)
{
	if (x < 0 || y < 0 || x > w->map_width - 1 || y > w->map_height - 1)
		return (0);
	return (w->map[y][x]);
}

void		place_player(t_env *w)
{
	int		i;
	int		j;
	int		v;

	i = -1;
	j = -1;
	v = 0;
	while (++i < w->map_height)
	{
		j = -1;
		while (++j < w->map_width)
			if (!(v = get_position(w, j, i)))
				break ;
		if (!v)
			break ;
	}
	w->player.pos.x = j + 0.5;
	w->player.pos.y = i + 0.5;
}

void		init_player(t_env *w)
{
	place_player(w);
	w->player.s_shift = 0.2;
	w->player.dirt.x = 1;
	w->player.dirt.y = 0;
	w->player.plane.x = 0;
	w->player.plane.y = 0.66;
	w->player.flag.up = 0;
	w->player.flag.down = 0;
	w->player.flag.left = 0;
	w->player.flag.right = 0;
	w->player.flag.shift = 0;
	w->flag.texture = 0;
	w->player.time = 0;
	w->player.oldtime = 0;
	w->flag.info = 1;
	w->flag.music = 0;
	load_textures(w);
}
