/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:08:44 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/13 11:35:27 by pnuti            ###   ########.fr       */
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

//INPUT

typedef struct	s_vector
{
	float	x1;
	float	y1;
	float	z1;
	float	x2;
	float	y2;
	float	z2;
}	t_vector;

typedef struct	s_sphere
{
	float			x;
	float			y;
	float			z;
	float			d;
//	unsigned int	rgb;
}	t_sphere;

typedef struct	s_cam
{
	float	x;
	float	y;
	float	z;
	float	nov_x;
	float	nov_y;
	float	nov_z;
	float	fov_w;
	float	fov_h;
}	t_cam;

typedef struct	s_screen
{
	int	w;
	int	h;
}	t_screen;

typedef struct	s_data
{
	//TO TEST
	t_sphere	sphere;
	t_cam		camera;
	//TO TEST
	void		*mlx;
	void		*win;
	t_screen	screen;
}	t_data;

void	init(t_data *data, char *argv[]);
void	purge(t_data *data);
void	loop(t_data *data);

//INTERSECTION

int		inter_sphere(t_data *data, t_vector ray);

#endif