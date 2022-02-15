/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:36:04 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/15 16:23:17 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	project(t_data *data, t_vector ray, int i, int j)
{
	float	angle_w;
	float	angle_h;

	angle_w = (data->scene->camera->fov_w / 2) - ((data->scene->camera->fov_w / data->screen.w) * j);
	angle_h = (data->scene->camera->fov_h / 2) - ((data->scene->camera->fov_h / data->screen.h) * i);
	set_p(&ray.p2, ray.p1.x + data->scene->camera->nov.x + sinf(angle_w * 3.14 / 180),
		ray.p1.y + data->scene->camera->nov.y + cosf(angle_w * 3.14 / 180),
		ray.p1.z + data->scene->camera->nov.z + sinf(angle_h * 3.14 / 180));
	//printf("ij: [%d,%d]\tx: %f\ty: %f\tz: %f\n", i, j, ray.p2.x, ray.p2.y, ray.p2.z);
	if (inter_sphere(data, ray))
		mlx_pixel_put(data->mlx, data->win, j, i, 0XFFFFFFFF);
}

void	render(t_data *data)
{
	t_vector	ray;
	int	i;
	int	j;

	import_p(&data->scene->camera->c, &ray.p1);
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