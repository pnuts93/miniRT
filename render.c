/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:36:04 by pnuti             #+#    #+#             */
/*   Updated: 2022/04/26 11:47:54 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_uint	get_pixel(t_data *data, t_vector ray, float t, t_point *(*f)(t_data*, t_vector, float, t_point))
{
	t_point	*collision;
	t_point	*norm;
	t_point	*tmp;
	t_point	*ref;
	t_point	*inc;
	float	dev;

	tmp = mult_vect_scal(ray.p2, t);
	collision = sum_vectors(ray.p1, *tmp);
	free(tmp);
	norm = f(data, ray, t, *collision); 
	inc = diff_vectors(ray.p1, *collision);
	normalise(inc);
	tmp = mult_vect_scal(*norm, 2 * dot(*norm, *inc));
	ref = diff_vectors(*tmp, *inc);
	free(tmp);
	tmp = diff_vectors(data->scene->light->c, *collision);
	dev = dot(*tmp, *ref);
	float	coeff = powf(dev * (dev > 0), 1);
	free(tmp);
	free(ref);
	free(collision);
	free(inc);
	free(norm);
	return (get_rgb(coeff, data));
}

void	project(t_data *data, t_vector ray, int i, int j)
{
	float	angle_w;
	float	angle_h;
	float	t;
	t_point	*(*f[3])(t_data *data, t_vector ray, float t, t_point collision);

	f[0] = &norm_sphere;
	f[1] = &norm_plane;
	f[2] = &norm_cylinder;
	angle_w = (data->scene->camera->fov_w / 2) - ((data->scene->camera->fov_w / data->screen.w) * (float)j);
	angle_h = (data->scene->camera->fov_h / 2) - ((data->scene->camera->fov_h / data->screen.h) * (float)i);
	ray.p2.x = sinf(modulef((PI / 2) + deg_to_rad(angle_h), PI)) * cosf(data->scene->camera->theta + deg_to_rad(angle_w));
	ray.p2.y = sinf((PI / 2) + deg_to_rad(angle_h)) * sinf(modulef(data->scene->camera->theta + deg_to_rad(angle_w), 2 * PI));
	ray.p2.z = cosf((PI / 2) + deg_to_rad(angle_h));
	t = get_shape(data, ray);
	if (t > 0)
		my_mlx_pixel_put(&data->img, j, i, get_pixel(data, ray, t, f[data->shape_sel[0]]));
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
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}