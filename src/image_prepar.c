/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_prepar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 20:34:38 by obaranni          #+#    #+#             */
/*   Updated: 2018/05/08 20:45:13 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void				squere_filling(t_newcol *col, const guchar *q_img, int len,
		int n)
{
	int				mx;
	int				my;

	my = 0;
	while (my < n)
	{
		mx = 0;
		while (mx < n)
		{
			ft_memcpy(&(col->color), (q_img + (my + (int)round(col->vect.y))
				* len + (mx + (int)round(col->vect.x)) * 3), 3);
			col->r += *(((unsigned char *)&(col->color)) + 0);
			col->g += *(((unsigned char *)&(col->color)) + 1);
			col->b += *(((unsigned char *)&(col->color)) + 2);
			mx++;
		}
		my++;
	}
}

guint32				pixel_squere(t_vect pix,
		const guchar *q_img, int len, double qual)
{
	t_newcol		col;
	int				n;

	col.r = 0;
	col.g = 0;
	col.b = 0;
	col.qual = qual;
	col.vect = pix;
	n = (int)round(1 / qual);
	squere_filling(&col, q_img, len, n);
	*((char *)&(col.color) + 0) = (char)(col.r / (n * n));
	*((char *)&(col.color) + 1) = (char)(col.g / (n * n));
	*((char *)&(col.color) + 2) = (char)(col.b / (n * n));
	return (*((guint32 *)&(col.color)));
}

void				scale_img(t_img *q_img, double qual, t_img *img, int i)
{
	int				j;
	t_vect			pix;
	guint32			buf;

	qual = !qual ? img->h / q_img->h : qual;
	i = -1;
	pix.y = 0;
	while (++i < img->h)
	{
		pix.x = 0;
		j = -1;
		while (++j < img->w)
		{
			if (qual >= 1)
				ft_memcpy((IMG + i * img->sl + j * img->bpp), QIMG +
					((size_t)(pix.y) * q_img->sl + (size_t)(pix.x) * QBPP), 3);
			else
			{
				buf = pixel_squere(pix, q_img->img_str, q_img->sl, qual);
				ft_memcpy((IMG + i * img->sl + j * BPP), (guchar *)&buf, 3);
			}
			pix.x += 1.0 / qual;
		}
		pix.y += 1.0 / qual;
	}
}
