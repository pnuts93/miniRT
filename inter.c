/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:41:57 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/28 22:01:37 by pnuti            ###   ########.fr       */
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