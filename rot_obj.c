/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:13:18 by pnuti             #+#    #+#             */
/*   Updated: 2022/06/06 10:14:05 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	rot_pla(t_data *data, int obj_id, int dimension, float magnitude)
{
	data->scene->pla[obj_id]->nov = rotate_axis(deg_to_rad(magnitude), \
		data->scene->pla[obj_id]->nov, dimension);
	normalise(&data->scene->pla[obj_id]->nov);
}

void	rot_cyl(t_data *data, int obj_id, int dimension, float magnitude)
{
	data->scene->cyl[obj_id]->nov = rotate_axis(deg_to_rad(magnitude), \
		data->scene->cyl[obj_id]->nov, dimension);
	normalise(&data->scene->cyl[obj_id]->nov);
}

void	rot_cam(t_data *data, int obj_id, int dimension, float magnitude)
{
	if (!obj_id)
	{
		data->scene->camera->nov_i = rotate_axis(deg_to_rad(magnitude), \
		data->scene->camera->nov_i, dimension);
		normalise(&data->scene->camera->nov_i);
	}
}
