/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:07:19 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/03 09:42:41 by pnuti            ###   ########.fr       */
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

	tmp2 = diff_vectors(collision, data->scene->cyl[data->shape_sel[1]]->c);
	tmp3 = mult_vect_scal(data->scene->cyl[data->shape_sel[1]]->nov, dot(data->scene->cyl[data->shape_sel[1]]->nov, *tmp2));
	free(tmp2);
	tmp2 = sum_vectors(*tmp3, data->scene->cyl[data->shape_sel[1]]->c);
	tmp = diff_vectors(collision, *tmp2);
	free(tmp3);
	free(tmp2);
	normalise(tmp);
	return (tmp);
}
