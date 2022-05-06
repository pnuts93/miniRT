/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:12:27 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/05 17:19:25 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

float	inter_plane(t_pla *pla, t_ray *ray)
{
	float	t;
	float	den;

	den = dot(ray->p2, pla->nov);
	if (isequal(den, 0))
		return (-1);
	t = dot(pla->nov, diff_vectors(pla->c, ray->p1)) / den;
	if (t < 0 || isequal(t, 0))
		return (-1);
	return (t);
}
