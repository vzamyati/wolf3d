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

int		textures_load(t_env *w, int nbr, char *path)
{
	w->texture[nbr].ptr = mlx_xpm_file_to_image(w->mlx,
		path, &w->texture[nbr].width, &w->texture[nbr].height);
	if (!w->texture[nbr].ptr)
		return (0);
	w->texture[nbr].data = mlx_get_data_addr(w->texture[nbr].ptr,
		&w->texture[nbr].bpp, &w->texture[nbr].sizeline,
		&w->texture[nbr].endian);
	if (!w->texture[nbr].data)
		return (0);
	return (1);
}

void	load_weapon(t_env *w)
{
	w->weapon.shots = (t_textur*)ft_memalloc(sizeof(t_textur) * 2);
	w->weapon.shotgun = mlx_xpm_file_to_image(w->mlx,
	"textures/0.xpm", &w->weapon.width, &w->weapon.height);
	if (!w->weapon.shotgun)
		ft_error("Have problems with textures' files.\n");
	w->weapon.shots[0].ptr = mlx_xpm_file_to_image(w->mlx,
	"textures/1.xpm", &w->weapon.shots[0].width,
	&w->weapon.shots[0].height);
	if (!w->weapon.shots[0].ptr)
		ft_error("Have problems with textures' files.\n");
}

void	load_textures(t_env *w)
{
	w->texture = (t_textur*)ft_memalloc(sizeof(t_textur) * 9);
	if (!(textures_load(w, 0, "textures/redstone.xpm")))
		ft_error("Have problems with textures' files.\n");
	if (!(textures_load(w, 1, "textures/greystone.xpm")))
		ft_error("Have problems with textures' files.\n");
	if (!(textures_load(w, 2, "textures/bulestone.xpm")))
		ft_error("Have problems with textures' files.\n");
	if (!(textures_load(w, 3, "textures/flag.xpm")))
		ft_error("Have problems with textures' files.\n");
	if (!(textures_load(w, 4, "textures/eagle.xpm")))
		ft_error("Have problems with textures' files.\n");
	if (!(textures_load(w, 5, "textures/purplestone.xpm")))
		ft_error("Have problems with textures' files.\n");
	if (!(textures_load(w, 6, "textures/mossy.xpm")))
		ft_error("Have problems with textures' files.\n");
	if (!(textures_load(w, 7, "textures/colorstone.xpm")))
		ft_error("Have problems with textures' files.\n");
	if (!(textures_load(w, 8, "textures/wood.xpm")))
		ft_error("Have problems with textures' files.\n");
	load_weapon(w);
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
