/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:51:16 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/09 14:40:43 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	rgb_sanitize(int *channel)
{
	if (*channel < 0)
		*channel = 0;
	else if (*channel > 255)
		*channel = 255;
}

static t_rgb	calc_rgb(float coeff, t_data *data, t_rgb shape_c)
{
	t_rgb	res;

	res.r = coeff * data->scene->light->ratio * 255;
	res.g = res.r;
	res.b = res.r;
	res.r = (res.r + data->scene->alight->color.r * data->scene->alight->ratio) \
		/ 2;
	res.g = (res.g + data->scene->alight->color.g * data->scene->alight->ratio) \
		/ 2;
	res.b = (res.b + data->scene->alight->color.b * data->scene->alight->ratio) \
		/ 2;
	res.r *= (float)shape_c.r / 255;
	res.g *= (float)shape_c.g / 255;
	res.b *= (float)shape_c.b / 255;
	return (res);
}

t_uint	get_rgb(float coeff, t_data *data, t_ray *ray)
{
	t_rgb	res;
	t_rgb	shape_c;
	void	(*f[3])(t_data*, t_rgb*, t_ray*);

	set_rgb_shape(f);
	if (ray->shape_sel[0] == DI)
		ray->shape_sel[0] = CY;
	f[ray->shape_sel[0]](data, &shape_c, ray);
	res = calc_rgb(coeff, data, shape_c);
	rgb_sanitize(&res.r);
	rgb_sanitize(&res.g);
	rgb_sanitize(&res.b);
	return ((t_uint)(res.r * 0x00010000 + \
					res.g * 0x00000100 + \
					res.b + 0xFF000000));
}
