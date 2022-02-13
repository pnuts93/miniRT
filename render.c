/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:36:04 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/13 12:04:25 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	project(t_data *data, t_vector ray, int i, int j)
{
	float	angle_w;
	float	angle_h;

	angle_w = (data->camera.fov_w / 2) - ((data->camera.fov_w / data->screen.w) * j);
	angle_h = (data->camera.fov_h / 2) - ((data->camera.fov_h / data->screen.h) * i);
	ray.x2 = data->camera.x + data->camera.nov_x + sinf(angle_w);
	ray.y2 = data->camera.y + data->camera.nov_y + cosf(angle_w);
	ray.z2 = data->camera.z + data->camera.nov_z + sinf(angle_h);
	if (inter_sphere(data, ray))
		mlx_pixel_put(data->mlx, data->win, j, i, 0XFFFFFFFF);
}

void	render(t_data *data)
{
	t_vector	ray;
	int	i;
	int	j;

	ray.x1 = data->camera.x;
	ray.y1 = data->camera.y;
	ray.z1 = data->camera.z;
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