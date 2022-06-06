/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigonometry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:49:06 by pnuti             #+#    #+#             */
/*   Updated: 2022/06/06 12:05:13 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

float	deg_to_rad(float a)
{
	return (PI * a / 180);
}

float	get_angle_xy(t_point a)
{
	return (atan2f(a.y, a.x));
}
