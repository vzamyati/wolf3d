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

#include "wolf3d.h"

static void		validate_map1(char *buf, int i, t_env *wolf)
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
			if (len - 1 != wolf->map_width)
				ft_error("Wrong size!\n");
			len = 0;
		}
		i++;
	}
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		if (buf[i] == ' ')
			wolf->map_width--;
		i++;
	}
	ft_strdel(&buf);
}

static void		validate_map2(t_env *wolf)
{
	int			i;

	i = -1;
	while (++i < wolf->map_width)
		if (wolf->map[0][i] == 0 || wolf->map[wolf->map_height - 1][i] == 0)
			ft_error("opened map1\n");
	i = -1;
	while (++i < wolf->map_height)
		if (wolf->map[i][0] == 0 || wolf->map[i][wolf->map_width - 1] == 0)
			ft_error("opened map2\n");
	if (wolf->map[3][3] != 0)
		ft_error("no place\n");
}

static void		make_map(char *av, int i, t_env *wolf)
{
	char		*line;
	int			j;
	int			fd;
	int			k;

	fd = open(av, O_RDONLY);
	if (!(wolf->map = (int **)ft_memalloc(sizeof(int *) * wolf->map_height)))
		ft_error("Couldn't allocate memory.\n");
	while (get_next_line(fd, &line) > 0)
	{
		j = -1;
		k = 0;
		if (!(wolf->map[i] = ft_memalloc(sizeof(int) * wolf->map_width)))
			ft_error("Couldn't allocate memory.\n");
		while (++j < wolf->map_width)
		{
			if (line[k] == ' ')
				k++;
			wolf->map[i][j] = ft_atoi(&line[k]);
			k++;
		}
		i++;
		ft_strdel(&line);
	}
}

void			open_file(char *av, t_env *wolf)
{
	int			fd;
	int			i;
	char		*buf;

	i = 0;
	buf = ft_strnew(65536);
	if ((fd = open(av, O_RDONLY)) < 0 || (read(fd, buf, 65536)) < 1)
		ft_error("Couldn't open the file.\n");
	wolf->map_width = ft_linelen(buf);
	wolf->map_height = ft_countlines(buf);
	validate_map1(buf, i, wolf);
	close(fd);
	make_map(av, i, wolf);
	validate_map2(wolf);
}
