/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:29:17 by pnuti             #+#    #+#             */
/*   Updated: 2022/05/05 16:49:14 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

float	absf(float n)
{
	if (n >= 0)
		return (n);
	else
		return (n * -1);
}

float	modulef(float n, float module)
{
	int	i;

	i = 0;
	while (n > module * i)
		i++;
	i--;
	return (n - (module * (float)i));
}

float	quadratic(float a, float b, float c)
{
	float	x1;
	float	x2;

	x1 = ((b * -1) - sqrtf(powf(b, 2) - (4 * a * c))) / (2 * a);
	x2 = ((b * -1) + sqrtf(powf(b, 2) - (4 * a * c))) / (2 * a);
	return (fmin_pos(x1, x2));
}

int	isequal(float a, float b)
{
	return ((a - 0.00001 <= b) && (a + 0.00001 >= b));
}

float	fmin_pos(float n1, float n2)
{
	if ((isless(n1, n2) && isgreater(n1, 0)) || isequal(n1, n2))
		return (n1);
	else if (isless(n2, n1) && isgreater(n2, 0))
		return (n2);
	else
		return (-1);
}
