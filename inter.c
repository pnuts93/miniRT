/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:41:57 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/15 15:53:40 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	inter_sphere(t_data *data, t_vector ray)
{
	float	a;
	float	b;
	float	c;
	float	res;
	t_point	*diff;

	a = dot(ray.p2, ray.p2);
	diff = diff_p(data->scene->sph[0]->c, ray.p1);
	b = 2 * dot(ray.p2, *diff);
	c = dot(*diff, *diff) - powf(data->scene->sph[0]->r, 2);
	free(diff);
	res = powf(b, 2) - (4 * a * c);
	//printf("a: %f\tb: %f\tc: %f\tres: %f\n", a, b, c, res);
	if (res < 0)
		return (0);
	return (1);
}