/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytraycing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 20:54:54 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/05/13 20:55:12 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void				qual(t_atr *atr)
{
	int				buf;
	t_col			buf2;

	atr->q.dir = init_cam_ray(atr->q.x, atr->q.y,
		&atr->scene->cam);
	atr->q.min_light = find_soft_light(atr->scene,
		&(atr->q.dir), &(atr->q.light), &(atr->q.inters_pnt));
	atr->q.min_obj = find_closest_obj(atr->scene, &(atr->q.obj),
						atr->scene->cam.position,
						new_vecparr2(&(atr->q.inters_pnt), &(atr->q.dir)));
	if (atr->q.light && atr->q.obj && (atr->q.min_obj < atr->q.min_light))
		buf = throw_a_ray(atr, 0, atr->scene->cam.position);
	else if (atr->q.light)
	{
		buf2 = get_col_areal(atr->q.light, &(atr->q.inters_pnt));
		buf = ft_rgb_to_int(buf2.r, buf2.g, buf2.b);
	}
	else if (atr->q.obj)
		buf = throw_a_ray(atr, 0, atr->scene->cam.position);
	else
		buf = 0;
	ft_memcpy(atr->img->img_str + atr->img->sl * atr->i
				+ atr->j * atr->img->bpp, &buf, 3);
	atr->q.x = atr->q.x + atr->q.qual;
	atr->j++;
}

void				*get_qual_img_str(void *atrib)
{
	t_atr			*atr;

	atr = (t_atr *)atrib;
	atr->q.y = atr->start + atr->q.qual / 2;
	atr->i = (int)ceil(atr->start / atr->q.qual);
	while (atr->q.y < atr->end)
	{
		atr->j = 0;
		atr->q.x = atr->scene->qual / 2;
		while (atr->q.x < (atr->img->sl / 3) * atr->q.qual)
			qual(atr);
		atr->q.y = atr->q.y + atr->q.qual;
		atr->i++;
	}
	free(atr);
	return (NULL);
}

t_atr				*new_atr(t_scene *scene, double qual, int *i, int *n)
{
	t_atr			*atr;

	atr = ft_memalloc(sizeof(*atr));
	atr->scene = scene;
	atr->q.qual = qual;
	atr->start = (*i ? *n : 0);
	atr->end = (int)fmin(atr->start + round((W_H) / THR_C + 1), W_H);
	if ((qual >= 1) && (atr->end % (int)ceil(qual)))
		atr->end += qual - atr->end % (int)ceil(qual);
	*n = atr->end;
	return (atr);
}

void				render(t_scene *scene,
							double qual, t_img *img)
{
	t_img			*q_img;
	pthread_t		pth[THR_C];
	int				i;
	int				n;
	t_atr			*atr;

	q_img = (t_img *)ft_memalloc(sizeof(t_img));
	image_init(q_img, (int)ceil((double)W_W / qual),
			(int)ceil((double)W_H / qual));
	i = 0;
	n = 0;
	while (i < THR_C)
	{
		atr = new_atr(scene, qual, &i, &n);
		atr->img = q_img;
		pthread_create(&pth[i], NULL, get_qual_img_str, atr);
		i++;
	}
	while (i)
		pthread_join(pth[THR_C - i--], NULL);
	if (img == &scene->pre_img)
		scale_img(q_img, 0, img, 0);
	else
		scale_img(q_img, qual, img, 0);
	free(q_img);
}
