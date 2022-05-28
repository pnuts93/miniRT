/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:12:41 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/28 21:17:18 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_point	multiply_matrix(float matrix[3][3], t_point v)
{
	t_point	res;

	res.x = matrix[0][0] * v.x + matrix[0][1] * v.y + matrix[0][2] * v.z;
	res.y = matrix[1][0] * v.x + matrix[1][1] * v.y + matrix[1][2] * v.z;
	res.z = matrix[2][0] * v.x + matrix[2][1] * v.y + matrix[2][2] * v.z;
	return (res);
}
