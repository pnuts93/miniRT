/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:47:11 by pnuti             #+#    #+#             */
/*   Updated: 2022/06/05 14:21:14 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	dispatch(t_data *data, t_select *sel)
{
	void	(*f[5][3])(t_data*, int, int, float);

	f[0][0] = &tra_sph;
	f[0][1] = NULL;
	f[0][2] = &red_sph;
	f[1][0] = &tra_pla;
	f[1][1] = &rot_pla;
	f[1][2] = NULL;
	f[2][0] = &tra_cyl;
	f[2][1] = &rot_cyl;
	f[2][2] = &red_cyl;
	f[3][0] = &tra_lig;
	f[3][1] = NULL;
	f[3][2] = NULL;
	f[4][0] = &tra_cam;
	f[4][1] = &rot_cam;
	f[4][2] = NULL;
	f[sel->obj][sel->action](data, sel->obj_id, sel->dimension, sel->magnitude);
}

void	step0(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->cmd_backg.img, 80, 80);
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET, 0xFFFFFFFF, "SELECT an object:");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE, 0xFFFFFFFF, "S: sphere");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 2, 0xFFFFFFFF, "P: plane");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 3, 0xFFFFFFFF, "Y: cylinder");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 4, 0xFFFFFFFF, "L: light");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 5, 0xFFFFFFFF, "C: camera");
}

void	step1(t_data *data, t_select *sel)
{
	char	*obj_id;

	mlx_put_image_to_window(data->mlx, data->win, data->cmd_backg.img, 80, 80);
	obj_id = ft_itoa(sel->obj_id);
	mlx_string_put(data->mlx, data->win, 50, 50, 0xFFFFFFFF, \
		"SELECT the object number (press ENTER to confirm):\n\
		← | →\n\n\
		B: back");
	mlx_string_put(data->mlx, data->win, 0, 0, 0xFFFFFFFF, obj_id);
	free(obj_id);
}

void	step2(t_data *data, t_select *sel)
{
	mlx_put_image_to_window(data->mlx, data->win, data->cmd_backg.img, 80, 80);
	mlx_string_put(data->mlx, data->win, 0, 0, 0xFFFFFFFF, \
		"SELECT an action:\n\
		T: translation\n\
		R: rotation\n");
	if (sel->obj == SPHERE || sel->obj == CYLINDER)
	{
		mlx_string_put(data->mlx, data->win, 0, 0, 0xFFFFFFFF, "D: redimension");
	}
	mlx_string_put(data->mlx, data->win, 0, 0, 0xFFFFFFFF, "B: back");
}

void	step3(t_data *data, t_select *sel)
{
	mlx_put_image_to_window(data->mlx, data->win, data->cmd_backg.img, 80, 80);
	if (sel->action != RED)
	{
		mlx_string_put(data->mlx, data->win, OFFSET, OFFSET, 0xFFFFFFFF, "SELECT an axis:");
		mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE, 0xFFFFFFFF, "[ x | y | z ]");
	}
	else
	{
		mlx_string_put(data->mlx, data->win, OFFSET, OFFSET, 0xFFFFFFFF, "SELECT a dimension:");
		mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE, 0xFFFFFFFF, "D: diameter");
		if (sel->obj == CYLINDER)
		{
			mlx_string_put(data->mlx, data->win, 0, 0, 0xFFFFFFFF, "H: height");
		}
	}
	mlx_string_put(data->mlx, data->win, 0, 0, 0xFFFFFFFF, "B: back");
}

void	step4(t_data *data, t_select *sel)
{
	char	*magnitude;

	mlx_put_image_to_window(data->mlx, data->win, data->cmd_backg.img, 80, 80);
	magnitude = ft_itoa(sel->magnitude);
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET, 0xFFFFFFFF, "SELECT A magnitude (press ENTER to confirm):");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE, 0xFFFFFFFF, " ← | → ");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 2, 0xFFFFFFFF, "B: back");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 3, 0xFFFFFFFF, magnitude);
	free(magnitude);
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
	if (kn == 65363/*right arrow*/)
		sel->obj_id = (sel->obj_id + 1) % shape_sel[sel->obj];
	else if (kn == 65361/*left arrow*/ && sel->obj_id > 0)
		sel->obj_id = (sel->obj_id - 1) % shape_sel[sel->obj];
	else if (kn == 65293 /*enter*/)
	{
		sel->step++;
		step2(data, sel);
	}
	else if (ft_toupper(kn) == 'B')
	{
		sel->step--;
		step0(data);
	}
}

void	handle_step2(t_data *data, t_select *sel, int kn)
{
	if (ft_toupper(kn) == 'T')
		sel->action = TRA;
	else if (ft_toupper(kn) == 'R')
		sel->action = ROT;
	else if (ft_toupper(kn) == 'D' && (sel->obj == SPHERE || sel->obj == CYLINDER))
		sel->action = RED;
	else if (ft_toupper(kn) == 'B')
	{
		sel->step--;
		step1(data, sel);
		return ;
	}
	else
		return ;
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
		step4(data, sel);
}

void	handle_step4(t_data *data, t_select *sel, int kn)
{
	if (kn == 65363/*right arrow*/)
		sel->magnitude += 1;
	else if (kn == 65361/*left arrow*/ || (kn == 24 && sel->magnitude > 0 && sel->action == RED))
		sel->magnitude -= 1;
	else if (kn == 65293 /*enter*/)
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
}
