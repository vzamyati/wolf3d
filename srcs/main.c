/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:09:23 by vzamyati          #+#    #+#             */
/*   Updated: 2018/07/04 15:08:43 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_error(char *reason)
{
	ft_putstr_fd(reason, 2);
	exit (1);
}

int		main(int ac, char **av)
{
	t_env	*wolf;

	if (ac != 2)
		ft_error("Incorrect amount of arguments. Try again.\n");
	if (!(wolf = init_env()))
		ft_error("Couldn't init mlx.\n");
	open_file(av[1], wolf);
	init_player(wolf);
	mlx_hook(wolf->win, 2, 0, key_press, wolf);
	mlx_hook(wolf->win, 3, 0, key_release, wolf);
	mlx_hook(wolf->win, 17, 1L << 17, f_exit, wolf);
	mlx_loop_hook(wolf->mlx, game_loop, wolf);
	system("leaks wolf");
	mlx_loop(wolf->mlx);
	return (0);
}