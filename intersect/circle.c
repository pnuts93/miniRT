/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:12:59 by pnuti             #+#    #+#             */
/*   Updated: 2022/04/27 13:13:13 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

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
