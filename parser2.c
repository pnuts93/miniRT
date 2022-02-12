/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:44:34 by lhorefto          #+#    #+#             */
/*   Updated: 2022/02/12 12:54:32 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

bool	get_camera(char **line, t_camera *camera)
{
	int		fov;
	char	**xyz;
	char	**ov;

	if (ft_2darr_len(line) != 4)
		return (berror("Error\nwrong camera data!"));
	fov = ft_atoi(line[3]);
	if (fov < 0 || fov > 180)
		return (berror("Error\nwrong camera field of view!"));
	camera->fov = fov;
	xyz = ft_split(line[1], ',');
	if (ft_2darr_len(xyz) != 3)
		return (berror("Error\n wrong light coordinates!"));
	camera->x = atof(xyz[0]);
	camera->y = atof(xyz[1]);
	camera->z = atof(xyz[2]);
	ov = ft_split(line[2], ',');
	if (!check_ovector(ov))
		return (berror("Error\n wrong camera orientation vector!"));
	camera->vx = atof(ov[0]);
	camera->vy = atof(ov[1]);
	camera->vz = atof(ov[2]);
	free_2darr(xyz, 3);
	free_2darr(ov, 3);
	free_2darr(line, 4);
	return true;
}

bool	get_sphere(char **line, t_sph *sph)
{
	char	**rgb;
	char	**xyz;

	if (ft_2darr_len(line) != 4)
		return (berror("Error\nwrong sphere data!"));
	sph->dia = atof(line[2]);
	xyz = ft_split(line[1], ',');
	if (ft_2darr_len(xyz) != 3)
		return (berror("Error\nwrong sphere coordinates!"));
	sph->x = atof(xyz[0]);
	sph->y = atof(xyz[1]);
	sph->z = atof(xyz[2]);
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
	pla->x = atof(xyz[0]);
	pla->y = atof(xyz[1]);
	pla->z = atof(xyz[2]);
	ov = ft_split(line[2], ',');
	if (!check_ovector(ov))
		return (berror("Error\nwrong plane orientation vector!"));
	pla->vx = atof(ov[0]);
	pla->vy = atof(ov[1]);
	pla->vz = atof(ov[2]);
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
	cyl->dia = atof(line[3]);
	cyl->hei = atof(line[4]);
	xyz = ft_split(line[1], ',');
	if (ft_2darr_len(xyz) != 3)
		return (berror("Error\nwrong cylinder coordinates!"));
	cyl->x = atof(xyz[0]);
	cyl->y = atof(xyz[1]);
	cyl->z = atof(xyz[2]);
	ov = ft_split(line[2], ',');
	if (!check_ovector(ov))
		return (berror("Error\nwrong cylinder orientation vector!"));
	cyl->vx = atof(ov[0]);
	cyl->vy = atof(ov[1]);
	cyl->vz = atof(ov[2]);
	rgb = ft_split(line[3], ',');
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
