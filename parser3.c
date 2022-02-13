/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:39:13 by lhorefto          #+#    #+#             */
/*   Updated: 2022/02/13 12:27:54 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static bool	set_plane_coordinates(char **xyz, char **ov, char **rgb, t_pla *pla)
{
	pla->x = ft_atof(xyz[0]);
	pla->y = ft_atof(xyz[1]);
	pla->z = ft_atof(xyz[2]);
	free_2darr(xyz);
	pla->vx = ft_atof(ov[0]);
	pla->vy = ft_atof(ov[1]);
	pla->vz = ft_atof(ov[2]);
	free_2darr(ov);
	if (!check_rgb(rgb))
	{
		free_2darr(rgb);
		return (berror("Error\nwrong plane rgb values!"));
	}
	pla->r = ft_atoi(rgb[0]);
	pla->g = ft_atoi(rgb[1]);
	pla->b = ft_atoi(rgb[2]);
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
	cyl->x = ft_atof(xyz[0]);
	cyl->y = ft_atof(xyz[1]);
	cyl->z = ft_atof(xyz[2]);
	free_2darr(xyz);
	cyl->vx = ft_atof(ov[0]);
	cyl->vy = ft_atof(ov[1]);
	cyl->vz = ft_atof(ov[2]);
	free_2darr(ov);
	if (!check_rgb(rgb))
	{
		free_2darr(rgb);
		return (berror("Error\nwrong cylinder rgb values!"));
	}
	cyl->r = ft_atoi(rgb[0]);
	cyl->g = ft_atoi(rgb[1]);
	cyl->b = ft_atoi(rgb[2]);
	free_2darr(rgb);
	return (true);
}

bool	get_cylinder(char **line, t_cyl *cyl)
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
	return (set_cyl_coordinates(xyz, ov, rgb, cyl));
}
