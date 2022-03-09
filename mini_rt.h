/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:08:44 by pnuti             #+#    #+#             */
/*   Updated: 2022/03/09 14:57:41 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# define PI 3.14159

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

//INPUT

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct	s_vector
{
	t_point	p1;
	t_point	p2;
}	t_vector;

typedef struct s_alight
{
	double	ratio;
	int		r;
	int		g;
	int		b;
}	t_alight;

typedef struct s_cam
{
	t_point	c;
	t_point	nov_i;
	float	phi;
	float	theta;
	float	fov_w;
	float	fov_h;
}	t_cam;

typedef struct s_light
{
	t_point	c;
	double	ratio;
}	t_light;

typedef struct s_sph
{
	t_point	c;
	float	d;
	int		r;
	int		g;
	int		b;
}	t_sph;

typedef struct s_pla
{
	t_point	c;
	t_point	nov;
	int		r;
	int		g;
	int		b;
}	t_pla;

typedef struct s_cyl
{
	t_point	c;
	t_point	nov;
	float	dia;
	float	hei;
	int		r;
	int		g;
	int		b;
}	t_cyl;

typedef struct s_ns
{
	int	nc;
	int	na;
	int	nl;
	int	ny;
	int	np;
	int	ns;
}	t_ns;

typedef struct s_scene
{
	t_alight	*alight;
	t_light		*light;
	t_cam		*camera;
	t_sph		**sph;
	t_pla		**pla;
	t_cyl		**cyl;
	bool		error;
	int			cc;
	int			cp;
	int			cs;
	t_ns		ns;
}	t_scene;

typedef struct s_screen
{
	int	w;
	int	h;
}	t_screen;

typedef struct s_data
{
	t_scene		*scene;
	void		*mlx;
	void		*win;
	t_screen	screen;
}	t_data;

void	init(t_data *data, char *argv[]);
t_scene	*init_scene(t_ns ns);
t_ns	init_counter();
void	purge(t_data *data);
void	purge_scene(t_scene *scene);
void	loop(t_data *data);
void	render(t_data *data);
t_scene	*reader(char *path, t_scene *scene);
bool	check_rgb(char **rgb);
bool	check_ovector(char **ov);
bool	berror(const char	*msg);
void	free_2darr(char	**str);
bool	get_camera(char **line, t_cam *camera);
bool	get_light(char **line, t_light *light);
bool	get_alight(char **line, t_alight *alight);
bool	get_sphere(char **line, t_sph *sph);
bool	get_plane(char **line, t_pla *pla);
bool	get_cylinder(char **line, t_cyl *cyl);
float	absf(float n);
float	modulef(float n, float module);
float	*quadratic(float a, float b, float c);
int		isequal(float a, float b);
void	translate_scene(t_scene *scene);
void	rotate_scene(t_scene *scene);

//INTERSECTION

int		inter_sphere(t_data *data, t_vector ray);
int		inter_cylinder(t_data *data, t_vector ray);
int		inter_plane(t_data *data, t_vector ray);

//VECTORS

void	set_p(t_point *p, float x, float y, float z);
void	import_p(t_point *p_src, t_point *p_dst);
t_point *sum_vectors(t_point a, t_point b);
t_point	*diff_vectors(t_point a, t_point b);
float	dot(t_point v1, t_point v2);
t_point	*cross(t_point a, t_point b);
t_point	*multiply_matrix(float matrix[3][3], t_point v);
t_point	*rotate_axis(float radians, t_point v, char axis);
t_point	*mult_vect_scal(t_point v, float s);
t_point	*rotate_quaternion(t_point v, t_point u, float radians);

//TRIGONOMETRY

float	deg_to_rad(float a);
float	get_angle_xy(t_point a);

#endif