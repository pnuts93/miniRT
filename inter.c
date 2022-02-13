/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:41:57 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/13 19:20:20 by pnuti            ###   ########.fr       */
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
	b = 2 * ((ray.x2 - ray.x1) * (ray.x1 - data->scene->sph[0]->x) + (ray.y2 - ray.y1) * (ray.y1 - data->scene->sph[0]->y) + (ray.z2 - ray.z1) * (ray.z1 - data->scene->sph[0]->z));
	c = powf(data->scene->sph[0]->x - ray.x1, 2) + powf(data->scene->sph[0]->y - ray.y1, 2) + powf(data->scene->sph[0]->z - ray.z1, 2) - powf(data->scene->sph[0]->d / 2, 2);
	res = powf(b, 2) - (4 * a * c);
	if (res < 0)
		return (0);
	return (1);
}