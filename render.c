/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:36:04 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/13 19:16:25 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	project(t_data *data, t_vector ray, int i, int j)
{
	float	angle_w;
	float	angle_h;

	angle_w = (data->scene->camera[0].fov_w / 2) - ((data->scene->camera[0].fov_w / data->screen.w) * j);
	angle_h = (data->scene->camera[0].fov_h / 2) - ((data->scene->camera[0].fov_h / data->screen.h) * i);
	ray.x2 = data->scene->camera[0].x + data->scene->camera[0].vx + sinf(angle_w);
	ray.y2 = data->scene->camera[0].y + data->scene->camera[0].vy + cosf(angle_w);
	ray.z2 = data->scene->camera[0].z + data->scene->camera[0].vz + sinf(angle_h);
	if (inter_sphere(data, ray))
		mlx_pixel_put(data->mlx, data->win, j, i, 0XFFFFFFFF);
}

void	render(t_data *data)
{
	t_vector	ray;
	int	i;
	int	j;

	ray.x1 = data->scene->camera[0].x;
	ray.y1 = data->scene->camera[0].y;
	ray.z1 = data->scene->camera[0].z;
	i = 0;
	while (i < data->screen.h)
	{
		j = 0;
		while (j < data->screen.w)
		{
			project(data, ray, i, j);
			j++;
		}
		i++;
	}
}