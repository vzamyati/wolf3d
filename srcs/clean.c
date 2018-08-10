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

#include "w3d.h"

void		delete_env(t_env **w)
{
	if (!w || !(*w))
		return ;
	if ((*w)->win)
		mlx_destroy_window((*w)->mlx, (*w)->win);
	if ((*w)->img)
		mlx_destroy_image((*w)->mlx, (*w)->img);
	ft_memdel((void**)w);
}

int			f_exit(t_env *w)
{
	if (w != NULL)
		mlx_destroy_window(w->mlx, w->win);
	system("pkill afplay");
	exit(0);
	return (0);
}

void		ft_error(char *reason)
{
	ft_putstr_fd(reason, 2);
	exit(1);
}
