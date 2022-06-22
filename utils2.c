/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:08:12 by bkeskint          #+#    #+#             */
/*   Updated: 2022/06/16 13:37:37 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	dispatch(t_data *data, t_select *sel)
{
	void	(*f[5][3])(t_data*, int, int, float);

	f[0][0] = &tra_sph;
	f[0][1] = NULL;
	f[0][2] = &red_sph;
	f[1][0] = &tra_pla;
	f[1][1] = &rot_pla;
	f[1][2] = NULL;
	f[2][0] = &tra_cyl;
	f[2][1] = &rot_cyl;
	f[2][2] = &red_cyl;
	f[3][0] = &tra_lig;
	f[3][1] = NULL;
	f[3][2] = NULL;
	f[4][0] = &tra_cam;
	f[4][1] = &rot_cam;
	f[4][2] = NULL;
	if (f[sel->obj][sel->action])
		f[sel->obj][sel->action](data, sel->obj_id, \
			sel->dimension, sel->magnitude);
}
