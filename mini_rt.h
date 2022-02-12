/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:08:44 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/12 17:18:39 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_alight
{
	double	ratio;
	int		r;
	int		g;
	int		b;
}	t_alight;

typedef struct s_camera
{
	double	x;
	double	y;
	double	z;
	double	vx;
	double	vy;
	double	vz;
	int		fov;
}	t_camera;

typedef struct s_light
{
	double	x;
	double	y;
	double	z;
	double	ratio;
}	t_light;

typedef struct s_sph
{
	double	x;
	double	y;
	double	z;
	double	dia;
	int		r;
	int		g;
	int		b;
}	t_sph;

typedef struct s_pla
{
	double	x;
	double	y;
	double	z;
	double	vx;
	double	vy;
	double	vz;
	int		r;
	int		g;
	int		b;
}	t_pla;

typedef struct s_cyl
{
	double	x;
	double	y;
	double	z;
	double	vx;
	double	vy;
	double	vz;
	double	dia;
	double	hei;
	int		r;
	int		g;
	int		b;
}	t_cyl;

typedef struct s_scene
{
	t_alight	*alight;
	t_light		*light;
	t_camera	*camera;
	t_sph		*sph;
	t_pla		*pla;
	t_cyl		*cyl;	
}	t_scene;

typedef struct s_screen
{
	int	w;
	int	h;
}	t_screen;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_screen	screen;
}	t_data;

void	init(t_data *data, char *argv[]);
t_scene	*init_scene();
void	purge(t_data *data);
void	purge_scene(t_scene *scene);
void	loop(t_data *data);
t_scene	*reader(char *path);
bool	check_rgb(char **rgb);
bool	check_ovector(char **ov);
bool	berror(const char	*msg);
void	free_2darr(char	**str, int l);
bool	get_camera(char **line, t_camera *camera);
bool	get_sphere(char **line, t_sph *sph);
bool	get_plane(char **line, t_pla *pla);
bool	get_cylinder(char **line, t_cyl *cyl);

#endif