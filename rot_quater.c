/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_quater.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:35:54 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/05 09:15:18 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

//	Rodrigues formula implementation

t_point	rotate_quaternion(t_point v, t_point u, float radians)
{
	return (sum_vectors(
			sum_vectors(
				mult_vect_scal(v, cosf(radians)),
				mult_vect_scal(cross(u, v), sinf(radians))),
			mult_vect_scal(u, dot(u, v) * (1 - cosf(radians)))));
}
