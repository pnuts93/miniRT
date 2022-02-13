/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:41:57 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/13 18:14:09 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	inter_sphere(t_data *data, t_vector ray)
{
	float	a;
	float	b;
	float	c;
	float	res;

	a = powf(ray.x1 - ray.x2, 2) + powf(ray.y1 - ray.y2, 2) + powf(ray.z1 - ray.z2, 2);
	b = 2 * ((ray.x2 - ray.x1) * (ray.x1 - data->sphere.x) + (ray.y2 - ray.y1) * (ray.y1 - data->sphere.y) + (ray.z2 - ray.z1) * (ray.z1 - data->sphere.z));
	c = powf(data->sphere.x - ray.x1, 2) + powf(data->sphere.y - ray.y1, 2) + powf(data->sphere.z - ray.z1, 2) - powf(data->sphere.d / 2, 2);
	res = powf(b, 2) - (4 * a * c);
	if (res < 0)
		return (0);
	return (1);
}