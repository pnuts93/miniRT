/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:37:00 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/13 10:57:13 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	init(t_data *data, char *argv[])
{
	data->mlx = mlx_init();
	data->screen.w = 0;
	data->screen.h = 0;
	mlx_get_screen_size(data->mlx, &data->screen.w, &data->screen.h);
	data->win = mlx_new_window(data->mlx, data->screen.w, data->screen.h, argv[1]);
}

t_scene	*init_scene()
{
	t_scene	*scene;
	
	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return NULL;
	scene->error = false;
	scene->alight = (t_alight *)malloc(sizeof(t_alight));
	scene->camera = (t_camera *)malloc(sizeof(t_camera));
	scene->light = (t_light *)malloc(sizeof(t_light));
	scene->sph = (t_sph *)malloc(sizeof(t_sph));
	scene->pla = (t_pla *)malloc(sizeof(t_pla));
	scene->cyl = (t_cyl *)malloc(sizeof(t_cyl));
	return scene;
}