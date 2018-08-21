/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:29:42 by vzamyati          #+#    #+#             */
/*   Updated: 2018/07/19 14:29:46 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void		validate_map1(char *buf, int i, t_env *w)
{
	int			len;

	len = 0;
	while (buf[i] && buf[i] != '\0')
	{
		if ((buf[i] < 48 || buf[i] > 57) && buf[i] != ' ' && buf[i] != '\n')
			ft_error("Wrong element! Try again\n");
		len++;
		if (buf[i] == '\n')
		{
			if (len - 1 != w->map_width)
				ft_error("Wrong size! Try again\n");
			len = 0;
		}
		i++;
	}
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		if (buf[i] == ' ')
			w->map_width--;
		i++;
	}
	ft_strdel(&buf);
}

int			check_position(t_env *w)
{
	int		i;
	int		j;
	int		v;

	i = -1;
	j = -1;
	v = 0;
	while (++i < w->map_height)
	{
		j = -1;
		while (++j < w->map_width)
			if ((v = get_position(w, j, i)) == 0)
				break ;
		if (!v)
			return (1);
	}
	return (0);
}

void		validate_map2(t_env *w)
{
	int			i;

	i = -1;
	while (++i < w->map_width)
		if (w->map[0][i] == 0 || w->map[w->map_height - 1][i] == 0)
			ft_error("The map is opened. Try again\n");
	i = -1;
	while (++i < w->map_height)
		if (w->map[i][0] == 0 || w->map[i][w->map_width - 1] == 0)
			ft_error("The map is opened. Try again\n");
	if (!check_position(w))
		ft_error("Couldn't place the player. Try again\n");
}

void		check_value(t_env *w, int i, int j)
{
	if (w->map[i][j] > 2147483647)
		w->map[i][j] = 1;
}

void		make_map(char *av, int i, t_env *w)
{
	char		*line;
	int			j;
	int			fd;
	int			k;

	fd = open(av, O_RDONLY);
	if (!(w->map = (int **)ft_memalloc(sizeof(int *) * w->map_height)))
		ft_error("Couldn't allocate memory.\n");
	while (get_next_line(fd, &line) > 0)
	{
		j = -1;
		k = 0;
		if (!(w->map[i] = ft_memalloc(sizeof(int) * w->map_width)))
			ft_error("Couldn't allocate memory.\n");
		while (++j < w->map_width)
		{
			if (line[k] == ' ')
				k++;
			w->map[i][j] = ft_atol_base(&line[k], 10);
			check_value(w, i, j);
			k++;
		}
		i++;
		ft_strdel(&line);
	}
}
