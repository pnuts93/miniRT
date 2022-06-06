/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:49:20 by lhorefto          #+#    #+#             */
/*   Updated: 2022/06/06 14:59:56 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static char	*raw(char *path)
{
	int		fd;
	int		i;
	char	buff[10000];

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error\nNo such file or directory!", 2);
		exit(1);
	}
	i = read(fd, buff, 10000);
	if (i < 0)
		return (ft_strdup(""));
	buff[i] = 0;
	return (ft_strdup(buff));
}

static void	cmp_input(char **lines, int i, t_ns *ns)
{
	if (!ft_strncmp(lines[i], "A ", 2))
		ns->na++;
	else if (!ft_strncmp(lines[i], "L ", 2))
		ns->nl++;
	else if (!ft_strncmp(lines[i], "C ", 2))
		ns->nc++;
	else if (!ft_strncmp(lines[i], "sp ", 3))
		ns->ns++;
	else if (!ft_strncmp(lines[i], "pl ", 3))
		ns->np++;
	else if (!ft_strncmp(lines[i], "cy ", 3))
		ns->ny++;
}

static t_ns	count_elements(char **lines)
{
	t_ns	ns;
	int		i;

	ns = init_counter();
	i = 0;
	while (lines[i])
	{
		cmp_input(lines, i, &ns);
		i++;
	}
	if (ns.na != 1 || ns.nl != 1 || ns.nc != 1)
	{
		free_2darr(lines);
		ft_putendl_fd("Error\nwrong number of cameras/(ambient)lights \
			in the file!", 2);
		exit(1);
	}
	return (ns);
}

static bool	handle_line(t_scene *scene, char **line)
{
	int	n_c;

	n_c = scene->cc;
	if (!ft_strncmp(line[0], "A", 3))
		return (get_alight(line, scene->alight));
	else if (!ft_strncmp(line[0], "L", 3))
		return (get_light(line, scene->light));
	else if (!ft_strncmp(line[0], "C", 3))
		return (get_camera(line, scene->camera));
	else if (!ft_strncmp(line[0], "sp", 4))
		return (get_sphere(line, scene->sph[scene->cs++]));
	else if (!ft_strncmp(line[0], "pl", 4))
		return (get_plane(line, scene->pla[scene->cp++]));
	else if (!ft_strncmp(line[0], "cy", 4))
		return (get_cylinder(line, n_c, scene->cyl[scene->cc++]));
	else
		return (berror("Error\nUnknown identifier in the scene!"));
}

t_scene	*reader(char *path, t_scene *scene)
{
	char	**lines;
	char	**tmp;
	int		i;
	char	*r;

	r = raw(path);
	lines = ft_split(r, '\n');
	free(r);
	scene = init_scene(count_elements(lines));
	i = 0;
	while (lines[i])
	{
		tmp = ft_split(lines[i], ' ');
		if (!scene->error && !handle_line(scene, tmp))
			scene->error = true;
		free_2darr(tmp);
		free(lines[i]);
		i++;
	}
	free(lines);
	return (scene);
}
