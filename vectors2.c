/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:59:26 by pnuti             #+#    #+#             */
/*   Updated: 2022/06/06 10:25:52 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_point	cross(t_point a, t_point b)
{
	t_point	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}

t_point	sum_vectors(t_point a, t_point b)
{
	t_point	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_point	diff_vectors(t_point a, t_point b)
{
	t_point	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

void	normalise(t_point *v)
{
	float	magnitude;

	magnitude = sqrtf(dot(*v, *v));
	if (!magnitude)
		return ;
	v->x /= magnitude;
	v->y /= magnitude;
	v->z /= magnitude;
	if (isequal(v->x, 0))
		v->x = 0;
	if (isequal(v->y, 0))
		v->y = 0;
	if (isequal(v->z, 0))
		v->z = 0;
}
