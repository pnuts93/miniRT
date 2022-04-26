/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:41:57 by pnuti             #+#    #+#             */
/*   Updated: 2022/04/26 11:53:42 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

float	inter_sphere(t_sph *sph, t_vector ray)
{
	float	b;
	float	c;
	float	res;
	float	*quad;
	t_point	*diff;

	diff = diff_vectors(ray.p1, sph->c);
	b = 2 * dot(ray.p2, *diff);
	c = dot(*diff, *diff) - powf(sph->d / 2, 2);
	free(diff);
	if ((powf(b, 2) - (4 * c)) < 0)
		return (-1);
	quad = quadratic(1, b, c);
	if (quad[0] < quad[1])
		res = quad[0];
	else
		res = quad[1];
	free(quad);
	return (res);
}

float	inter_cylinder(t_cyl *cyl, t_vector ray)
{
	float	a;
	float	b;
	float	c;
	float	*quad;
	float	res;

	if (cyl->phi != 0)
		rotate_cyl(cyl, &ray);
	a = powf(ray.p2.x, 2) + powf(ray.p2.y, 2);
	b = 2 * ((ray.p1.x - cyl->c.x) * ray.p2.x + (ray.p1.y - cyl->c.y) * ray.p2.y);
	c = powf(ray.p1.x - cyl->c.x, 2) + powf(ray.p1.y - cyl->c.y, 2) - powf(cyl->dia / 2, 2);
	if ((powf(b, 2) - (4 * a * c)) < 0)
		return (-1);
	quad = quadratic(a, b, c);
	float z1 = ray.p1.z + ray.p2.z * quad[0];
	float z2 = ray.p1.z + ray.p2.z * quad[1];
	if ((z1 >= cyl->c.z) && (z1 <= cyl->c.z + cyl->hei) ||
		(z2 >= cyl->c.z) && (z2 <= cyl->c.z + cyl->hei))
		{
			res = fmin_pos(quad[0], quad[1]);
			free(quad);
			return (res);
		}
	free(quad);
	return (-1);
}

float	inter_plane(t_pla *pla, t_vector ray)
{
	float	t;
	float	den;
	t_point	*tmp;

	den = dot(ray.p2, pla->nov);
	if (isequal(den, 0))
		return (-1);
	tmp = diff_vectors(pla->c, ray.p1);
	t = dot(pla->nov, *tmp) / den;
	free(tmp);
	if (t <= 0)
		return (-1);
	return (t);
}