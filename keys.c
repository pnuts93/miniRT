/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:47:11 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/25 12:01:41 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	step0(t_data *data, t_select *sel)
{
	mlx_string_put(data->mlx, data->win, 0, 0, 0xFFFFFFFF, "");
	mlx_string_put(data->mlx, data->win, 0, 0, 0xFFFFFFFF, 
		"SELECT an object:\n\
		S: sphere\n\
		P: plane\n\
		Y: cylinder\n\
		L: light\n\
		C: camera\n");
}

void	step1(t_data *data, t_select *sel)
{
	char	*obj_id;

	obj_id = ft_itoa(sel->obj_id);
	mlx_string_put(data->mlx, data->win, 0, 0, 0xFFFFFFFF, 
		"SELECT the object number (press ENTER to confirm):\n\
		← | →");
	mlx_string_put(data->mlx, data->win, 0, 0, 0xFFFFFFFF, obj_id);
	free(obj_id);
}

void	handle_step0(t_data *data, t_select *sel, int kn)
{
	if (ft_strchr("SPYLC", ft_toupper(kn)))
	{
		if (ft_toupper(kn) == 'S')
			sel->obj = SPHERE;
		else if (ft_toupper(kn) == 'P')
			sel->obj = PLANE;
		else if (ft_toupper(kn) == 'Y')
			sel->obj = CYLINDER;
		else if (ft_toupper(kn) == 'L')
			sel->obj = LIGHT;
		else if (ft_toupper(kn) == 'C')
			sel->obj = CAMERA;
		sel->step++;
		step1(data, sel);
	}
}

void	handle_step1(t_data *data, t_select *sel, int kn)
{
	int	shape_sel[5];

	shape_sel[0] = data->scene->ns.ns;
	shape_sel[1] = data->scene->ns.np;
	shape_sel[2] = data->scene->ns.ny;
	shape_sel[3] = data->scene->ns.nl;
	shape_sel[4] = data->scene->ns.nc;
	if (kn == 42)
		sel->obj_id = (sel->obj_id + 1) % shape_sel[sel->obj];
	else if (kn == 24 && sel->obj_id > 0)
		sel->obj_id = (sel->obj_id - 1) % shape_sel[sel->obj];
	else if (kn == 1)
		sel->step++;
}