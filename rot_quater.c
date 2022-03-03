/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_quater.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:35:54 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/19 15:55:25 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

//	Rodrigues formula implementation

t_point	*rotate_quaternion(t_point v, t_point u, float radians)
{
	t_point	*tmp_res;
	t_point	*tmp1;
	t_point	*tmp2;

	tmp1 = mult_vect_scal(v, cosf(radians));
	tmp2 = cross(u, v);
	tmp_res = mult_vect_scal(*tmp2, sinf(radians));
	free(tmp2);
	tmp2 = sum_vectors(*tmp1, *tmp_res);
	free(tmp1);
	free(tmp_res);
	tmp1 = mult_vect_scal(u, dot(u, v) * (1 - cosf(radians)));
	tmp_res = sum_vectors(*tmp2, *tmp1);
	free(tmp1);
	free(tmp2);
	return (tmp_res);
}
