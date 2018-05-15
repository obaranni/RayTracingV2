/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_refr_refl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 21:16:25 by obaranni          #+#    #+#             */
/*   Updated: 2018/05/14 21:20:34 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void			reverse(char *str, int len)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int				int_to_str(int x, char str[], int d)
{
	int			i;

	i = 0;
	if (x < 0)
		x *= -1;
	while (x)
	{
		str[i] = ((x % 10) + 48);
		x = x / 10;
		i++;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str, i);
	str[i] = '\0';
	return (i);
}

void			ftoa(double n, char *res, int afterpoint)
{
	int			ipart;
	double		fpart;
	int			i;

	ipart = (int)n;
	fpart = n - (double)ipart;
	i = int_to_str(ipart, res, 0);
	if (afterpoint != 0)
	{
		res[i] = '.';
		fpart = fpart * pow(10, afterpoint);
		int_to_str((int)fpart, res + i + 1, afterpoint);
	}
}

int				refr_refl_backup(ini_t *ini, t_obj *obj, int sect_id)
{
	char		res[4];

	ftoa(obj->refl, (char *)res, 1);
	res[3] = 0;
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "refl",
	(int)ft_strlen("refl")), (char *)res, 0);
	ftoa(obj->refr, (char *)res, 1);
	res[3] = 0;
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "refr",
	(int)ft_strlen("refr")), (char *)res, 0);
	return (0);
}
