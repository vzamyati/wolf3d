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
	wolf->map_height = 0;
	wolf->map_width = 0;
	return (wolf);
}

void		init_player(t_env *wolf)
{
	wolf->player.s_move = 0.08;
	wolf->player.s_turn = 0.045;
	wolf->player.s_shift = 0.13;
	wolf->player.pos.x = 5;
	wolf->player.pos.y = 5;
	wolf->player.dirt.x = -1;
	wolf->player.dirt.y = 0;
	wolf->player.plane.x = 0;
	wolf->player.plane.y = 0.66;
	wolf->player.up = 0;
	wolf->player.down = 0;
	wolf->player.left = 0;
	wolf->player.right = 0;
	wolf->player.shift = 0;
	wolf->player.time = 0;
	wolf->player.oldtime = 0;
	load_textures(wolf);
}
