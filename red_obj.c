/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:23:36 by pnuti             #+#    #+#             */
/*   Updated: 2022/06/05 15:58:47 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	red_sph(t_data *data, int obj_id, int dimension, float magnitude)
{
	if (dimension == 'd')
		data->scene->sph[obj_id]->d = magnitude;
}

void	red_cyl(t_data *data, int obj_id, int dimension, float magnitude)
{
	if (dimension == 'd')
		data->scene->cyl[obj_id]->dia = magnitude;
	else if (dimension == 'h')
		data->scene->cyl[obj_id]->hei = magnitude;
}
