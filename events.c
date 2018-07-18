/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:25:57 by vzamyati          #+#    #+#             */
/*   Updated: 2018/07/06 16:25:58 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			f_exit(t_env *wolf)
{
	if (wolf != NULL)
	{
		mlx_destroy_window(wolf->mlx, wolf->win);
		free(wolf);
	}
	exit(0);
	return (0);
}

int			key_events(int key, t_env *wolf)
{
	if (key == ESC || key == Q)
		f_exit(wolf);
	return (0);
}