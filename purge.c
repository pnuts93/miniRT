/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:26:17 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/12 16:15:13 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	purge(t_data *data, t_scene *scene)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(scene->alight);
	free(scene->light);
	free(scene->camera);
	free(scene->pla);
	free(scene->sph);
	free(scene->cyl);
	free(scene);
	exit(0);
}
