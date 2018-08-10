/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 13:09:44 by vzamyati          #+#    #+#             */
/*   Updated: 2018/08/09 13:09:45 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void		key_up(t_env *w)
{
	if (w->player.flag.shift)
	{
		if (w->map[(int)(w->player.pos.x + w->player.dirt.x *
		w->player.s_shift)][(int)w->player.pos.y] == 0)
			w->player.pos.x += w->player.dirt.x * w->player.s_shift;
		if (w->map[(int)w->player.pos.x][(int)(w->player.pos.y +
		w->player.dirt.y * w->player.s_shift)] == 0)
			w->player.pos.y += w->player.dirt.y * w->player.s_shift;
	}
	else
	{
		if (w->map[(int)(w->player.pos.x + w->player.dirt.x *
		w->player.s_move)][(int)w->player.pos.y] == 0)
			w->player.pos.x += w->player.dirt.x * w->player.s_move;
		if (w->map[(int)w->player.pos.x][(int)(w->player.pos.y +
		w->player.dirt.y * w->player.s_move)] == 0)
			w->player.pos.y += w->player.dirt.y * w->player.s_move;
	}
}

void		key_down(t_env *w)
{
	if (w->map[(int)(w->player.pos.x - w->player.dirt.x *
	w->player.s_move)][(int)w->player.pos.y] == 0)
		w->player.pos.x -= w->player.dirt.x * w->player.s_move;
	if (w->map[(int)w->player.pos.x][(int)(w->player.pos.y -
	w->player.dirt.y * w->player.s_move)] == 0)
		w->player.pos.y -= w->player.dirt.y * w->player.s_move;
}

void		key_left(t_env *w)
{
	double	tmp_x;

	tmp_x = w->player.dirt.x;
	w->player.dirt.x = w->player.dirt.x * cos(-w->player.s_rot) -
	w->player.dirt.y * sin(-w->player.s_rot);
	w->player.dirt.y = tmp_x * sin(-w->player.s_rot) +
	w->player.dirt.y * cos(-w->player.s_rot);
	tmp_x = w->player.plane.x;
	w->player.plane.x = w->player.plane.x * cos(-w->player.s_rot) -
	w->player.plane.y * sin(-w->player.s_rot);
	w->player.plane.y = tmp_x * sin(-w->player.s_rot) +
	w->player.plane.y * cos(-w->player.s_rot);
}

void		key_right(t_env *w)
{
	double	tmp_x;

	tmp_x = w->player.dirt.x;
	w->player.dirt.x = w->player.dirt.x * cos(w->player.s_rot) -
	w->player.dirt.y * sin(w->player.s_rot);
	w->player.dirt.y = tmp_x * sin(w->player.s_rot) +
	w->player.dirt.y * cos(w->player.s_rot);
	tmp_x = w->player.plane.x;
	w->player.plane.x = w->player.plane.x * cos(w->player.s_rot) -
	w->player.plane.y * sin(w->player.s_rot);
	w->player.plane.y = tmp_x * sin(w->player.s_rot) +
	w->player.plane.y * cos(w->player.s_rot);
}
