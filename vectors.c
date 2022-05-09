/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:07:14 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/09 09:14:08 by pnuti            ###   ########.fr       */
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

float	dot(t_point v1, t_point v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_point	mult_vect_scal(t_point v, float s)
{
	t_point	res;

	set_p(&res, v.x * s, v.y * s, v.z * s);
	return (res);
}
