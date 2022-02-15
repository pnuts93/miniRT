/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:07:14 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/15 11:52:49 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	set_p(t_point *p, float x, float y, float z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

void	import_p(t_point *p_src, t_point *p_dst)
{
	if (p_dst && p_src)
	{
		p_dst->x = p_src->x;
		p_dst->y = p_src->y;
		p_dst->z = p_src->z;
	}
}

/*
The function diff_p returns a set of XYZ coordinates, not a point, this is 
because it represents a directional vector, and it will be mostly used in
the dot product function
*/

t_point	*diff_p(t_point a, t_point b)
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

float	dot(t_point v1, t_point v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}