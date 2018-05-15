/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_filecreate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 09:52:05 by obaranni          #+#    #+#             */
/*   Updated: 2018/03/19 10:19:25 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int					create_file(ini_t *ini_tmp, t_env *env)
{
	int				size;
	FILE			*fp;
	char			*data;
	char			*path;

	size = ini_save(ini_tmp, NULL, 0);
	data = (char *)ft_memalloc((size_t)size);
	size = ini_save(ini_tmp, data, size);
	ini_destroy(ini_tmp);
	path = name_set(env);
	fp = fopen(path, "w");
	fwrite(data, 1, (size_t)size, fp);
	fclose(fp);
	free(path);
	free(data);
	return (0);
}
