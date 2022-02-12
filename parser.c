/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:49:20 by lhorefto          #+#    #+#             */
/*   Updated: 2022/02/12 12:52:51 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static char	*raw(char *path) //error handling?
{
	int		fd;
	int		i;
	char	buff[10000];

	fd = open(path, O_RDONLY);
	i = read(fd, buff, 10000);
	if (i < 0)
		return NULL;
	buff[i] = 0;
	return ft_strdup(buff);
}

static bool	get_alight(char **line, t_alight *alight)
{
	double	ra;
	char	**rgb;
	
	if (ft_2darr_len(line) != 3)
		return (berror("Error\n wrong ambient light data!"));
	printf("??\n");
	ra = atof(line[1]);
	if (ra < 0.0 || ra > 1.0)
		return (berror("Error\n wrong ambient light ratio!"));
	printf("??\n");
	alight->ratio = ra;
	rgb = ft_split(line[2], ',');
	printf("??\n");
	if (!check_rgb(rgb))
		return (berror("Error\n wrong ambient light rgb values!"));
	alight->r = ft_atoi(rgb[0]);
	alight->g = ft_atoi(rgb[1]);
	alight->b = ft_atoi(rgb[2]);
	free_2darr(rgb, 3);
	free_2darr(line, 3);
	return true;
}

static bool	get_light(char **line, t_light *light)
{
	double	ra;
	char	**xyz;

	if (ft_2darr_len(line) != 3)
		return (berror("Error\n wrong light data!"));
	ra = atof(line[2]);
	if (ra < 0.0 || ra > 1.0)
		return (berror("Error\n wrong light ratio!"));
	light->ratio = ra;
	xyz = ft_split(line[1], ',');
	if (ft_2darr_len(xyz) != 3)
		return (berror("Error\n wrong light coordinates!"));
	light->x = atof(xyz[0]);
	light->y = atof(xyz[1]);
	light->z = atof(xyz[2]);
	free_2darr(xyz, 3);
	free_2darr(line, 3);
}

static bool handle_line(t_scene *scene, char **line)
{
	if (!ft_strncmp(line[0], "A", 3))
		return (get_alight(line, scene->alight));
	else if (!ft_strncmp(line[0], "L", 3))
		return (get_light(line, scene->light));
	else if (!ft_strncmp(line[0], "C", 3))
		return (get_camera(line, scene->camera));
	else if (!ft_strncmp(line[0], "sp", 4))
		return (get_sphere(line, scene->sph));
	else if (!ft_strncmp(line[0], "pl", 4))
		return (get_plane(line, scene->pla));
	else if (!ft_strncmp(line[0], "cy", 4))
		return (get_cylinder(line, scene->cyl));		
	else
		return berror("Error\nUnknown identifier in the scene!");
}

t_scene	*reader(char *path)
{
	t_scene	*scene;
	char	**lines;
	int		i;

	lines = ft_split(raw(path), '\n');
	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return NULL;
	i = 0;
	while (lines[i])
	{
		char	**tmp;
		printf("%s\n", lines[i]);
		tmp = ft_split(lines[i], ' ');
		if (!handle_line(scene, tmp))	
		{
			// do cleanup
			return NULL;
		}
		i++;
	}
	free(lines);
	return scene;
}