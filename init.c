/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:37:00 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/27 18:35:50 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	init(t_data *data, char *argv[])
{
	data->mlx = mlx_init();
	data->screen.w = 0;
	data->screen.h = 0;
	mlx_get_screen_size(data->mlx, &data->screen.w, &data->screen.h);
	data->win = mlx_new_window(data->mlx, data->screen.w, data->screen.h, \
		argv[1]);
	data->img.img = mlx_new_image(data->mlx, data->screen.w, data->screen.h);
	data->img.address = mlx_get_data_addr(data->img.img, &data->img.bppx, \
		&data->img.len, &data->img.endian);
	data->cmd_backg.img = mlx_new_image(data->mlx, data->screen.w / 8, \
		data->screen.h / 6);
	data->cmd_backg.address = mlx_get_data_addr(data->cmd_backg.img, \
		&data->cmd_backg.bppx, &data->cmd_backg.len, &data->cmd_backg.endian);
	init_backg(data);
	data->done = false;
}

static t_sph	**init_sph(int n)
{
	t_sph	**sph;
	int		i;

	sph = (t_sph **)malloc(sizeof(t_sph *) * n);
	i = 0;
	while (i < n)
	{
		sph[i] = (t_sph *)malloc(sizeof(t_sph));
		i++;
	}
	return (sph);
}

static t_pla	**init_pla(int n)
{
	t_pla	**pla;
	int		i;

	pla = (t_pla **)malloc(sizeof(t_pla *) * n);
	i = 0;
	while (i < n)
	{
		pla[i] = (t_pla *)malloc(sizeof(t_pla));
		i++;
	}
	return (pla);
}

static t_cyl	**init_cyl(int n)
{
	t_cyl	**cyl;
	int		i;

	cyl = (t_cyl **)malloc(sizeof(t_cyl *) * n);
	i = 0;
	while (i < n)
	{
		cyl[i] = (t_cyl *)malloc(sizeof(t_cyl));
		i++;
	}
	return (cyl);
}

t_scene	*init_scene(t_ns ns)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->error = false;
	scene->cc = 0;
	scene->cp = 0;
	scene->cs = 0;
	scene->ns = ns;
	scene->alight = (t_alight *)malloc(sizeof(t_alight));
	scene->camera = (t_cam *)malloc(sizeof(t_cam));
	scene->light = (t_light *)malloc(sizeof(t_light));
	scene->sph = init_sph(ns.ns);
	scene->pla = init_pla(ns.np);
	scene->cyl = init_cyl(ns.ny);
	return (scene);
}
