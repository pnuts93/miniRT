/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:51:16 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/05 15:36:46 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	rgb_sanitize(int *channel)
{
	if (*channel < 0)
		*channel = 0;
	else if (*channel > 255)
		*channel = 255;
}

static void	c_sph(t_data *data, t_rgb *c, t_ray *ray)
{
	c->r = data->scene->sph[ray->shape_sel[1]]->color.r;
	c->g = data->scene->sph[ray->shape_sel[1]]->color.g;
	c->b = data->scene->sph[ray->shape_sel[1]]->color.b;
}

static void	c_pla(t_data *data, t_rgb *c, t_ray *ray)
{
	c->r = data->scene->pla[ray->shape_sel[1]]->color.r;
	c->g = data->scene->pla[ray->shape_sel[1]]->color.g;
	c->b = data->scene->pla[ray->shape_sel[1]]->color.b;
}

static void	c_cyl(t_data *data, t_rgb *c, t_ray *ray)
{
	c->r = data->scene->cyl[ray->shape_sel[1]]->color.r;
	c->g = data->scene->cyl[ray->shape_sel[1]]->color.g;
	c->b = data->scene->cyl[ray->shape_sel[1]]->color.b;
}

t_uint	get_rgb(float coeff, t_data *data, t_ray *ray)
{
	t_rgb	res;
	t_rgb	shape_c;
	void	(*f[3])(t_data *data, t_rgb *c, t_ray *ray);

	f[0] = &c_sph;
	f[1] = &c_pla;
	f[2] = &c_cyl;
	if (ray->shape_sel[0] == DI)
		ray->shape_sel[0] = CY; 
	f[ray->shape_sel[0]](data, &shape_c, ray);
	res.r = coeff * data->scene->light->ratio * 255;
	res.g = res.r;
	res.b = res.r;
	res.r = (res.r + data->scene->alight->color.r * data->scene->alight->ratio) / 2;
	res.g = (res.g + data->scene->alight->color.g * data->scene->alight->ratio) / 2;
	res.b = (res.b + data->scene->alight->color.b * data->scene->alight->ratio) / 2;
	res.r *= (float)shape_c.r / 255;
	res.g *= (float)shape_c.g / 255;
	res.b *= (float)shape_c.b / 255;
	rgb_sanitize(&res.r);
	rgb_sanitize(&res.g);
	rgb_sanitize(&res.b);
	return ((t_uint)(res.r * 0x00010000 + res.g * 0x00000100 + res.b + 0xFF000000));
}