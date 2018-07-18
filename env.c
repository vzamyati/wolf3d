/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:26:45 by vzamyati          #+#    #+#             */
/*   Updated: 2018/07/06 16:26:47 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		delete_env(t_env **wolf)
{
	if (!wolf || !(*wolf))
		return ;
	if ((*wolf)->win)
		mlx_destroy_window((*wolf)->mlx, (*wolf)->win);
	if ((*wolf)->img)
		mlx_destroy_image((*wolf)->mlx, (*wolf)->img);
	ft_memdel((void**)wolf);
}

t_env		*init_env(void)
{
	t_env *wolf;

	if (!(wolf = ft_memalloc(sizeof(t_env))))
		return (NULL);
	if (!((wolf->mlx = mlx_init())
		&& (wolf->win = mlx_new_window(wolf->mlx, W_WIDTH, W_HEIGHT, "wolf3d by vz"))
		&&  (wolf->img = mlx_new_image(wolf->mlx, W_WIDTH, W_HEIGHT))))
		delete_env(&wolf);
	return (wolf);
}