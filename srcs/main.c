/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:09:23 by vzamyati          #+#    #+#             */
/*   Updated: 2018/08/13 13:35:54 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

t_env		*init_env(void)
{
	t_env	*w;

	if (!(w = ft_memalloc(sizeof(t_env))))
		return (NULL);
	if (!((w->mlx = mlx_init())
		&& (w->win = mlx_new_window(w->mlx, W_WIDTH,
			W_HEIGHT, "w3d by vz"))
		&& (w->img = mlx_new_image(w->mlx, W_WIDTH, W_HEIGHT))
		&& (w->data = mlx_get_data_addr(w->img, &w->bpp,
			&w->sizeline, &w->endian))))
		delete_env(&w);
	w->ceil = 0x000000;
	w->floor = 0x646464;
	return (w);
}

void		next_step(char *av, t_env *w)
{
	open_file(av, w);
	init_player(w);
	mlx_hook(w->win, 2, 0, key_press, w);
	mlx_hook(w->win, 3, 0, key_release, w);
	mlx_hook(w->win, 17, 1L << 17, f_exit, w);
	mlx_loop_hook(w->mlx, game_loop, w);
	signal(SIGINT, exit(w));
	mlx_loop(w->mlx);
}

int			main(int ac, char **av)
{
	t_env	*w;

	if (ac != 2)
		ft_error("Incorrect amount of arguments. Try again.\n");
	if (!(w = init_env()))
		ft_error("Couldn't init mlx.\n");
	next_step(av[1], w);
	return (0);
}
