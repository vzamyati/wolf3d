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

void	load_textures(t_env *wolf)
{
	wolf->texture = (t_textur*)ft_memalloc(sizeof(t_textur) * 5);
	wolf->texture[0].ptr = mlx_xpm_file_to_image(wolf->mlx,
		"textures/redstone.xpm", &wolf->texture->width, &wolf->texture->height);
	wolf->texture[0].data = mlx_get_data_addr(wolf->texture[0].ptr,
	&wolf->texture[0].bpp, &wolf->texture[0].sizeline, &wolf->texture[0].endian);
	wolf->texture[1].ptr = mlx_xpm_file_to_image(wolf->mlx,
		"textures/greystone.xpm", &wolf->texture->width, &wolf->texture->height);
	wolf->texture[1].data = mlx_get_data_addr(wolf->texture[1].ptr,
	&wolf->texture[1].bpp, &wolf->texture[1].sizeline, &wolf->texture[1].endian);
	wolf->texture[2].ptr = mlx_xpm_file_to_image(wolf->mlx,
		"textures/bulestone.xpm", &wolf->texture->width, &wolf->texture->height);
	wolf->texture[2].data = mlx_get_data_addr(wolf->texture[2].ptr,
	&wolf->texture[2].bpp, &wolf->texture[2].sizeline, &wolf->texture[2].endian);
	wolf->texture[3].ptr = mlx_xpm_file_to_image(wolf->mlx,
		"textures/eagle.xpm", &wolf->texture->width, &wolf->texture->height);
	wolf->texture[3].data = mlx_get_data_addr(wolf->texture[3].ptr,
	&wolf->texture[3].bpp, &wolf->texture[3].sizeline, &wolf->texture[3].endian);
	wolf->texture[4].ptr = mlx_xpm_file_to_image(wolf->mlx,
		"textures/peterson.xpm", &wolf->texture->width, &wolf->texture->height);
	wolf->texture[4].data = mlx_get_data_addr(wolf->texture[4].ptr,
	&wolf->texture[4].bpp, &wolf->texture[4].sizeline, &wolf->texture[4].endian);
}

void	get_texture(t_env *wolf)
{
	if (wolf->map[wolf->rayc.map_x][wolf->rayc.map_y] == 1)
		wolf->rayc.texture_nb = 0;
	else if (wolf->map[wolf->rayc.map_x][wolf->rayc.map_y] == 2)
		wolf->rayc.texture_nb = 1;
	else if (wolf->map[wolf->rayc.map_x][wolf->rayc.map_y] == 3)
		wolf->rayc.texture_nb = 2;
	else if (wolf->map[wolf->rayc.map_x][wolf->rayc.map_y] == 4)
		wolf->rayc.texture_nb = 3;
	else if (wolf->map[wolf->rayc.map_x][wolf->rayc.map_y] == 5)
		wolf->rayc.texture_nb = 4;
}