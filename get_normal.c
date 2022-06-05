/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:07:19 by pnuti             #+#    #+#             */
/*   Updated: 2022/06/05 21:20:00 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_point	norm_sphere(t_data *data, t_ray *ray, t_point collision)
{
	t_point	res;

	res = diff_vectors(collision, data->scene->sph[ray->shape_sel[1]]->c);
	normalise(&res);
	return (res);
}

t_point	norm_plane(t_data *data, t_ray *ray, t_point collision)
{
	set_p(&collision, 0, 0, 0);
	if (dot(ray->p2, data->scene->pla[ray->shape_sel[1]]->nov) < 0)
		return (mult_vect_scal(data->scene->pla[ray->shape_sel[1]]->nov, 1));
	else
		return (mult_vect_scal(data->scene->pla[ray->shape_sel[1]]->nov, -1));
}

t_point	norm_cylinder(t_data *data, t_ray *ray, t_point collision)
{
	t_point	res;

	res = diff_vectors(collision, sum_vectors(\
		mult_vect_scal(data->scene->cyl[ray->shape_sel[1]]->nov, \
			dot(data->scene->cyl[ray->shape_sel[1]]->nov, \
			diff_vectors(collision, data->scene->cyl[ray->shape_sel[1]]->c))), \
		data->scene->cyl[ray->shape_sel[1]]->c));
	normalise(&res);
	return (res);
}

t_point	norm_disk(t_data *data, t_ray *ray, t_point collision)
{
	set_p(&collision, 0, 0, 0);
	if (dot(ray->p2, data->scene->cyl[ray->shape_sel[1]]->nov) < 0)
		return (mult_vect_scal(data->scene->cyl[ray->shape_sel[1]]->nov, 1));
	return (mult_vect_scal(data->scene->cyl[ray->shape_sel[1]]->nov, -1));
}
