/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 17:59:46 by vzamyati          #+#    #+#             */
/*   Updated: 2018/07/19 17:59:50 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			delete_env(t_env **wolf)
{
	if (!wolf || !(*wolf))
		return ;
	if ((*wolf)->win)
		mlx_destroy_window((*wolf)->mlx, (*wolf)->win);
	if ((*wolf)->img)
		mlx_destroy_image((*wolf)->mlx, (*wolf)->img);
	ft_memdel((void**)wolf);
}

int			f_exit(t_env *wolf)
{
	if (wolf != NULL)
		mlx_destroy_window(wolf->mlx, wolf->win);
	system("pkill afplay");
	exit(0);
	return (0);
}

void		ft_error(char *reason)
{
	ft_putstr_fd(reason, 2);
	exit (1);
}
