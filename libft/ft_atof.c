/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:25:05 by lhorefto          #+#    #+#             */
/*   Updated: 2022/02/12 17:57:25 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convert a string to a double
** 
*/

static double	ft_fractional(char *str)
{
	double	fra;
	double	div;

	div = 10;
	fra = 0;
	while (*str && ft_isdigit(*str))
	{
		fra += (*str - '0') / div;
		str++;
		div *= 10;
	}
	return (fra);
}

double	ft_atof(char *str)
{
	int		i;
	double	ret;
	char	*integer;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	integer = (char *)malloc(i + 1);
	ft_strlcpy(integer, str, i + 1);
	ret = (double)ft_atoi(integer);
	if (str[i] == '.')
		ret += ft_fractional(&str[++i]);
	free(integer);
	return (ret);
}
