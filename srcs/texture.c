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

#include "w3d.h"

void	load_textures2(t_env *w)
{
	w->texture[5].ptr = mlx_xpm_file_to_image(w->mlx,
		"textures/purplestone.xpm", &w->texture->width, &w->texture->height);
	w->texture[5].data = mlx_get_data_addr(w->texture[5].ptr,
	&w->texture[5].bpp, &w->texture[5].sizeline, &w->texture[5].endian);
	w->texture[6].ptr = mlx_xpm_file_to_image(w->mlx,
		"textures/mossy.xpm", &w->texture->width, &w->texture->height);
	w->texture[6].data = mlx_get_data_addr(w->texture[6].ptr,
	&w->texture[6].bpp, &w->texture[6].sizeline, &w->texture[6].endian);
	w->texture[7].ptr = mlx_xpm_file_to_image(w->mlx,
		"textures/colorstone.xpm", &w->texture->width, &w->texture->height);
	w->texture[7].data = mlx_get_data_addr(w->texture[7].ptr,
	&w->texture[7].bpp, &w->texture[7].sizeline, &w->texture[7].endian);
	w->texture[8].ptr = mlx_xpm_file_to_image(w->mlx,
		"textures/wood.xpm", &w->texture->width, &w->texture->height);
	w->texture[8].data = mlx_get_data_addr(w->texture[8].ptr,
	&w->texture[8].bpp, &w->texture[8].sizeline, &w->texture[8].endian);
}

void	load_textures(t_env *w)
{
	w->texture = (t_textur*)ft_memalloc(sizeof(t_textur) * 9);
	w->texture[0].ptr = mlx_xpm_file_to_image(w->mlx,
		"textures/redstone.xpm", &w->texture->width, &w->texture->height);
	w->texture[0].data = mlx_get_data_addr(w->texture[0].ptr,
	&w->texture[0].bpp, &w->texture[0].sizeline, &w->texture[0].endian);
	w->texture[1].ptr = mlx_xpm_file_to_image(w->mlx,
		"textures/greystone.xpm", &w->texture->width, &w->texture->height);
	w->texture[1].data = mlx_get_data_addr(w->texture[1].ptr,
	&w->texture[1].bpp, &w->texture[1].sizeline, &w->texture[1].endian);
	w->texture[2].ptr = mlx_xpm_file_to_image(w->mlx,
		"textures/bulestone.xpm", &w->texture->width, &w->texture->height);
	w->texture[2].data = mlx_get_data_addr(w->texture[2].ptr,
	&w->texture[2].bpp, &w->texture[2].sizeline, &w->texture[2].endian);
	w->texture[3].ptr = mlx_xpm_file_to_image(w->mlx,
		"textures/flag.xpm", &w->texture->width, &w->texture->height);
	w->texture[3].data = mlx_get_data_addr(w->texture[3].ptr,
	&w->texture[3].bpp, &w->texture[3].sizeline, &w->texture[3].endian);
	w->texture[4].ptr = mlx_xpm_file_to_image(w->mlx,
		"textures/eagle.xpm", &w->texture->width, &w->texture->height);
	w->texture[4].data = mlx_get_data_addr(w->texture[4].ptr,
	&w->texture[4].bpp, &w->texture[4].sizeline, &w->texture[4].endian);
	load_textures2(w);
}

void	get_texture(t_env *w)
{
	if (w->map[w->rayc.map_x][w->rayc.map_y] == 1)
		w->rayc.texture_nb = 0;
	else if (w->map[w->rayc.map_x][w->rayc.map_y] == 2)
		w->rayc.texture_nb = 1;
	else if (w->map[w->rayc.map_x][w->rayc.map_y] == 3)
		w->rayc.texture_nb = 2;
	else if (w->map[w->rayc.map_x][w->rayc.map_y] == 4)
		w->rayc.texture_nb = 3;
	else if (w->map[w->rayc.map_x][w->rayc.map_y] == 5)
		w->rayc.texture_nb = 4;
	else if (w->map[w->rayc.map_x][w->rayc.map_y] == 6)
		w->rayc.texture_nb = 5;
	else if (w->map[w->rayc.map_x][w->rayc.map_y] == 7)
		w->rayc.texture_nb = 6;
	else if (w->map[w->rayc.map_x][w->rayc.map_y] == 8)
		w->rayc.texture_nb = 7;
	else if (w->map[w->rayc.map_x][w->rayc.map_y] == 9)
		w->rayc.texture_nb = 8;
	else
		w->rayc.texture_nb = 0;
}
