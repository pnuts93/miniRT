/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:12:05 by pnuti             #+#    #+#             */
/*   Updated: 2022/06/16 10:16:50 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	init_sel(t_select *sel)
{
	sel->step = 0;
	sel->obj = -1;
	sel->obj_id = 0;
	sel->dimension = 0;
	sel->magnitude = 0;
}

static int	handle_key(int kn, t_data *data)
{
	static t_select	sel;
	void			(*f[5])(t_data*, t_select*, int);

	f[0] = &handle_step0;
	f[1] = &handle_step1;
	f[2] = &handle_step2;
	f[3] = &handle_step3;
	f[4] = &handle_step4;
	if (kn == 65307)
		purge(data);
	else
		f[sel.step](data, &sel, kn);
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
