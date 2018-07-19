/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:29:41 by vzamyati          #+#    #+#             */
/*   Updated: 2018/07/19 18:29:44 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	raycasting(t_env *wolf)
{
	int x;

	x = -1;
	wolf->rayc.position.x = wolf->player.position.x;
	wolf->rayc.position.y = wolf->player.position.y;
	while (++x < W_WIDTH)
	{
		calculate_ray(wolf, x);
		step(wolf);
	}
}

void	calculate_ray(t_env *wolf, int x)
{
	wolf->rayc.camera = 2 * x / (double)(W_WIDTH) - 1;
	wolf->rayc.direct.x = wolf->player.direct.x + wolf->player.plane.x
	* wolf->rayc.camera;
	wolf->rayc.direct.y = wolf->player.direct.y + wolf->player.plane.y
	* wolf->rayc.camera;
	wolf->rayc.map_x = (int)wolf->rayc.position.x;
	wolf->rayc.map_y = (int)wolf->rayc.position.y;
	wolf->rayc.delta.x = sqrt(1 + (wolf->rayc.direct.y * wolf->rayc.direct.y) /
		(wolf->rayc.direct.x * wolf->rayc.direct.x));
	wolf->rayc.delta.y = sqrt(1 + (wolf->rayc.direct.x * wolf->rayc.direct.x) /
		(wolf->rayc.direct.y * wolf->rayc.direct.y));
	wolf->rayc.hit = 0;
	wolf->rayc.hit_side = 0;
}

void	step(t_env *wolf)
{
	if (wolf->rayc.direct.x < 0)
	{
		wolf->rayc.step_x = -1;
		wolf->rayc.side.x = (wolf->rayc.position.x - (int)wolf->rayc.position.x) * 
			wolf->rayc.delta.x;
	}
	else
	{
		wolf->rayc.step_x = 1;
		wolf->rayc.side.x = ((int)wolf->rayc.position.x + 1 - wolf->rayc.position.x) * 
			wolf->rayc.delta.x;
	}
	if (wolf->rayc.direct.y < 0)
	{
		wolf->rayc.step_y = -1;
		wolf->rayc.side.y = (wolf->rayc.position.y - (int)wolf->rayc.position.y) * 
			wolf->rayc.delta.y;
	}
	else
	{
		wolf->rayc.step_y = 1;
		wolf->rayc.side.y = ((int)wolf->rayc.position.y + 1 - wolf->rayc.position.y) * 
			wolf->rayc.delta.y;
	}
}