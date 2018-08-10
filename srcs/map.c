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

static void		validate_map1(char *buf, int i, t_env *w)
{
	int			len;

	len = 0;
	while (buf[i] && buf[i] != '\0')
	{
		if ((buf[i] < 48 || buf[i] > 57) && buf[i] != ' ' && buf[i] != '\n')
			ft_error("Wrong element!\n");
		len++;
		if (buf[i] == '\n')
		{
			if (len - 1 != w->map_width)
				ft_error("Wrong size!\n");
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

static void		validate_map2(t_env *w)
{
	int			i;

	i = -1;
	while (++i < w->map_width)
		if (w->map[0][i] == 0 || w->map[w->map_height - 1][i] == 0)
			ft_error("opened map1\n");
	i = -1;
	while (++i < w->map_height)
		if (w->map[i][0] == 0 || w->map[i][w->map_width - 1] == 0)
			ft_error("opened map2\n");
	if (w->map[3][3] != 0)
		ft_error("no place\n");
}

static void		make_map(char *av, int i, t_env *w)
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
			w->map[i][j] = ft_atoi(&line[k]);
			k++;
		}
		i++;
		ft_strdel(&line);
	}
}

void			open_file(char *av, t_env *w)
{
	int			fd;
	int			i;
	char		*buf;

	i = 0;
	buf = ft_strnew(65536);
	if ((fd = open(av, O_RDONLY)) < 0 || (read(fd, buf, 65536)) < 1)
		ft_error("Couldn't open the file.\n");
	w->map_width = ft_linelen(buf);
	w->map_height = ft_countlines(buf);
	validate_map1(buf, i, w);
	close(fd);
	make_map(av, i, w);
	validate_map2(w);
}
