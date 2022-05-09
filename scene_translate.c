/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_translate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:23:23 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/09 09:12:30 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	translate_point(t_point *p, t_point c)
{
	t_point	tmp;

	tmp = diff_vectors(*p, c);
	import_p(&tmp, p);
}

static void	translate_spheres(t_sph **sph, int n, t_point c)
{
	int	i;

	i = 0;
	while (i < n)
	{
		translate_point(&sph[i]->c, c);
		i++;
	}
}

static void	translate_cylinders(t_cyl **cyl, int n, t_point c)
{
	int	i;

	i = 0;
	while (i < n)
	{
		translate_point(&cyl[i]->c, c);
		i++;
	}
}

static void	translate_planes(t_pla **pla, int n, t_point c)
{
	int	i;

	i = 0;
	while (i < n)
	{
		translate_point(&pla[i]->c, c);
		i++;
	}
}

void	translate_scene(t_scene *scene)
{
	translate_spheres(scene->sph, scene->ns.ns, scene->camera->c);
	translate_cylinders(scene->cyl, scene->ns.ny, scene->camera->c);
	translate_planes(scene->pla, scene->ns.np, scene->camera->c);
	if (scene->ns.nl)
		translate_point(&scene->light->c, scene->camera->c);
	set_p(&scene->camera->c, 0, 0, 0);
}
