/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:28:16 by pnuti             #+#    #+#             */
/*   Updated: 2022/04/26 09:28:50 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2 || ft_strncmp(ft_strchr(argv[1], '.'), ".rt", 4))
		return (!berror("Error\nwrong number of arguments or file extension!"));
	data.scene = reader(argv[1], data.scene);
	if (data.scene->error)
	{
		purge_scene(data.scene);
		return (2);
	}
	init(&data, argv);
	data.scene->camera->fov_h = data.scene->camera->fov_w * ((float)data.screen.h / (float)data.screen.w);
	translate_scene(data.scene);
	rotate_scene(data.scene);
	ref_cyl(data.scene->cyl, data.scene->ns.ny);
//	printf("cyl ov\tx: %f\ty: %f\tz: %f\n", data.scene->cyl[0]->nov.x, data.scene->cyl[0]->nov.y, data.scene->cyl[0]->nov.z);
//	printf("phi: %f\n", data.scene->cyl[0]->phi);
//	printf("sph\tx: %f\ty: %f\tz: %f\n", data.scene->sph[0]->c.x, data.scene->sph[0]->c.y, data.scene->sph[0]->c.z);
//	printf("camera ov\tx: %f\ty: %f\tz: %f\ttheta: %f\n", data.scene->camera->nov_i.x, data.scene->camera->nov_i.y, data.scene->camera->nov_i.z, data.scene->camera->theta);
	loop(&data);
	return (0);
}
