/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:29:17 by pnuti             #+#    #+#             */
/*   Updated: 2022/03/11 16:40:00 by pnuti            ###   ########.fr       */
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
	return (n - (module * (float)i));
}

float	*quadratic(float a, float b, float c)
{
	float	*quad;

	quad = (float *)malloc(sizeof(float) * 2);
	if (!quad)
		return (NULL);
	quad[0] = ((b * -1) - sqrtf(powf(b, 2) - (4 * a * c))) / 2 * a;
	quad[1] = ((b * -1) + sqrtf(powf(b, 2) - (4 * a * c))) / 2 * a;
	return (quad);
}

int	isequal(float a, float b)
{
	return ((a - 0.00001 <= b) && (a + 0.00001 >= b));
}
