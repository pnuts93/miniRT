/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:28:16 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/13 12:07:41 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (0);
	init(&data, argv);
	data.sphere.x = 0;
	data.sphere.y = 0;
	data.sphere.z = 100.6;
	data.sphere.d = 12.6;
	data.camera.x = 0;
	data.camera.y = 0;
	data.camera.z = 0;
	data.camera.nov_x = 0;
	data.camera.nov_y = 0;
	data.camera.nov_z = 1;
	data.camera.fov_w = 90;
	data.camera.fov_h = data.camera.fov_w * (data.screen.h / data.screen.w);
	render(&data);
	loop(&data);
	return (0);
}
