/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:25:33 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/03/05 17:45:26 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void				*create_window(t_env *env)
{
	GtkBuilder		*builder;
	GError			*error;

	error = NULL;
	builder = gtk_builder_new();
	if (!gtk_builder_add_from_file(builder, "res/main_window.glade", &error))
	{
		g_critical("Can't load the file: %s", error->message);
		g_error_free(error);
	}
	env->gtk.gtk_win =
		GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
	env->gtk.main_gtk_img =
		GTK_IMAGE(gtk_builder_get_object(builder, "main_gtk_img"));
	get_gtk_pointers(env, builder);
	gtk_builder_connect_signals(builder, env);
	if (!env->gtk.gtk_win)
		g_critical("Error at getting main_window widget");
	env->gtk.builder = builder;
	srand(time(NULL));
	return (env->gtk.gtk_win);
}

void				gtk_away(t_env *env)
{
	create_window(env);
	g_signal_connect(env->gtk.gtk_win,
		"destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(G_OBJECT(env->gtk.gtk_win), "key_press_event",
		G_CALLBACK(ft_hooks), env);
	gtk_label_set_text(GTK_LABEL(env->gtk.lab_obj_name),
								"Waiting for your click");
	gtk_widget_hide(env->gtk.obj_box);
	gtk_widget_show(env->gtk.gtk_win);
}

void				init_preview(t_env *env, int argc,
								char *const *argv, t_scene *scene)
{
	char			*scene_num;
	char			*gtk_obj_name;
	GtkLabel		*lbl;

	scene_num = ft_itoa(argc);
	gtk_obj_name = ft_str_replace("previewEventBox%", "%", scene_num, 0);
	env->gtk.previeweventbox = GTK_EVENT_BOX(
				gtk_builder_get_object(env->gtk.builder, gtk_obj_name));
	g_object_set_data(G_OBJECT(env->gtk.previeweventbox), "scene", scene);
	ft_strdel(&gtk_obj_name);
	gtk_obj_name = ft_str_replace("preview%", "%", scene_num, 0);
	scene->pre_img.image = GTK_IMAGE(
			gtk_builder_get_object(env->gtk.builder, gtk_obj_name));
	ft_strdel(&gtk_obj_name);
	gtk_obj_name = ft_str_replace("lab_scene%", "%", scene_num, 0);
	lbl = GTK_LABEL(gtk_builder_get_object(env->gtk.builder, gtk_obj_name));
	gtk_label_set_text(lbl, argv[argc]);
	gtk_widget_set_visible(GTK_WIDGET(lbl), TRUE);
	ft_strdel(&gtk_obj_name);
	ft_strdel(&scene_num);
}

void				scene_while(t_env *env, int argc,
								char **argv, t_scene *scene)
{
	env->gtk.num = 0;
	env->gtk.backup_fl = 1;
	env->gtk.save_fl = 1;
	env->gtk.name[0] = 96;
	env->gtk.name[1] = '\0';
	while (argc-- > 1)
	{
		scene = scene_init(argv[argc], env);
		init_preview(env, argc, argv, scene);
		scene->backup.f_name = argv[argc];
		env->scenes = add_bid_lst(env->scenes, (void *)scene);
		env->w_name = scene->name;
	}
	env->scene = scene;
}

int					main(int argc, char **argv)
{
	t_env			*env;
	t_scene			*scene;
	t_bid_list		*scenes;

	scene = NULL;
	argument_check(argc);
	env = ft_new_s_env();
	env->current = NULL;
	gtk_init(&argc, &argv);
	gtk_away(env);
	scene_while(env, argc, argv, scene);
	gtk_adj_set_val(env);
	draw(env);
	scenes = env->scenes;
	while (env->scenes)
	{
		scene = (t_scene *)(env->scenes->data);
		render(scene, 3, &scene->pre_img);
		gtk_image_set_from_pixbuf(scene->pre_img.image,
								scene->pre_img.pixbuf);
		env->scenes = env->scenes->next;
	}
	env->scenes = scenes;
	gtk_main();
	return (0);
}
