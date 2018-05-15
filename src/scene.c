/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:10:11 by obaranni          #+#    #+#             */
/*   Updated: 2018/05/15 17:47:06 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INI_IMPLEMENTATION
#include "../headers/rt.h"

char			*read_scene(char *s_name, t_scene *scene)
{
	int			fd;
	char		*buf;
	int			bytes;

	buf = (char*)ft_memalloc(sizeof(char) * 14096);
	if (((fd = open(s_name, O_RDONLY)) == -1) ||
		((bytes = (int)read(fd, buf, 14096)) == -1))
	{
		free(buf);
		free(scene);
		ft_putstr(strerror(errno));
		ft_putstr(": ");
		ft_putendl(s_name);
		exit(errno);
	}
	buf[bytes] = 0;
	return (buf);
}

void			select_init_func(ini_t *ini, t_scene *scene,
		int i)
{
	const char	*obj_name;

	obj_name = ini_section_name(ini, i);
	if (ft_strequ(obj_name, "lig"))
		lig_init(scene, ini, i);
	if (ft_strequ(obj_name, "sph"))
		sph_init(scene, ini, i);
	if (ft_strequ(obj_name, "sqr"))
		sqr_init(scene, ini, i);
	if (ft_strequ(obj_name, "con"))
		con_init(scene, ini, i);
	if (ft_strequ(obj_name, "cyl"))
		cyl_init(scene, ini, i);
	if (ft_strequ(obj_name, "pln"))
		pln_init(scene, ini, i);
	if (ft_strequ(obj_name, "dis"))
		dis_init(scene, ini, i);
	if (ft_strequ(obj_name, "pol"))
		pol_init(scene, ini, i);
	if (ft_strequ(obj_name, "par"))
		par_init(scene, ini, i);
	if (ft_strequ(obj_name, "eli"))
		eli_init(scene, ini, i);
}

int				read_ini(ini_t *ini, t_scene *scene)
{
	int			s_num;
	int			i;

	i = 1;
	s_num = ini_section_count(ini);
	while (i < s_num)
	{
		select_init_func(ini, scene, i);
		i++;
	}
	return (0);
}

ini_t			*pars_ini(t_scene *scene, char *buf)
{
	ini_t		*ini;

	ini = ini_load(buf, 0);
	ini->file_name = scene->backup.f_name;
	init_camera(&scene->cam, ini);
	scene->amb = ft_atof(ini_get_prop(ini, 0, "amb"));
	scene->qual = ft_atoi(ini_get_prop(ini, 0, "qual"));
	scene->sepia_flag = ft_atoi(ini_get_prop(ini, 0, "sepia"));
	scene->cartoon_flag = ft_atoi(ini_get_prop(ini, 0, "cartoon"));
	scene->specularity = ft_atoi(ini_get_prop(ini, 0, "specularity"));
	if (scene->specularity < 1 || scene->specularity > 10)
		scene->specularity = 1;
	if (scene->cartoon_flag < 0 || scene->cartoon_flag > 1)
		scene->cartoon_flag = 0;
	if (scene->sepia_flag < 1 || scene->sepia_flag > 1)
		scene->sepia_flag = 0;
	read_ini(ini, scene);
	return (ini);
}

t_scene			*scene_init(char *s_name, t_env *env)
{
	t_scene		*scene;

	scene = ft_memalloc(sizeof(*scene));
	image_init(&scene->img, W_W, W_H);
	image_init(&scene->pre_img, W_W / 3, W_H / 3);
	scene->objs = NULL;
	scene->lights = NULL;
	scene->backup.f_name = s_name;
	scene->backup.count = 1;
	scene->backup.buf = read_scene(s_name, scene);
	scene->backup.ini = pars_ini(scene, scene->backup.buf);
	scene->env = env;
	scene->name = ft_strdup(s_name);
	return (scene);
}
