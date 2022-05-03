/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:59:01 by pnuti             #+#    #+#             */
/*   Updated: 2022/04/28 09:04:32 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	isin_circle(t_data *data, t_vector ray, float *res, int rec)
{
	int		i;
	float	t;

	i = 0;
	while (i < data->scene->ns.ns)
	{
		t = inter_sphere(data->scene->sph[i], ray);
		if ((*res < 0 && t >= 0) || (t >= 0 && t < *res))
		{
			*res = t;
			if (!rec)
			{
				data->shape_sel[0] = SP;
				data->shape_sel[1] = i;
			}
		}
		i++;
	}
}

static void	isin_plane(t_data *data, t_vector ray, float *res, int rec)
{
	int		i;
	float	t;

	i = 0;
	while (i < data->scene->ns.np)
	{
		t = inter_plane(data->scene->pla[i], ray);
		if ((*res < 0 && t >= 0) || (t >= 0 && t < *res))
		{
			*res = t;
			if (!rec)
			{
				data->shape_sel[0] = PL;
				data->shape_sel[1] = i;
			}
		}
		i++;
	}
}

static void	isin_cylinder(t_data *data, t_vector ray, float *res, int rec)
{
	int		i;
	float	t;

	i = 0;
	while (i < data->scene->ns.ny)
	{
		t = inter_cylinder(data->scene->cyl[i], ray);
		if ((*res < 0 && t >= 0) || (t >= 0 && t < *res))
		{
			*res = t;
			if (!rec)
			{
				data->shape_sel[0] = CY;
				data->shape_sel[1] = i;
			}
		}
		i++;
	}
}

float	get_shape(t_data *data, t_vector ray, int rec)
{
	float	res;

	res = -1;
	if (!rec)
	{
		data->shape_sel[0] = NA;
		data->shape_sel[1] = 0;
	}
	isin_circle(data, ray, &res, rec);
	isin_plane(data, ray, &res, rec);
	isin_cylinder(data, ray, &res, rec);
	return (res);
}