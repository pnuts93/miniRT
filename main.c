/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:28:16 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/13 19:15:04 by pnuti            ###   ########.fr       */
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
	purge_scene(data.scene);
	init(&data, argv);
	data.scene->camera[0].fov_h = data.scene->camera[0].fov_w * (data.screen.h / data.screen.w);
	render(&data);
	loop(&data);
	purge(&data);
	return (0);
}
