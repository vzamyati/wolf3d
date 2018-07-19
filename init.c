/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 17:59:10 by vzamyati          #+#    #+#             */
/*   Updated: 2018/07/19 17:59:12 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_env			*init_env(void)
{
	t_env *wolf;

	if (!(wolf = ft_memalloc(sizeof(t_env))))
		return (NULL);
	if (!((wolf->mlx = mlx_init())
		&& (wolf->win = mlx_new_window(wolf->mlx, W_WIDTH,
			W_HEIGHT, "wolf3d by vz"))
		&&  (wolf->img = mlx_new_image(wolf->mlx, W_WIDTH, W_HEIGHT))
		&& (wolf->data = mlx_get_data_addr(wolf->img, &wolf->bpp, 
			&wolf->sizeline, &wolf->endian))))
		delete_env(&wolf);
	wolf->ceil = 0x000000;
	wolf->floor = 0x646464;
	wolf->m_height = 0;
	wolf->m_width = 0;
	return (wolf);
}

t_player		init_player(void)
{
	t_player player;

	player.s_move = 0.08;
	player.s_turn = 0.045;
	player.s_shift = 0.13;
	player.up = 0;
	player.down = 0;
	player.left = 0;
	player.right = 0;
	player.shift = 0;
	player.position.x = 0;
	player.position.y = 0;
	player.direct.x = -1;
	player.direct.y = 0;
	player.plane.x = 0;
	player.plane.y = 0.66;
	return (player);
}
