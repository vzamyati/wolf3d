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

#include "wolf3d.h"

void		key_up(t_env *wolf)
{
	if (wolf->player.flag.shift)
	{
		if (wolf->map[(int)(wolf->player.pos.x + wolf->player.dirt.x *
		wolf->player.s_shift)][(int)wolf->player.pos.y] == 0)
			wolf->player.pos.x += wolf->player.dirt.x * wolf->player.s_shift;
		if (wolf->map[(int)wolf->player.pos.x][(int)(wolf->player.pos.y +
		wolf->player.dirt.y * wolf->player.s_shift)] == 0)
			wolf->player.pos.y += wolf->player.dirt.y * wolf->player.s_shift;
	}
	else
	{
		if (wolf->map[(int)(wolf->player.pos.x + wolf->player.dirt.x *
		wolf->player.s_move)][(int)wolf->player.pos.y] == 0)
			wolf->player.pos.x += wolf->player.dirt.x * wolf->player.s_move;
		if (wolf->map[(int)wolf->player.pos.x][(int)(wolf->player.pos.y +
		wolf->player.dirt.y * wolf->player.s_move)] == 0)
			wolf->player.pos.y += wolf->player.dirt.y * wolf->player.s_move;
	}
}

void		key_down(t_env *wolf)
{
	if (wolf->map[(int)(wolf->player.pos.x - wolf->player.dirt.x *
	wolf->player.s_move)][(int)wolf->player.pos.y] == 0)
		wolf->player.pos.x -= wolf->player.dirt.x * wolf->player.s_move;
	if (wolf->map[(int)wolf->player.pos.x][(int)(wolf->player.pos.y -
	wolf->player.dirt.y * wolf->player.s_move)] == 0)
		wolf->player.pos.y -= wolf->player.dirt.y * wolf->player.s_move;
}

void		key_left(t_env *wolf)
{
	double	tmp_x;

	tmp_x = wolf->player.dirt.x;
	wolf->player.dirt.x = wolf->player.dirt.x * cos(-wolf->player.s_rot) -
	wolf->player.dirt.y * sin(-wolf->player.s_rot);
	wolf->player.dirt.y = tmp_x * sin(-wolf->player.s_rot) +
	wolf->player.dirt.y * cos(-wolf->player.s_rot);
	tmp_x = wolf->player.plane.x;
	wolf->player.plane.x = wolf->player.plane.x * cos(-wolf->player.s_rot) -
	wolf->player.plane.y * sin(-wolf->player.s_rot);
	wolf->player.plane.y = tmp_x * sin(-wolf->player.s_rot) +
	wolf->player.plane.y * cos(-wolf->player.s_rot);
}

void		key_right(t_env *wolf)
{
	double	tmp_x;

	tmp_x = wolf->player.dirt.x;
	wolf->player.dirt.x = wolf->player.dirt.x * cos(wolf->player.s_rot) -
	wolf->player.dirt.y * sin(wolf->player.s_rot);
	wolf->player.dirt.y = tmp_x * sin(wolf->player.s_rot) +
	wolf->player.dirt.y * cos(wolf->player.s_rot);
	tmp_x = wolf->player.plane.x;
	wolf->player.plane.x = wolf->player.plane.x * cos(wolf->player.s_rot) -
	wolf->player.plane.y * sin(wolf->player.s_rot);
	wolf->player.plane.y = tmp_x * sin(wolf->player.s_rot) +
	wolf->player.plane.y * cos(wolf->player.s_rot);
}