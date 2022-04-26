/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:07:19 by pnuti             #+#    #+#             */
/*   Updated: 2022/04/26 10:57:14 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_point	*norm_sphere(t_data *data, t_vector ray, float t, t_point collision)
{
	t_point	*res;

	res = diff_vectors(collision, data->scene->sph[data->shape_sel[1]]->c);
	normalise(res);
	return (res);
}

t_point	*norm_plane(t_data *data, t_vector ray, float t, t_point collision)
{
	t_point	*res;

	res = (t_point *)malloc(sizeof(t_point));
	import_p(&data->scene->pla[data->shape_sel[1]]->nov, res);
	return (res);
}

t_point	*norm_cylinder(t_data *data, t_vector ray, float t, t_point collision)
{
	t_point	*tmp;
	t_point	*tmp2;
	t_point	*tmp3;

	tmp = mult_vect_scal(data->scene->cyl[data->shape_sel[1]]->nov, data->scene->cyl[data->shape_sel[1]]->hei);
	normalise(tmp);
	tmp2 = diff_vectors(collision, data->scene->cyl[data->shape_sel[1]]->c);
	tmp3 = mult_vect_scal(*tmp2, dot(*tmp, *tmp2));
	free(tmp);
	free(tmp2);
	tmp = diff_vectors(collision, *tmp3);
	free(tmp3);
	normalise(tmp);
	return (tmp);
}
