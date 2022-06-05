/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:24:51 by pnuti             #+#    #+#             */
/*   Updated: 2022/06/05 15:58:17 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_ns	init_counter(void)
{
	t_ns	ns;

	ns.nl = 0;
	ns.na = 0;
	ns.nc = 0;
	ns.ny = 0;
	ns.ns = 0;
	ns.np = 0;
	return (ns);
}

void	init_backg(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->screen.h / 6)
	{
		j = 0;
		while (j < data->screen.w / 8)
		{
			my_mlx_pixel_put(&data->cmd_backg, j, i, 0x55555555);
			j++;
		}
		i++;
	}
}
