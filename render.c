/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:36:04 by pnuti             #+#    #+#             */
/*   Updated: 2022/03/03 10:50:52 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	get_angles(t_cam *camera)
{
	camera->theta = get_angle_xy(camera->nov_i);
	if (isnan(camera->theta))
		camera->theta = 0;
	camera->phi = acosf(camera->nov_i.z);
}

void	project(t_data *data, t_vector ray, int i, int j)
{
	float	angle_w;
	float	angle_h;
	t_point	*tmp;
	t_point	*tmp2;
	t_point	*tmp3;

	angle_w = (data->scene->camera->fov_w / 2) - ((data->scene->camera->fov_w / data->screen.w) * (float)j);
	angle_h = (data->scene->camera->fov_h / 2) - ((data->scene->camera->fov_h / data->screen.h) * (float)i);
	ray.p2.x = sinf(modulef(data->scene->camera->phi + deg_to_rad(angle_h), PI)) * cosf(data->scene->camera->theta + deg_to_rad(angle_w));
	ray.p2.y = sinf(data->scene->camera->phi + deg_to_rad(angle_h)) * sinf(modulef(data->scene->camera->theta + deg_to_rad(angle_w), 2 * PI));
	ray.p2.z = cosf(data->scene->camera->phi + deg_to_rad(angle_h));
	//printf("%f|%f ", data->scene->camera->phi + deg_to_rad(angle_h), data->scene->camera->theta + deg_to_rad(angle_w));
	if (inter_sphere(data, ray))
		mlx_pixel_put(data->mlx, data->win, j, i, 0XFFFFFFFF);
}

void	render(t_data *data)
{
	t_vector	ray;
	int	i;
	int	j;

	import_p(&data->scene->camera->c, &ray.p1);
	get_angles(data->scene->camera);
	//printf("fov: %f\tw: %d\th: %d\n", data->scene->camera->fov_w, data->screen.w, data->screen.h);
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