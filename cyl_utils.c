/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:42:28 by pnuti             #+#    #+#             */
/*   Updated: 2022/03/11 17:10:23 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ref_cyl(t_cyl **cyl, int n)
{
	int		i;
	t_point	tmp;
	t_point	*tmp2;

	i = 0;
	while (i < n)
	{
		cyl[i]->phi = acosf(cyl[i]->nov.z);
		if (isequal(cyl[i]->phi, PI / 2))
		{
			tmp2 = rotate_axis(PI / 2, cyl[i]->nov, 'z');
			import_p(tmp2, &cyl[i]->u);
			free(tmp2);
		}
		else
		{
			set_p(&tmp, cyl[i]->nov.x, cyl[i]->nov.y, 0);
			tmp2 = cross(cyl[i]->nov, tmp);
			import_p(tmp2, &cyl[i]->u);
			free(tmp2);
		}
		i++;
	}
}

void	rotate_cyl(t_cyl *cyl, t_vector *ray)
{
	t_point	*tmp;
	t_point	*tmp2;

	tmp = rotate_quaternion(ray->p1, cyl->u, cyl->phi * -1);
	tmp2 = rotate_quaternion(ray->p2, cyl->u, cyl->phi * -1);
	import_p(tmp, &ray->p1);
	import_p(tmp2, &ray->p2);
	free(tmp);
	free(tmp2);
}