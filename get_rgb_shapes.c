/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_shapes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 07:45:50 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/09 07:58:47 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

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

void	set_rgb_shape(void (*f[3])(t_data*, t_rgb*, t_ray*))
{
	f[0] = &c_sph;
	f[1] = &c_pla;
	f[2] = &c_cyl;
}
