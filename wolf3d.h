/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:09:38 by vzamyati          #+#    #+#             */
/*   Updated: 2018/07/03 14:09:41 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	WOLF3D_H
# define	WOLF3D_H

# include "./libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define W_HEIGHT		800
# define W_WIDTH 		800

# define ESC			53
# define Q				12

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
}						t_env;

int			f_exit(t_env *wolf);
int			key_events(int key, t_env *wolf);
void		delete_env(t_env **wolf);
t_env		*init_env(void);
void		ft_error(char *reason);

#endif