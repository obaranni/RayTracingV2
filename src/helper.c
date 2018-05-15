/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 22:57:03 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/02/27 13:59:36 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int					check_d(double *t, t_vecparr v, t_obj *obj)
{
	double			d;
	double			sqrt_d;
	t_vect			t_t1_t2;

	d = v.a_b_c->y * v.a_b_c->y - 4 * v.a_b_c->x * v.a_b_c->z;
	if (d < 0)
		return (0);
	sqrt_d = sqrt(d);
	t_t1_t2.x = (-v.a_b_c->y + sqrt_d) / (2 * v.a_b_c->x);
	t_t1_t2.y = (-v.a_b_c->y - sqrt_d) / (2 * v.a_b_c->x);
	if (t_t1_t2.x < 0 && t_t1_t2.y < 0)
		return (0);
	*t = obj->cut(t_t1_t2, v.start_pnt, v.vect, obj->data);
	if (*t < 0.00001)
		return (0);
	return (1);
}

void				vect_normalise(t_vect *v)
{
	double			mod;

	mod = vect_len(*v);
	v->x /= mod;
	v->y /= mod;
	v->z /= mod;
}

void				crutch_save(t_crutch *crutch, t_env *env, t_scene *scene,
		t_quality *m_q)
{
	crutch->env = env;
	crutch->scene = scene;
	crutch->m_q = m_q;
}

t_vecarr			find_shad(const t_obj *obj,
								t_obj *obj_shed, t_vecarr flag_dark_intpsh)
{
	if ((obj_shed != obj || (obj_shed == obj &&
			!obj->scene->objs->next && !obj->scene->objs->prew)))
		flag_dark_intpsh.a.x = 1;
	if (obj_shed->refr >= 1)
		flag_dark_intpsh.a.y = 1;
	if (obj_shed->refr < 1)
		flag_dark_intpsh.a.x = check_refr_coef(obj_shed);
	return (flag_dark_intpsh);
}
