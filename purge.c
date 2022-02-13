/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:26:17 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/13 14:41:42 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	purge(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
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
	while (i < scene->cp)
	{
		free(scene->pla[i]);
		i++;
	}
	free(scene->pla);
	i = 0;
	while (i < scene->cs)
	{
		free(scene->sph[i]);
		i++;
	}
	free(scene->sph);
	i = 0;
	while (i < scene->cc)
	{
		free(scene->cyl[i]);
		i++;
	}
	free(scene->cyl);
	free(scene);
}