/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_set_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 09:30:22 by obaranni          #+#    #+#             */
/*   Updated: 2018/03/19 10:22:21 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

char				*join_path(t_env *env, char *to)
{
	char			*folder_path;
	char			*backup_path;
	char			*backup_n;

	backup_n = ft_itoa(env->scene->backup.count);
	backup_path = ft_strjoin("scenes/backup_", backup_n);
	folder_path = ft_strjoin(backup_path, "_");
	to = ft_strjoin(folder_path, to);
	free(folder_path);
	free(backup_n);
	free(backup_path);
	return (to);
}

char				*name_set(t_env *env)
{
	int				i;
	char			*to;
	char			**path;

	path = ft_strsplit(env->scene->backup.f_name, '/');
	i = 0;
	while (path[i])
		i++;
	to = path[--i];
	to = join_path(env, to);
	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
	return (to);
}
