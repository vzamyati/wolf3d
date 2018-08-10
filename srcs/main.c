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

t_env			*init_env(void)
{
	t_env *wolf;
 	if (!(wolf = ft_memalloc(sizeof(t_env))))
		return (NULL);
	if (!((wolf->mlx = mlx_init())
		&& (wolf->win = mlx_new_window(wolf->mlx, W_WIDTH,
			W_HEIGHT, "wolf3d by vz"))
		&&  (wolf->img = mlx_new_image(wolf->mlx, W_WIDTH, W_HEIGHT))
		&& (wolf->data = mlx_get_data_addr(wolf->img, &wolf->bpp, 
			&wolf->sizeline, &wolf->endian))))
		delete_env(&wolf);
	wolf->ceil = 0x000000;
	wolf->floor = 0x646464;
	return (wolf);
}


void	next_step(char *av, t_env *wolf)
{
	open_file(av, wolf);
	init_player(wolf);
	mlx_hook(wolf->win, 2, 0, key_press, wolf);
	mlx_hook(wolf->win, 3, 0, key_release, wolf);
	mlx_hook(wolf->win, 17, 1L << 17, f_exit, wolf);
	mlx_loop_hook(wolf->mlx, game_loop, wolf);
	system("leaks wolf");
	mlx_loop(wolf->mlx);
}

int		main(int ac, char **av)
{
	t_env	*wolf;

	if (ac != 2)
		ft_error("Incorrect amount of arguments. Try again.\n");
	if (!(wolf = init_env()))
		ft_error("Couldn't init mlx.\n");
	next_step(av[1], wolf);
	return (0);
}