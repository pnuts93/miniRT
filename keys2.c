/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:00:13 by bkeskint          #+#    #+#             */
/*   Updated: 2022/06/05 16:07:10 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

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
	if (kn == 65363)
		sel->obj_id = (sel->obj_id + 1) % shape_sel[sel->obj];
	else if (kn == 65361 && sel->obj_id > 0)
		sel->obj_id = (sel->obj_id - 1) % shape_sel[sel->obj];
	else if (kn == 65293)
	{
		sel->step++;
		step2(data, sel);
	}
	else if (ft_toupper(kn) == 'B')
	{
		sel->step--;
		step0(data);
	}
	if (kn == 65363 || kn == 65361)
		step1(data, sel);
}

void	handle_step2(t_data *data, t_select *sel, int kn)
{
	if (ft_toupper(kn) == 'T')
		sel->action = TRA;
	else if (ft_toupper(kn) == 'R')
		sel->action = ROT;
	else if (ft_toupper(kn) == 'D' && (sel->obj == SPHERE
			|| sel->obj == CYLINDER))
		sel->action = RED;
	else if (ft_toupper(kn) == 'B')
	{
		sel->step--;
		step1(data, sel);
		return ;
	}
	else
		return ;
	sel->step++;
	step3(data, sel);
}

void	handle_step3(t_data *data, t_select *sel, int kn)
{
	if (ft_toupper(kn) == 'B')
	{
		sel->step--;
		sel->dimension = 0;
		step2(data, sel);
		return ;
	}
	if (sel->action != RED)
	{
		if (ft_toupper(kn) == 'X')
			sel->dimension = 'x';
		else if (ft_toupper(kn) == 'Y')
			sel->dimension = 'y';
		else if (ft_toupper(kn) == 'Z')
			sel->dimension = 'z';
	}
	else
	{
		if (ft_toupper(kn) == 'D')
			sel->dimension = 'd';
		else if (ft_toupper(kn) == 'H')
			sel->dimension = 'h';
	}
	if (sel->dimension)
	{
		sel->step++;
		step4(data, sel);
	}
}

void	handle_step4(t_data *data, t_select *sel, int kn)
{
	if (kn == 65363)
		sel->magnitude += 1;
	else if (kn == 65361 || (kn == 65361 && sel->magnitude > 0
			&& sel->action == RED))
		sel->magnitude -= 1;
	else if (kn == 65293)
	{
		sel->step = 0;
		data->done = false;
		dispatch(data, sel);
	}
	else if (ft_toupper(kn) == 'B')
	{
		sel->step--;
		step3(data, sel);
	}
	if (kn == 65363 || kn == 65361)
		step4(data, sel);
}
