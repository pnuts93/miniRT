/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:39:13 by lhorefto          #+#    #+#             */
/*   Updated: 2022/06/05 21:15:59 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static bool	set_plane_coordinates(char **xyz, char **ov, char **rgb, t_pla *pla)
{
	set_p(&pla->c, ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
	free_2darr(xyz);
	set_p(&pla->nov, ft_atof(ov[0]), ft_atof(ov[1]), ft_atof(ov[2]));
	free_2darr(ov);
	normalise(&pla->nov);
	if (!check_rgb(rgb))
	{
		free_2darr(rgb);
		return (berror("Error\nwrong plane rgb values!"));
	}
	pla->color.r = ft_atoi(rgb[0]);
	pla->color.g = ft_atoi(rgb[1]);
	pla->color.b = ft_atoi(rgb[2]);
	free_2darr(rgb);
	return (true);
}

bool	get_plane(char **line, t_pla *pla)
{
	char	**rgb;
	char	**ov;
	char	**xyz;

	if (ft_2darr_len(line) != 4)
		return (berror("Error\nwrong plane data!"));
	xyz = ft_split(line[1], ',');
	if (ft_2darr_len(xyz) != 3)
	{
		free_2darr(xyz);
		return (berror("Error\nwrong plane coordinates!"));
	}
	ov = ft_split(line[2], ',');
	if (!check_ovector(ov))
	{
		free_2darr(xyz);
		free_2darr(ov);
		return (berror("Error\nwrong plane orientation vector!"));
	}
	rgb = ft_split(line[3], ',');
	return (set_plane_coordinates(xyz, ov, rgb, pla));
}

static bool	set_cyl_coordinates(char **xyz, char **ov, char **rgb, t_cyl *cyl)
{
	set_p(&cyl->c, ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
	free_2darr(xyz);
	set_p(&cyl->nov, ft_atof(ov[0]), ft_atof(ov[1]), ft_atof(ov[2]));
	free_2darr(ov);
	normalise(&cyl->nov);
	if (!check_rgb(rgb))
	{
		free_2darr(rgb);
		return (berror("Error\nwrong cylinder rgb values!"));
	}
	cyl->color.r = ft_atoi(rgb[0]);
	cyl->color.g = ft_atoi(rgb[1]);
	cyl->color.b = ft_atoi(rgb[2]);
	free_2darr(rgb);
	return (true);
}

bool	get_cylinder(char **line, int n, t_cyl *cyl)
{
	char	**rgb;
	char	**ov;
	char	**xyz;

	if (ft_2darr_len(line) != 6)
		return (berror("Error\nwrong cylinder data!"));
	cyl->dia = ft_atof(line[3]);
	cyl->hei = ft_atof(line[4]);
	xyz = ft_split(line[1], ',');
	if (ft_2darr_len(xyz) != 3)
	{
		free_2darr(xyz);
		return (berror("Error\nwrong cylinder coordinates!"));
	}
	ov = ft_split(line[2], ',');
	if (!check_ovector(ov))
	{
		free_2darr(xyz);
		free_2darr(ov);
		return (berror("Error\nwrong cylinder orientation vector!"));
	}
	rgb = ft_split(line[5], ',');
	cyl->n = n;
	return (set_cyl_coordinates(xyz, ov, rgb, cyl));
}

bool	get_alight(char **line, t_alight *alight)
{
	double	ra;
	char	**rgb;

	if (ft_2darr_len(line) != 3)
		return (berror("Error\n wrong ambient light data!"));
	ra = atof(line[1]);
	if (ra < 0.0 || ra > 1.0)
		return (berror("Error\n wrong ambient light ratio!"));
	alight->ratio = ra;
	rgb = ft_split(line[2], ',');
	if (!check_rgb(rgb))
	{
		free_2darr(rgb);
		return (berror("Error\n wrong ambient light rgb values!"));
	}
	alight->color.r = ft_atoi(rgb[0]);
	alight->color.g = ft_atoi(rgb[1]);
	alight->color.b = ft_atoi(rgb[2]);
	free_2darr(rgb);
	return (true);
}
