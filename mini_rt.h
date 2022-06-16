/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:08:44 by pnuti             #+#    #+#             */
/*   Updated: 2022/06/16 10:15:12 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# define PI 3.141592
# define OFFSET 100
# define LINE 20

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

//INPUT

typedef unsigned int	t_uint;

enum e_shape_type
{
	SP,
	PL,
	CY,
	DI,
	NA
};

enum e_obj_sel
{
	SPHERE,
	PLANE,
	CYLINDER,
	LIGHT,
	CAMERA
};

enum e_action
{
	TRA,
	ROT,
	RED
};

typedef struct s_img
{
	void	*img;
	char	*address;
	int		bppx;
	int		len;
	int		endian;
}	t_img;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_ray
{
	t_point	p1;
	t_point	p2;
	float	t;
	int		shape_sel[3];
}	t_ray;

typedef struct s_alight
{
	double	ratio;
	t_rgb	color;
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
	t_rgb	color;
}	t_sph;

typedef struct s_pla
{
	t_point	c;
	t_point	nov;
	t_rgb	color;
}	t_pla;

typedef struct s_cyl
{
	t_point	c;
	t_point	nov;
	t_point	u;
	float	dia;
	float	hei;
	float	phi;
	int		n;
	t_rgb	color;
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

typedef struct s_select
{
	int		step;
	int		obj;
	int		obj_id;
	int		max_id;
	int		action;
	char	dimension;
	float	magnitude;
}	t_select;

typedef struct s_data
{
	t_img		img;
	t_img		cmd_backg;
	t_scene		*scene;
	void		*mlx;
	void		*win;
	t_screen	screen;
	bool		done;
}	t_data;

void	init(t_data *data, char *argv[]);
t_scene	*init_scene(t_ns ns);
t_ns	init_counter(void);
void	purge(t_data *data);
void	purge_scene(t_scene *scene);
void	loop(t_data *data);
void	render(t_data *data);
t_scene	*reader(char *path, t_scene *scene);
bool	check_rgb(char **rgb);
bool	check_ovector(char **ov);
bool	berror(char *msg);
void	free_2darr(char	**str);
bool	get_camera(char **line, t_cam *camera);
bool	get_light(char **line, t_light *light);
bool	get_alight(char **line, t_alight *alight);
bool	get_sphere(char **line, t_sph *sph);
bool	get_plane(char **line, t_pla *pla);
bool	get_cylinder(char **line, int n, t_cyl *cyl);
float	absf(float n);
float	modulef(float n, float module);
float	quadratic(float a, float b, float c);
int		isequal(float a, float b);
void	translate_scene(t_scene *scene);
void	rotate_scene(t_scene *scene);
void	ref_cyl(t_cyl **cyl, int n);
void	rotate_cyl(t_cyl *cyl, t_ray *ray);
t_uint	get_rgb(float coeff, t_data *data, t_ray *ray);
void	set_rgb_shape(void (*f[3])(t_data*, t_rgb*, t_ray*));
float	fmin_pos(float n1, float n2);
void	get_shape(t_data *data, t_ray *ray);
t_point	norm_sphere(t_data *data, t_ray *ray, t_point collision);
t_point	norm_plane(t_data *data, t_ray *ray, t_point collision);
t_point	norm_cylinder(t_data *data, t_ray *ray, t_point collision);
t_point	norm_disk(t_data *data, t_ray *ray, t_point collision);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
float	get_shadow(t_data *data, t_point p1, t_point p2, float tlight);
void	init_backg(t_data *data);
void	init_sel(t_select *sel);
void	tra_sph(t_data *data, int obj_id, int dimension, float magnitude);
void	red_sph(t_data *data, int obj_id, int dimension, float magnitude);
void	tra_pla(t_data *data, int obj_id, int dimension, float magnitude);
void	rot_pla(t_data *data, int obj_id, int dimension, float magnitude);
void	tra_cyl(t_data *data, int obj_id, int dimension, float magnitude);
void	rot_cyl(t_data *data, int obj_id, int dimension, float magnitude);
void	red_cyl(t_data *data, int obj_id, int dimension, float magnitude);
void	tra_lig(t_data *data, int obj_id, int dimension, float magnitude);
void	tra_cam(t_data *data, int obj_id, int dimension, float magnitude);
void	rot_cam(t_data *data, int obj_id, int dimension, float magnitude);

//INTERSECTION

float	inter_sphere(t_sph *sph, t_ray *ray);
float	inter_cylinder(t_cyl *cyl, t_ray *ray);
float	inter_plane(t_pla *pla, t_ray *ray);

//VECTORS

void	normalise(t_point *v);
void	set_p(t_point *p, float x, float y, float z);
void	import_p(t_point *p_src, t_point *p_dst);
t_point	sum_vectors(t_point a, t_point b);
t_point	diff_vectors(t_point a, t_point b);
float	dot(t_point v1, t_point v2);
t_point	cross(t_point a, t_point b);
t_point	multiply_matrix(float matrix[3][3], t_point v);
t_point	rotate_axis(float radians, t_point v, char axis);
t_point	mult_vect_scal(t_point v, float s);
t_point	rotate_quaternion(t_point v, t_point u, float radians);

//TRIGONOMETRY

float	deg_to_rad(float a);
float	get_angle_xy(t_point a);

//HOOKS

void	dispatch(t_data *data, t_select *sel);
void	step0(t_data *data);
void	step1(t_data *data, t_select *sel);
void	step2(t_data *data, t_select *sel);
void	step3(t_data *data, t_select *sel);
void	step4(t_data *data, t_select *sel);
void	handle_step0(t_data *data, t_select *sel, int kn);
void	handle_step1(t_data *data, t_select *sel, int kn);
void	handle_step2(t_data *data, t_select *sel, int kn);
void	handle_step3(t_data *data, t_select *sel, int kn);
void	handle_step4(t_data *data, t_select *sel, int kn);

#endif