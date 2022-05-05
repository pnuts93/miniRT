/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:59:01 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/05 14:20:06 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	isin_circle(t_data *data, t_ray *ray, int rec)
{
	int		i;
	float	t;

	i = 0;
	while (i < data->scene->ns.ns)
	{
		t = inter_sphere(data->scene->sph[i], ray);
		if ((isless(ray->t, 0) && isgreaterequal(t, 0)) || (isgreaterequal(t, 0) && isless(t, ray->t)))
		{
			ray->t = t;
			if (!rec)
			{
				ray->shape_sel[0] = SP;
				ray->shape_sel[1] = i;
				ray->shape_sel[2] = -1;
			}
		}
		i++;
	}
}

static void	isin_plane(t_data *data, t_ray *ray, int rec)
{
	int		i;
	float	t;

	i = 0;
	while (i < data->scene->ns.np)
	{
		t = inter_plane(data->scene->pla[i], ray);
		if ((isless(ray->t, 0) && isgreaterequal(t, 0)) || (isgreaterequal(t, 0) && isless(t, ray->t)))
		{
			ray->t = t;
			if (!rec)
			{
				ray->shape_sel[0] = PL;
				ray->shape_sel[1] = i;
				ray->shape_sel[2] = -1;
			}
		}
		i++;
	}
}

static void	isin_cylinder(t_data *data, t_ray *ray, int rec)
{
	int		i;
	float	t;

	i = 0;
	while (i < data->scene->ns.ny)
	{
		t = inter_cylinder(data->scene->cyl[i], ray);
		if ((isless(ray->t, 0) && isgreaterequal(t, 0)) || (isgreaterequal(t, 0) && isless(t, ray->t)))
		{
			ray->t = t;
			if (!rec)
			{
				ray->shape_sel[0] = CY;
				ray->shape_sel[1] = i;
				ray->shape_sel[2] = -1;
			}
		}
		i++;
	}
}

void	get_shape(t_data *data, t_ray *ray, int rec)
{
	ray->t = -1;
	if (!rec)
	{
		ray->shape_sel[0] = NA;
		ray->shape_sel[1] = -1;
		ray->shape_sel[2] = -1;
	}
	isin_circle(data, ray, rec);
	isin_plane(data, ray, rec);
	isin_cylinder(data, ray, rec);
}