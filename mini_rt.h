/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:08:44 by pnuti             #+#    #+#             */
/*   Updated: 2022/02/11 17:29:24 by pnuti            ###   ########.fr       */
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

typedef struct	s_screen
{
	int	w;
	int	h;
}	t_screen;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	t_screen	screen;
}	t_data;


void	init(t_data *data, char *argv[]);
void	purge(t_data *data);
void	loop(t_data *data);

#endif