/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shadow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:07:57 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/05 09:42:27 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

float	get_shadow(t_data *data, t_point p1, t_point p2, float tlight)
{
	t_ray	ray;

	ray.p1 = p1;
	ray.p2 = p2;
	normalise(&ray.p2);
	get_shape(data, &ray, 1);
	if (ray.t < tlight && ray.t >= 0)
		return (0);
	return (1);
}