/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:28:16 by pnuti             #+#    #+#             */
/*   Updated: 2022/06/06 12:32:27 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2 || !ft_strchr(argv[1], '.') \
		|| ft_strncmp(ft_strchr(argv[1], '.'), ".rt", 4))
		return (!berror("Error\nwrong number of arguments or file extension!"));
	data.scene = reader(argv[1], data.scene);
	if (data.scene->error)
	{
		purge_scene(data.scene);
		return (2);
	}
	init(&data, argv);
	data.scene->camera->fov_h = data.scene->camera->fov_w * \
		((float)data.screen.h / (float)data.screen.w);
	translate_scene(data.scene);
	rotate_scene(data.scene);
	loop(&data);
	return (0);
}
