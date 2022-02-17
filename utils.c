/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:17:43 by lhorefto          #+#    #+#             */
/*   Updated: 2022/02/17 13:43:55 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

bool	check_rgb(char **rgb)
{
	int	r;
	int	g;
	int	b;

	if (ft_2darr_len(rgb) != 3)
		return false;
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255)
		return false;
	if (g < 0 || g > 255)
		return false;
	if (b < 0 || b > 255)
		return false;
	return true;
}

bool	check_ovector(char **ov)
{
	double	x;
	double	y;
	double	z;

	if (ft_2darr_len(ov) != 3)
		return false;
	x = atof(ov[0]);
	y = atof(ov[1]);
	z = atof(ov[2]);
	if (x < -1.0 || x > 1.0)
		return false;
	if (y < -1.0 || y > 1.0)
		return false;
	if (z < -1.0 || z > 1.0)
		return false;
	return true;
}

bool	berror(const char	*msg)
{
	perror(msg);
	return false;
}

void	free_2darr(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	get_rgb(int r, int g, int b)
{
	return (r * (2 << 15) + g * (2 << 7) + b);
}