/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:12:27 by pnuti             #+#    #+#             */
/*   Updated: 2022/04/27 13:12:43 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

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
