/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:28:16 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/13 13:52:11 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_scene	*scene;

	if (argc != 2 || ft_strncmp(ft_strchr(argv[1], '.'), ".rt", 4))
		return (!berror("Error\nwrong number of arguments or file extension!"));

	scene = reader(argv[1], scene);
	if (scene->error)
	{
		purge_scene(scene);
		return (2);
	}
	purge_scene(scene);
	init(&data, argv);
	loop(&data);
	purge(&data);
	return (0);
}
