/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 20:49:33 by obaranni          #+#    #+#             */
/*   Updated: 2018/05/08 20:52:12 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

double		clamp(double lo, double hi, double v)
{
	return (fmax(lo, fmin(hi, v)));
}

t_vect		refract(t_atr *atr)
{
	double	k;
	t_vect	n;

	n = N;
	atr->cosi = clamp(-1, 1, vect_multipl(n, atr->q.dir));
	atr->etai = 1;
	atr->etat = 1.5;
	if (atr->q.obj && atr->q.obj->refr >= 0 && atr->q.obj->refr < 1)
	{
		if (atr->cosi < 0)
			atr->cosi *= -1;
		else
		{
			atr->etai = 1.5;
			atr->etat = 1;
			n = vect_multipl_const(n, -1);
		}
		atr->eta = atr->etai / atr->etat;
		k = 1 - atr->eta * atr->eta * (1 - atr->cosi * atr->cosi);
		if (k > 0)
			atr->q.dir = vect_sum(vect_multipl_const(atr->q.dir, atr->eta),
					vect_multipl_const(n, (atr->eta * atr->cosi - sqrt(k))));
		return (atr->q.dir);
	}
	return (vect_multipl_const(atr->q.dir, 0));
}

double		fresnel(t_atr *atr)
{
	double	kr;

	atr->cosi = clamp(-1, 1, vect_multipl(N, atr->q.dir));
	atr->etai = 1;
	atr->etat = 1.5;
	if (atr->cosi > 0)
	{
		atr->etat = 1;
		atr->etai = 1.5;
	}
	atr->sint = atr->etai / atr->etat
		* sqrt(fmax(0.f, 1 - (atr->cosi * atr->cosi)));
	if (atr->sint >= 1)
		kr = 1;
	else
	{
		atr->cost = sqrt(fmax(0.f, 1 - (atr->sint) * atr->sint));
		atr->cosi = fabsf((float)atr->cosi);
		atr->rs = ((atr->etat * atr->cosi) - (atr->etai * atr->cost))
				/ ((atr->etat * atr->cosi) + (atr->etai * atr->cost));
		atr->rp = ((atr->etai * atr->cosi) - (atr->etat * atr->cost))
				/ ((atr->etai * atr->cosi) + (atr->etat * atr->cost));
		kr = ((atr->rs * atr->rs) + (atr->rp * atr->rp)) / 2;
	}
	return (kr);
}

int			is_it_glass(t_atr *atr, int ref_numb)
{
	double	kr;
	t_vect	refr_orig;
	t_vect	bias;
	int		outside;

	kr = fresnel(atr);
	if ((vect_multipl(N, atr->q.dir)) < 0)
		outside = 1;
	else
		outside = 0;
	bias = vect_multipl_const(N, 0.001);
	if (kr < 1)
	{
		atr->q.dir = refract(atr);
		vect_normalise(&(atr->q.dir));
		if (outside)
			refr_orig = vect_substr(atr->q.inters_pnt, bias);
		else
			refr_orig = vect_sum(atr->q.inters_pnt, bias);
		return (throw_a_ray(atr, ref_numb, refr_orig));
	}
	return (0);
}
