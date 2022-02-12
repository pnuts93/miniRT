/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:44:34 by lhorefto          #+#    #+#             */
/*   Updated: 2022/02/12 17:59:31 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

bool	get_camera(char **line, t_camera *camera)
{
	int		f;
	char	**xyz;
	char	**ov;

	if (ft_2darr_len(line) != 4)
		return (berror("Error\nwrong camera data!"));
	f = ft_atoi(line[3]);
	if (f < 0 || f > 180)
		return (berror("Error\nwrong camera field of view!"));
	camera->fov = f;
	xyz = ft_split(line[1], ',');
	if (ft_2darr_len(xyz) != 3)
		return (berror("Error\n wrong light coordinates!"));
	camera->x = ft_atof(xyz[0]);
	camera->y = ft_atof(xyz[1]);
	camera->z = ft_atof(xyz[2]);
	free_2darr(xyz, 3);
	ov = ft_split(line[2], ',');
	if (!check_ovector(ov))
		return (berror("Error\n wrong camera orientation vector!"));
	camera->vy = ft_atof(ov[0]);
	camera->vx = ft_atof(ov[1]);
	camera->vz = ft_atof(ov[2]);
	free_2darr(ov, 3);
	free_2darr(line, 4);
	return (true);
}

bool	get_sphere(char **line, t_sph *sph)
{
	char	**rgb;
	char	**xyz;

	if (ft_2darr_len(line) != 4)
		return (berror("Error\nwrong sphere data!"));
	sph->dia = ft_atof(line[2]);
	xyz = ft_split(line[1], ',');
	if (ft_2darr_len(xyz) != 3)
		return (berror("Error\nwrong sphere coordinates!"));
	sph->x = ft_atof(xyz[0]);
	sph->y = ft_atof(xyz[1]);
	sph->z = ft_atof(xyz[2]);
	rgb = ft_split(line[3], ',');
	if (!check_rgb(rgb))
		return (berror("Error\nwrong sphere rgb values!"));
	sph->r = ft_atoi(rgb[0]);
	sph->g = ft_atoi(rgb[1]);
	sph->b = ft_atoi(rgb[2]);
	free_2darr(rgb, 3);
	free_2darr(xyz, 3);
	free_2darr(line, 4);
	return true;
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
		return (berror("Error\nwrong plane coordinates!"));
	pla->x = ft_atof(xyz[0]);
	pla->y = ft_atof(xyz[1]);
	pla->z = ft_atof(xyz[2]);
	ov = ft_split(line[2], ',');
	if (!check_ovector(ov))
		return (berror("Error\nwrong plane orientation vector!"));
	pla->vx = ft_atof(ov[0]);
	pla->vy = ft_atof(ov[1]);
	pla->vz = ft_atof(ov[2]);
	rgb = ft_split(line[3], ',');
	if (!check_rgb(rgb))
		return (berror("Error\nwrong plane rgb values!"));
	pla->r = ft_atoi(rgb[0]);
	pla->g = ft_atoi(rgb[1]);
	pla->b = ft_atoi(rgb[2]);
	free_2darr(xyz, 3);
	free_2darr(ov, 3);
	free_2darr(rgb, 3);
	free_2darr(line, 4);
	return true;
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
		return (berror("Error\nwrong cylinder coordinates!"));
	cyl->x = ft_atof(xyz[0]);
	cyl->y = ft_atof(xyz[1]);
	cyl->z = ft_atof(xyz[2]);
	ov = ft_split(line[2], ',');
	if (!check_ovector(ov))
		return (berror("Error\nwrong cylinder orientation vector!"));
	cyl->vx = ft_atof(ov[0]);
	cyl->vy = ft_atof(ov[1]);
	cyl->vz = ft_atof(ov[2]);
	rgb = ft_split(line[5], ',');
	if (!check_rgb(rgb))
		return (berror("Error\nwrong cylinder rgb values!"));
	cyl->r = ft_atoi(rgb[0]);
	cyl->g = ft_atoi(rgb[1]);
	cyl->b = ft_atoi(rgb[2]);
	free_2darr(xyz, 3);
	free_2darr(ov, 3);
	free_2darr(rgb, 3);
	free_2darr(line, 6);
	return true;
}
