/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:51:44 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/03 11:38:57 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

//	source: http://www.illusioncatalyst.com/notes_files/mathematics/line_cylinder_intersection.php

static void	find_abc(t_cyl *cyl, t_vector ray, float abc[3])
{
	t_point	*w;

	abc[0] = dot(ray.p2, ray.p2) - powf(dot(ray.p2, cyl->nov), 2);
	w = diff_vectors(ray.p1, cyl->c);
	abc[1] = 2 * (dot(ray.p2, *w) - dot(ray.p2, cyl->nov) * dot(*w, cyl->nov));
	abc[2] = dot(*w, *w) - powf(dot(*w, cyl->nov), 2) - powf(cyl->dia / 2, 2);
	free(w);
}

static float	check_inter(t_cyl *cyl, t_vector ray, float res)
{
	t_point	*tmp;
	t_point	*tmp2;
	float	cmp;

	tmp = mult_vect_scal(ray.p2, res);
	tmp2 = sum_vectors(ray.p1, *tmp);
	free(tmp);
	tmp = diff_vectors(*tmp2, cyl->c);
	cmp = dot(*tmp, cyl->nov);
	free(tmp);
	free(tmp2);
	if (cmp >= 0 && cmp <= cyl->hei)
		return (res);
	//else if
	return (-1);
}

float	inter_cylinder(t_cyl *cyl, t_vector ray)
{
	float	abc[3];
	float	*quad;
	float	res;

	find_abc(cyl, ray, abc);
	if ((powf(abc[1], 2) - 4 * abc[0] * abc[2]) <= 0)
		return (-1);
	quad = quadratic(abc[0], abc[1], abc[2]);
	res = fmin_pos(quad[0], quad[1]);
	free(quad);
	if (res >= 0)
		return (check_inter(cyl, ray, res));
	return (-1);
}