/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:36:04 by pnuti             #+#    #+#             */
/*   Updated: 2022/06/06 10:39:52 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_uint	get_pixel(t_data *data, t_ray *ray, \
	t_point (*f)(t_data*, t_ray*, t_point))
{
	t_point	collision;
	t_point	v_light;
	t_point	norm;
	float	coeff;

	collision = sum_vectors(ray->p1, mult_vect_scal(ray->p2, ray->t));
	norm = f(data, ray, collision);
	v_light = diff_vectors(data->scene->light->c, collision);
	coeff = dot(v_light, norm);
	coeff *= coeff > 0;
	coeff *= 1 / sqrtf(dot(v_light, v_light));
	coeff *= get_shadow(data, collision, v_light, sqrtf(dot(v_light, v_light)));
	return (get_rgb(coeff, data, ray));
}

void	project(t_data *data, t_ray ray, int i, int j)
{
	float	angle_w;
	float	angle_h;
	t_point	(*f[4])(t_data*, t_ray*, t_point);

	f[0] = &norm_sphere;
	f[1] = &norm_plane;
	f[2] = &norm_cylinder;
	f[3] = &norm_disk;
	angle_w = (data->scene->camera->fov_w / 2) - \
		((data->scene->camera->fov_w / data->screen.w) * (float)j);
	angle_h = (data->scene->camera->fov_h / 2) - \
		((data->scene->camera->fov_h / data->screen.h) * (float)i);
	ray.p2.x = sinf(modulef((PI / 2) + deg_to_rad(angle_h), PI)) * \
		cosf(data->scene->camera->theta + deg_to_rad(angle_w));
	ray.p2.y = sinf((PI / 2) + deg_to_rad(angle_h)) * \
		sinf(modulef(data->scene->camera->theta + deg_to_rad(angle_w), 2 * PI));
	ray.p2.z = cosf((PI / 2) + deg_to_rad(angle_h));
	get_shape(data, &ray);
	if (ray.t > 0)
		my_mlx_pixel_put(&data->img, j, data->screen.h - i, \
		get_pixel(data, &ray, f[ray.shape_sel[0]]));
	else
		my_mlx_pixel_put(&data->img, j, data->screen.h - i, 0xFF000000);
}

void	render(t_data *data)
{
	t_ray	ray;
	int		i;
	int		j;

	ray.p1 = data->scene->camera->c;
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
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	step0(data);
	data->done = true;
}
