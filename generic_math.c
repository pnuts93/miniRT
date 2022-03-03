/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:29:17 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/28 21:54:38 by pnuti            ###   ########.fr       */
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