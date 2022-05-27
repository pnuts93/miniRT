/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:26:17 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/27 18:17:49 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	purge(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_image(data->mlx, data->cmd_backg.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	purge_scene(data->scene);
	free(data->mlx);
	exit(0);
}

void	purge_scene(t_scene *scene)
{
	int	i;

	i = 0;
	free(scene->alight);
	free(scene->light);
	free(scene->camera);
	while (i < scene->ns.np)
		free(scene->pla[i++]);
	free(scene->pla);
	i = 0;
	while (i < scene->ns.ns)
		free(scene->sph[i++]);
	free(scene->sph);
	i = 0;
	while (i < scene->ns.ny)
		free(scene->cyl[i++]);
	free(scene->cyl);
	free(scene);
}
