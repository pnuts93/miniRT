/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:44:34 by lhorefto          #+#    #+#             */
/*   Updated: 2022/02/13 19:11:54 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	set_camera_coordinates(char **xyz, char **ov, t_cam *camera)
{
	camera->x = ft_atof(xyz[0]);
	camera->y = ft_atof(xyz[1]);
	camera->z = ft_atof(xyz[2]);
	free_2darr(xyz);
	camera->vy = ft_atof(ov[0]);
	camera->vx = ft_atof(ov[1]);
	camera->vz = ft_atof(ov[2]);
	free_2darr(ov);
}

bool	get_camera(char **line, t_cam *camera)
{
	int		f;
	char	**xyz;
	char	**ov;

	if (ft_2darr_len(line) != 4)
		return (berror("Error\nwrong camera data!"));
	f = ft_atoi(line[3]);
	if (f < 0 || f > 180)
		return (berror("Error\nwrong camera field of view!"));
	camera->fov_w = f;
	xyz = ft_split(line[1], ',');
	if (ft_2darr_len(xyz) != 3)
	{
		free_2darr(xyz);
		return (berror("Error\n wrong light coordinates!"));
	}
	ov = ft_split(line[2], ',');
	if (!check_ovector(ov))
	{
		free_2darr(ov);
		return (berror("Error\n wrong camera orientation vector!"));
	}
	set_camera_coordinates(xyz, ov, camera);
	return (true);
}

static void	set_sphere_coordinates(char **xyz, char **rgb, t_sph *sph)
{
	sph->x = ft_atof(xyz[0]);
	sph->y = ft_atof(xyz[1]);
	sph->z = ft_atof(xyz[2]);
	free_2darr(xyz);
	sph->r = ft_atoi(rgb[0]);
	sph->g = ft_atoi(rgb[1]);
	sph->b = ft_atoi(rgb[2]);
	free_2darr(rgb);
}

bool	get_sphere(char **line, t_sph *sph)
{
	char	**rgb;
	char	**xyz;

	if (ft_2darr_len(line) != 4)
		return (berror("Error\nwrong sphere data!"));
	sph->d = ft_atof(line[2]);
	xyz = ft_split(line[1], ',');
	if (ft_2darr_len(xyz) != 3)
	{
		free_2darr(xyz);
		return (berror("Error\nwrong sphere coordinates!"));
	}
	rgb = ft_split(line[3], ',');
	if (!check_rgb(rgb))
	{
		free_2darr(xyz);
		free_2darr(rgb);
		return (berror("Error\nwrong sphere rgb values!"));
	}
	set_sphere_coordinates(xyz, rgb, sph);
	return (true);
}

bool	get_light(char **line, t_light *light)
{
	double	ra;
	char	**xyz;

	if (ft_2darr_len(line) != 3)
		return (berror("Error\n wrong light data!"));
	ra = ft_atof(line[2]);
	if (ra < 0.0 || ra > 1.0)
		return (berror("Error\n wrong light ratio!"));
	light->ratio = ra;
	xyz = ft_split(line[1], ',');
	if (ft_2darr_len(xyz) != 3)
	{
		free_2darr(xyz);
		return (berror("Error\n wrong light coordinates!"));
	}
	light->x = ft_atof(xyz[0]);
	light->y = ft_atof(xyz[1]);
	light->z = ft_atof(xyz[2]);
	free_2darr(xyz);
	return (true);
}
