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

void		make_map(char *line, int **map, int i, t_env *wolf)
{
	char 	**split_line;
	int 	j;

	j = 0;
	if (!(map[i] = ft_memalloc(sizeof(int) * wolf->map_width)))
		ft_error("Couldn't allocate memory.\n");
	split_line = ft_strsplit(line, ' ');
	free(line);
	while (split_line[j] != '\0')
	{
		map[i][j] = ft_atoi(split_line[j]);
		printf("map[%d][%d] - %d\n", i, j, map[i][j]);
		j++;
	}
	ft_free(&split_line);
}

void	read_data(int fd, t_env *wolf)
{
	char 	*line;
	char	**map;
	int		i;

	i = 0;
	if (get_next_line(fd, &line) <= 0)
		ft_error("Couldn't read the map.\n");
	map = ft_strsplit(line, ' ');
	free(line);
	while (map[i] != '\0')
		i++;
	if (i != 4) //parametrs of the map
		ft_error("Error map.\n");
	wolf->map_height = ft_atoi(map[0]);
	wolf->map_width = ft_atoi(map[1]);
	wolf->player.pos.x = ft_atoi(map[2]) + 0.5;
	wolf->player.pos.y = ft_atoi(map[3]) + 0.5;
	ft_free(&map);
}

void	read_map_data(int fd, t_env *wolf)
{
	char 	*line;
	int		**map;
	size_t	i;

	i = 0;
	read_data(fd, wolf);
	if (!(map = (int **)ft_memalloc(sizeof(int *) * wolf->map_height)))
		ft_error("Couldn't allocate memory.\n");
	while (get_next_line(fd, &line))
	{
		make_map(line, map, i, wolf);
		i++;
	}
	wolf->map = map;
}

void 	open_file(char *av, t_env *wolf)
{
	int fd;

	if ((fd = open(av, O_RDONLY)) < 0)
		ft_error("Couldn't open the file.\n");
	read_map_data(fd, wolf);
	close(fd);
}
