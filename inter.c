/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:41:57 by pnuti             #+#    #+#             */
/*   Updated: 2022/03/08 15:22:29 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	inter_sphere(t_data *data, t_vector ray)
{
	//float	a;
	float	b;
	float	c;
	float	res;
	t_point	*diff;

	//a = dot(ray.p2, ray.p2);
	diff = diff_vectors(ray.p1, data->scene->sph[0]->c);
	b = 2 * dot(ray.p2, *diff);
	c = dot(*diff, *diff) - powf(data->scene->sph[0]->d / 2, 2);
	//printf("%f ", acosf(dot(ray.p2, data->scene->camera->nov_i) / (sqrtf(dot(ray.p2, ray.p2)) * sqrtf(dot(data->scene->camera->nov_i, data->scene->camera->nov_i)))));
	//printf("%f|%f ", b, c);
	free(diff);
	res = powf(b, 2) - (4 * c);
	if (res < 0)
		return (0);
	return (1);
}

int	inter_cylinder(t_data *data, t_vector ray)
{
	float	a;
	float	b;
	float	c;
	float	*quad;

	a = powf(ray.p2.x, 2) + powf(ray.p2.y, 2);
	b = 2 * ((ray.p1.x - data->scene->cyl[0]->c.x) * ray.p2.x + (ray.p1.y - data->scene->cyl[0]->c.y) * ray.p2.y);
	c = powf(ray.p1.x - data->scene->cyl[0]->c.x, 2) + powf(ray.p1.y - data->scene->cyl[0]->c.y, 2) - powf(data->scene->cyl[0]->dia / 2, 2);
	if ((powf(b, 2) - (4 * a * c)) < 0)
		return (0);
	quad = quadratic(a, b, c);
	float z1 = ray.p1.z + ray.p2.z * quad[0];
	float z2 = ray.p1.z + ray.p2.z * quad[1];
	free(quad);
	if ((z1 >= data->scene->cyl[0]->c.z) && (z1 <= data->scene->cyl[0]->c.z + data->scene->cyl[0]->hei) ||
		(z2 >= data->scene->cyl[0]->c.z) && (z2 <= data->scene->cyl[0]->c.z + data->scene->cyl[0]->hei))
		return (1);
	return (0);
}

int	inter_plane(t_data *data, t_vector ray)
{
	float	t;
	float	den;
	t_point	*tmp;

	den = dot(ray.p2, data->scene->pla[0]->nov);
	if (isequal(den, 0))
		return (0);
	tmp = diff_vectors(data->scene->pla[0]->c, ray.p1);
	t = dot(data->scene->pla[0]->nov, *tmp) / den;
	free(tmp);
	if (t <= 0)
		return (0);
	return (1);
}