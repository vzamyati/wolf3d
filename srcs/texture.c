/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:00:21 by vzamyati          #+#    #+#             */
/*   Updated: 2018/07/19 18:00:22 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	texture(t_env *wolf)
{
	wolf->texture = (t_textur*)ft_memalloc(sizeof(t_textur) * 2);
	wolf->texture[0].ptr = mlx_xpm_file_to_image(wolf->mlx,
		"textures/redstone.xpm", &wolf->texture->width, &wolf->texture->height);
	wolf->texture[0].data = mlx_get_data_addr(wolf->texture[0].ptr,
	&wolf->texture[0].bpp, &wolf->texture[0].sizeline, &wolf->texture[0].endian);
}

void	texture_n(t_env *wolf)
{
	if (wolf->map[wolf->ray.map_x][wolf->ray.map_y] == 1)
		wolf->scene.t_n = 0;
}