/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:47:11 by pnuti             #+#    #+#             */
/*   Updated: 2022/06/05 16:19:50 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/*
65363 ->
65361 <-
65293 Enter
*/

void	step0(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->cmd_backg.img, 80, 80);
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET, 0xFFFFFFFF,
		"SELECT an object:");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE, 0xFFFFFFFF,
		"S: sphere");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 2, 0xFFFFFFFF,
		"P: plane");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 3, 0xFFFFFFFF,
		"Y: cylinder");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 4, 0xFFFFFFFF,
		"L: light");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 5, 0xFFFFFFFF,
		"C: camera");
}

void	step1(t_data *data, t_select *sel)
{
	char	*obj_id;

	mlx_put_image_to_window(data->mlx, data->win, data->cmd_backg.img, 80, 80);
	obj_id = ft_itoa(sel->obj_id);
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET,
		0xFFFFFFFF, "SELECT the object number:");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE,
		0xFFFFFFFF, "(press ENTER to confirm)");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 2,
		0xFFFFFFFF, "<- | ->");
	mlx_string_put(data->mlx, data->win, OFFSET + 50, OFFSET + LINE * 2,
		0xFFFFFFFF, obj_id);
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 3,
		0xFFFFFFFF, "B: back");
	free(obj_id);
}

void	step2(t_data *data, t_select *sel)
{
	mlx_put_image_to_window(data->mlx, data->win, data->cmd_backg.img, 80, 80);
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET, 0xFFFFFFFF,
		"SELECT an action:");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE,
		0xFFFFFFFF, "T: translation");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 2,
		0xFFFFFFFF, "R: rotation");
	if (sel->obj == SPHERE || sel->obj == CYLINDER)
		mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 3,
			0xFFFFFFFF, "D: redimension");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 4,
		0xFFFFFFFF, "B: back");
}

void	step3(t_data *data, t_select *sel)
{
	mlx_put_image_to_window(data->mlx, data->win, data->cmd_backg.img, 80, 80);
	if (sel->action != RED)
	{
		mlx_string_put(data->mlx, data->win, OFFSET, OFFSET,
			0xFFFFFFFF, "SELECT an axis:");
		mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE,
			0xFFFFFFFF, "[ x | y | z ]");
	}
	else
	{
		mlx_string_put(data->mlx, data->win, OFFSET, OFFSET,
			0xFFFFFFFF, "SELECT a dimension:");
		mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE,
			0xFFFFFFFF, "D: diameter");
		if (sel->obj == CYLINDER)
		{
			mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 2,
				0xFFFFFFFF, "H: height");
		}
	}
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 3,
		0xFFFFFFFF, "B: back");
}

void	step4(t_data *data, t_select *sel)
{
	char	*magnitude;

	mlx_put_image_to_window(data->mlx, data->win, data->cmd_backg.img, 80, 80);
	magnitude = ft_itoa(sel->magnitude);
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET,
		0xFFFFFFFF, "SELECT A magnitude:");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE,
		0xFFFFFFFF, "(press ENTER to confirm)");
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 2,
		0xFFFFFFFF, " <- | -> ");
	mlx_string_put(data->mlx, data->win, OFFSET + 50, OFFSET + LINE * 2,
		0xFFFFFFFF, magnitude);
	mlx_string_put(data->mlx, data->win, OFFSET, OFFSET + LINE * 3,
		0xFFFFFFFF, "B: back");
	free(magnitude);
}
