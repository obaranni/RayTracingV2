/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_env_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 13:53:59 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/02/27 14:02:17 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

t_env			*ft_new_s_env(void)
{
	t_env		*env;

	env = (t_env *)ft_memalloc(sizeof(struct s_env));
	env->w_name = NULL;
	env->scenes = NULL;
	env->mute_signals = 0;
	return (env);
}

void			ft_destroy_env(t_env *env)
{
	g_signal_connect(env->gtk.gtk_win, "destroy",
	G_CALLBACK(gtk_main_quit), NULL);
	free(env->scenes);
	free(env);
	exit(0);
}
