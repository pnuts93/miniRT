/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:51:44 by pnuti             #+#    #+#             */
/*   Updated: 2022/06/06 09:58:15 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

static void	find_abc(t_cyl *cyl, t_ray *ray, float abc[3])
{
	t_point	w;

	abc[0] = dot(ray->p2, ray->p2) - powf(dot(ray->p2, cyl->nov), 2);
	w = diff_vectors(ray->p1, cyl->c);
	abc[1] = 2 * (dot(ray->p2, w) - dot(ray->p2, cyl->nov) * dot(w, cyl->nov));
	abc[2] = dot(w, w) - powf(dot(w, cyl->nov), 2) - powf(cyl->dia / 2, 2);
}

static float	check_disks(t_cyl *cyl, t_ray *ray, int n_disk)
{
	t_point	collision;
	t_point	v;
	float	den;
	float	t;

	den = dot(ray->p2, cyl->nov);
	if (!isequal(den, 0))
	{
		t = dot(cyl->nov, diff_vectors(sum_vectors(cyl->c, \
			mult_vect_scal(cyl->nov, cyl->hei * n_disk)), ray->p1)) / den;
		if (islessequal(t, 0))
			return (-1);
		collision = sum_vectors(ray->p1, mult_vect_scal(ray->p2, t));
		v = diff_vectors(collision, sum_vectors(cyl->c, \
			mult_vect_scal(cyl->nov, cyl->hei * n_disk)));
		if ((sqrtf(dot(v, v)) < cyl->dia / 2) && (t < ray->t || ray->t < 0))
		{
			ray->t = t;
			ray->shape_sel[0] = DI;
			ray->shape_sel[1] = cyl->n;
			ray->shape_sel[2] = n_disk;
			return (t);
		}
	}
	return (-1);
}

static float	check_inter(t_cyl *cyl, t_ray *ray, float res)
{
	float	cmp;

	cmp = dot(diff_vectors(sum_vectors(ray->p1, \
		mult_vect_scal(ray->p2, res)), cyl->c), cyl->nov);
	if (isgreaterequal(cmp, 0) && islessequal(cmp, cyl->hei))
		return (res);
	return (-1);
}

float	inter_cylinder(t_cyl *cyl, t_ray *ray)
{
	float	abc[3];
	float	res;
	float	tmp;

	tmp = fmin_pos(check_disks(cyl, ray, 0), check_disks(cyl, ray, 1));
	find_abc(cyl, ray, abc);
	if (islessequal(powf(abc[1], 2) - 4.0 * abc[0] * abc[2], 0) && tmp < 0)
		return (-1);
	res = quadratic(abc[0], abc[1], abc[2]);
	if ((tmp > 0 && tmp < res) || res < 0)
		return (-1);
	else if (isgreaterequal(res, 0))
		return (check_inter(cyl, ray, res));
	return (-1);
}
