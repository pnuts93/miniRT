/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shadow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:07:57 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/02 10:20:18 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

float	get_shadow(t_data *data, t_point *p1, t_point *p2, float tlight)
{
	t_vector	ray;
	float		t;

	import_p(p1, &ray.p1);
	import_p(p2, &ray.p2);
	t = get_shape(data, ray, 1);
	if (t < tlight && t >= 0)
		return (0);
	return (1);
}