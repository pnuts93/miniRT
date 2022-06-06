/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:38:04 by pnuti             #+#    #+#             */
/*   Updated: 2022/06/06 10:18:52 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	matrix_zero(float matrix[3][3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

static void	xrot_matrix(float matrix[3][3], float radians)
{
	matrix[0][0] = 1;
	matrix[1][1] = cosf(radians);
	matrix[1][2] = sinf(radians);
	matrix[2][1] = matrix[1][2] * -1;
	matrix[2][2] = matrix[1][1];
}

static void	yrot_matrix(float matrix[3][3], float radians)
{
	matrix[0][0] = cosf(radians);
	matrix[1][2] = sinf(radians) * -1;
	matrix[1][1] = 1;
	matrix[2][0] = sinf(radians);
	matrix[2][2] = matrix[0][0];
}

static void	zrot_matrix(float matrix[3][3], float radians)
{
	matrix[0][0] = cosf(radians);
	matrix[0][1] = sinf(radians);
	matrix[1][0] = sinf(radians) * -1;
	matrix[1][1] = matrix[0][0];
	matrix[2][2] = 1;
}

t_point	rotate_axis(float radians, t_point v, char axis)
{
	float	matrix[3][3];

	matrix_zero(matrix);
	if (axis == 'x')
		xrot_matrix(matrix, radians);
	else if (axis == 'y')
		yrot_matrix(matrix, radians);
	else
		zrot_matrix(matrix, radians);
	return (multiply_matrix(matrix, v));
}
