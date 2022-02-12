/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:28:16 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/12 16:15:55 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_scene	*scene;

	if (argc != 2)
		return (1);
	scene = reader(argv[1]);
	if (!scene)
		return (2);
	init(&data, argv);
	loop(&data);
	purge(&data, scene);
	return (0);
}
