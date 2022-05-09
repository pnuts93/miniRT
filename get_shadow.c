/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shadow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:41:57 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/09 10:10:46 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

float	get_shadow(t_data *data, t_point p1, t_point p2, float tlight)
{
	t_ray	ray;

	ray.p1 = p1;
	ray.p2 = p2;
	normalise(&ray.p2);
	get_shape(data, &ray);
	if (ray.t < tlight && ray.t >= 0)
		return (0);
	return (1);
}
