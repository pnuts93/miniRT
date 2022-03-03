/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:59:26 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/17 21:36:06 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_point	*cross(t_point a, t_point b)
{
	t_point	*res;

	res = (t_point *)malloc(sizeof(t_point));
	if (!res)
		return (NULL);
	res->x = a.y * b.z - a.z * b.y;
	res->y = a.z * b.x - a.x * b.z;
	res->z = a.x * b.y - a.y * b.x;
	return (res);
}

t_point *sum_vectors(t_point a, t_point b)
{
	t_point	*res;

	res = (t_point *)malloc(sizeof(t_point));
	if (!res)
		return (NULL);
	res->x = a.x + b.x;
	res->y = a.y + b.y;
	res->z = a.z + b.z;
	return (res);
}

t_point	*diff_vectors(t_point a, t_point b)
{
	t_point	*res;

	res = (t_point *)malloc(sizeof(t_point));
	if (!res)
		return (NULL);
	res->x = a.x - b.x;
	res->y = a.y - b.y;
	res->z = a.z - b.z;
	return (res);
}