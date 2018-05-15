/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:57:33 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/02/27 14:00:28 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

t_light			*new_light(t_param param, t_vect secondary)
{
	t_light		*res;

	res = ft_memalloc(sizeof(*res));
	res->pos = param.pos;
	res->direction = param.dir;
	res->color = param.col;
	res->radius = secondary.x;
	res->intense = secondary.y;
	res->type = secondary.z;
	if (res->type == 3)
	{
		res->pos = param.pos;
		res->color = param.col;
		res->direction = param.dir;
		res->radius = secondary.x;
		res->intense = secondary.y;
		res->type = secondary.z;
		vect_normalise(&res->direction);
	}
	return (res);
}

double			find_soft_light(t_scene *scene, t_vect *dirr,
						t_light **light, t_vect *inters_pnt)
{
	t_bid_list	*lghts;
	t_vect		inters_pnt_cur;
	t_light		*lght_cur;
	t_vect		m_c;

	lghts = scene->lights;
	*light = NULL;
	m_c.x = 1.0e30;
	while (lghts)
	{
		lght_cur = (t_light *)lghts->data;
		if (lght_cur->type == 3 && (intersect_areal(lght_cur,
				&scene->cam.position, dirr, &inters_pnt_cur)))
		{
			m_c.y = vect_len(vect_substr(inters_pnt_cur, scene->cam.position));
			if (m_c.y < m_c.x)
			{
				*light = lght_cur;
				m_c.x = m_c.y;
				*inters_pnt = inters_pnt_cur;
			}
		}
		lghts = lghts->next;
	}
	return (m_c.x);
}
