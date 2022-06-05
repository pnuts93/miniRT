/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tra_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:05:30 by pnuti             #+#    #+#             */
/*   Updated: 2022/06/05 15:51:04 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	tra_sph(t_data *data, int obj_id, int dimension, float magnitude)
{
	if (dimension == 'x')
		data->scene->sph[obj_id]->c.x += magnitude;
	else if (dimension == 'y')
		data->scene->sph[obj_id]->c.y += magnitude;
	else if (dimension == 'z')
		data->scene->sph[obj_id]->c.z += magnitude;
}

void	tra_pla(t_data *data, int obj_id, int dimension, float magnitude)
{
	if (dimension == 'x')
		data->scene->pla[obj_id]->c.x += magnitude;
	else if (dimension == 'y')
		data->scene->pla[obj_id]->c.y += magnitude;
	else if (dimension == 'z')
		data->scene->pla[obj_id]->c.z += magnitude;
}

void	tra_cyl(t_data *data, int obj_id, int dimension, float magnitude)
{
	if (dimension == 'x')
		data->scene->cyl[obj_id]->c.x += magnitude;
	else if (dimension == 'y')
		data->scene->cyl[obj_id]->c.y += magnitude;
	else if (dimension == 'z')
		data->scene->cyl[obj_id]->c.z += magnitude;
}

void	tra_lig(t_data *data, int obj_id, int dimension, float magnitude)
{
	if (dimension == 'x' && !obj_id)
		data->scene->light->c.x += magnitude;
	else if (dimension == 'y' && !obj_id)
		data->scene->light->c.y += magnitude;
	else if (dimension == 'z' && !obj_id)
		data->scene->light->c.z += magnitude;
}

void	tra_cam(t_data *data, int obj_id, int dimension, float magnitude)
{
	if (dimension == 'x' && !obj_id)
		data->scene->camera->c.x += magnitude;
	else if (dimension == 'y' && !obj_id)
		data->scene->camera->c.y += magnitude;
	else if (dimension == 'z' && !obj_id)
		data->scene->camera->c.z += magnitude;
}
