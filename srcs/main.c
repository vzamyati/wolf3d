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

static void			open_file(char *av, t_env *w)
{
	int			fd;
	int			i;
	char		*buf;

	i = 0;
	buf = ft_strnew(100000);
	if ((fd = open(av, O_RDONLY)) < 0 || (read(fd, buf, 100000)) < 1 ||
		buf[i + 1] == '\n')
		ft_error("File is not valid. Try again\n");
	w->map_width = ft_linelen(buf);
	w->map_height = ft_countlines(buf);
	validate_map1(buf, i, w);
	close(fd);
	make_map(av, i, w);
	validate_map2(w);
}

static void			sighandler(int signum)
{
	(void)signum;
	ft_error("\nSignal was interrupted by the user.\n");
	exit(1);
}

static void			next_step(char *av, t_env *w)
{
	open_file(av, w);
	if (!((w->mlx = mlx_init())
		&& (w->win = mlx_new_window(w->mlx, W_WIDTH,
			W_HEIGHT, "w3d by vz"))
		&& (w->img = mlx_new_image(w->mlx, W_WIDTH, W_HEIGHT))
		&& (w->data = mlx_get_data_addr(w->img, &w->bpp,
			&w->sizeline, &w->endian))))
		delete_env(&w);
	init_player(w);
	mlx_hook(w->win, 2, 0, key_press, w);
	mlx_hook(w->win, 3, 0, key_release, w);
	mlx_hook(w->win, 17, 1L << 17, f_exit, w);
	mlx_mouse_hook(w->win, mouse_hook, w);
	mlx_loop_hook(w->mlx, game_loop, w);
	signal(SIGINT, sighandler);
	mlx_loop(w->mlx);
}

int					main(int ac, char **av)
{
	t_env	*w;

	if (ac != 2)
		ft_error("Incorrect amount of arguments. Try again.\n");
	if (!(w = ft_memalloc(sizeof(t_env))))
		ft_error("Couldn't allloce memory. Try again.\n");
	next_step(av[1], w);
	return (0);
}
