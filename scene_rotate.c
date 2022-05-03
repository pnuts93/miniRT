/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:22:15 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/02 10:15:34 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	rot_spheres(t_sph **sph, int n, t_point u, float angle)
{
	int		i;
	t_point	*tmp;

	i = 0;
	while (i < n)
	{
		tmp = rotate_quaternion(sph[i]->c, u, angle);
		import_p(tmp, &sph[i]->c);
		free(tmp);
		i++;
	}
}

static void	rot_cylinders(t_cyl **cyl, int n, t_point u, float angle)
{
	int		i;
	t_point	*tmp;
	t_point	*tmp_dir;

	i = 0;
	while (i < n)
	{
		tmp = rotate_quaternion(cyl[i]->c, u, angle);
		tmp_dir = sum_vectors(cyl[i]->c, cyl[i]->nov);
		import_p(tmp, &cyl[i]->c);
		free(tmp);
		tmp = rotate_quaternion(*tmp_dir, u, angle);
		free(tmp_dir);
		tmp_dir = diff_vectors(*tmp, cyl[i]->c);
		import_p(tmp_dir, &cyl[i]->nov);
		free(tmp_dir);
		free(tmp);
		i++;
	}
}

static void	rot_planes(t_pla **pla, int n, t_point u, float angle)
{
	int		i;
	t_point	*tmp;
	t_point	*tmp_dir;

	i = 0;
	while (i < n)
	{
		tmp = rotate_quaternion(pla[i]->c, u, angle);
		tmp_dir = sum_vectors(pla[i]->c, pla[i]->nov);
		import_p(tmp, &pla[i]->c);
		free(tmp);
		tmp = rotate_quaternion(*tmp_dir, u, angle);
		free(tmp_dir);
		tmp_dir = diff_vectors(*tmp, pla[i]->c);
		import_p(tmp_dir, &pla[i]->nov);
		free(tmp_dir);
		free(tmp);
		i++;
	}
}

static void	rotate_geom(t_scene *scene, t_point u)
{
	t_point	*tmp;

	rot_spheres(scene->sph, scene->ns.ns, u, 1.570796 - scene->camera->phi);
	rot_cylinders(scene->cyl, scene->ns.ny, u, 1.570796 - scene->camera->phi);
	rot_planes(scene->pla, scene->ns.np, u, 1.570796 - scene->camera->phi);
	tmp = rotate_quaternion(scene->light->c, u, 1.570796 - scene->camera->phi);
	import_p(tmp, &scene->light->c);
	free(tmp);
	tmp = rotate_quaternion(scene->camera->nov_i, u, 1.570796 - scene->camera->phi);
	import_p(tmp, &scene->camera->nov_i);
	free(tmp);
	scene->camera->phi = PI / 2;
	if (isequal(scene->camera->theta, 0))
		scene->camera->theta = get_angle_xy(scene->camera->nov_i);
}

void	rotate_scene(t_scene *scene)
{
	t_point	*u;
	t_point	z;

	set_p(&z, 0, 0, 1);
	if (!scene->camera->nov_i.z)
		return ;
	if (!scene->camera->nov_i.x && !scene->camera->nov_i.y)
	{
		u = (t_point *)malloc(sizeof(t_point));
		if (!u)
			return ;
		set_p(u, 1, 0, 0);
	}
	else
		u = cross(z, scene->camera->nov_i);
	scene->camera->theta = get_angle_xy(scene->camera->nov_i);
	if (isnan(scene->camera->theta))
		scene->camera->theta = 0;
	scene->camera->phi = acosf(scene->camera->nov_i.z);
	rotate_geom(scene, *u);
}
