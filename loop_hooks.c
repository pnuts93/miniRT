/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:12:05 by pnuti             #+#    #+#             */
/*   Updated: 2022/04/28 16:02:43 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	handle_key(int kn, t_data *data)
{
	if (kn == 65307)
		purge(data);
	return (0);
}

static int	handle_loop(t_data *data)
{
	if (!data->done)
		render(data);
	return (0);
}

static int	handle_x(t_data *data)
{
	purge(data);
	return (0);
}

void	loop(t_data *data)
{
	mlx_hook(data->win, 33, 1L << 5, handle_x, data);
	mlx_key_hook(data->win, handle_key, data);
	mlx_loop_hook(data->mlx, handle_loop, data);
	mlx_loop(data->mlx);
}
