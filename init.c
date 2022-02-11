/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:37:00 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/11 17:38:50 by pnuti            ###   ########.fr       */
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
