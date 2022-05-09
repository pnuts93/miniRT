/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigonometry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:49:06 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/09 09:12:52 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

float	deg_to_rad(float a)
{
	return (PI * a / 180);
}

static float	get_quadrant(float x, float y)
{
	if (x >= 0 && y >= 0)
		return (1);
	else if (x < 0 && y >= 0)
		return (2);
	else if (x <= 0 && y < 0)
		return (3);
	else
		return (4);
}

float	get_angle_xy(t_point a)
{
	return (asin(absf(a.y) / sqrtf(powf(a.x, 2) + powf(a.y, 2))) * \
		get_quadrant(a.x, a.y));
}
