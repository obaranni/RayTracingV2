/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:18:18 by obaranni          #+#    #+#             */
/*   Updated: 2018/03/19 23:12:41 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <gtk/gtk.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <libc.h>
# include <pthread.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include "ini.h"
# define W_H 600
# define W_W 900
# define IMG (img->img_str)
# define BPP (img->bpp)
# define QIMG (q_img->img_str)
# define QBPP (q_img->bpp)
# define N (atr->q.obj->get_norm_vect(atr->q.obj->data, &(atr->q.inters_pnt)))
# define THR_C 1

struct s_env;
struct s_col;
struct s_square;
struct s_obj;

typedef struct			s_vect
{
	double				x;
	double				y;
	double				z;
}						t_vect;

typedef struct			s_vecparr
{
	t_vect				*a_b_c;
	const t_vect		*start_pnt;
	const t_vect		*vect;
}						t_vecparr;

typedef struct			s_vecparr2
{
	t_vect				*inters_pnt;
	t_vect				*dirr;
}						t_vecparr2;

typedef struct			s_vecarr
{
	t_vect				a;
	t_vect				b;
	t_vect				c;
	t_vect				d;
	t_vect				e;
	t_vect				f;
	t_vect				k2;
}						t_vecarr;

typedef struct			s_col
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
	unsigned char		a;
}						t_col;

typedef struct			s_newcol
{
	int					r;
	int					g;
	int					b;
	int					qual;
	int					refl;
	int					refr;
	int					result;
	t_vect				vect;
	guchar				color[4];
}						t_newcol;

typedef struct			s_bid_list
{
	void				*data;
	struct s_bid_list	*prew;
	struct s_bid_list	*next;
}						t_bid_list;

typedef struct			s_param
{
	struct s_col		col;
	struct s_vect		pos;
	struct s_vect		dir;
}						t_param;

typedef struct			s_light
{
	double				intense;
	struct s_vect		pos;
	struct s_vect		direction;
	struct s_col		color;
	double				radius;
	double				type;
}						t_light;

typedef struct			s_camera
{
	struct s_vect		position;
	struct s_vect		w;
	struct s_vect		v;
	struct s_vect		u;
	struct s_vect		alpha;
	double				distanse;
	double				left;
	double				right;
	double				top;
	double				bottom;
}						t_camera;

typedef struct			s_img
{
	unsigned char		*img_str;
	GdkPixbuf			*pixbuf;
	GtkImage			*image;
	int					bpp;
	int					sl;
	int					w;
	int					h;
}						t_img;

typedef struct			s_backup
{
	ini_t				*ini;
	char				*f_name;
	char				*buf;
	int					count;
}						t_backup;

typedef struct			s_scene
{
	t_img				img;
	t_img				pre_img;
	struct s_camera		cam;
	struct s_bid_list	*objs;
	struct s_bid_list	*lights;
	double				amb;
	double				qual;
	char				*name;
	struct s_env		*env;
	struct s_square		*sq_b;
	t_backup			backup;
	int					specularity;
	int					sepia_flag;
	int					cartoon_flag;
}						t_scene;

typedef struct			s_cut
{
	int					type;
	int					axis;
	double				cut_min;
	double				cut_max;
}						t_cut;

typedef struct			s_sphere
{
	struct s_vect		position;
	struct s_col		color;
	struct s_obj		*obj;
	struct s_vect		dir;
	double				radius;
	struct s_cut		cut;
	double				flag_sq;
}						t_sphere;

typedef struct			s_elips
{
	struct s_vect		position;
	struct s_col		color;
	struct s_obj		*obj;
	struct s_vect		dir;
	double				dist;
	double				rad;
	struct s_vect		a_b_c;
	struct s_cut		cut;
	double				flag_sq;
}						t_elips;

typedef struct			s_cylinder
{
	struct s_vect		position;
	struct s_col		color;
	struct s_obj		*obj;
	struct s_vect		direction;
	double				radius;
	struct s_cut		cut;
	double				flag_sq;
}						t_cylinder;

typedef struct			s_cone
{
	struct s_vect		position;
	struct s_col		color;
	struct s_obj		*obj;
	struct s_vect		direction;
	double				angel;
	struct s_cut		cut;
	double				flag_sq;
}						t_cone;

typedef struct			s_plane
{
	struct s_vect		position;
	struct s_col		color;
	struct s_obj		*obj;
	struct s_vect		direction;
	struct s_cut		cut;
	double				flag_sq;
}						t_plane;

typedef struct			s_mtrx
{
	double				mtrx[4][4];
}						t_mtrx;

typedef struct			s_square
{
	struct s_vect		position;
	struct s_col		color;
	struct s_obj		*obj;
	struct s_vect		direction;
	struct s_vect		position_base;
	double				k;
	int					side;
	double				flag_sq;
}						t_square;

typedef struct			s_poly
{
	struct s_obj		*obj;
	struct s_vect		pos_a;
	struct s_vect		pos_b;
	struct s_vect		pos_c;
	struct s_col		color;
	struct s_vect		direction;
	double				flag_sq;
}						t_poly;

typedef struct			s_disc
{
	struct s_vect		position;
	struct s_col		color;
	struct s_obj		*obj;
	struct s_vect		direction;
	double				radius;
	double				flag_sq;
}						t_disc;

typedef struct			s_parab
{
	struct s_vect		position;
	struct s_col		color;
	struct s_obj		*obj;
	struct s_vect		direction;
	double				k;
	struct s_cut		cut;
	double				flag_sq;
}						t_parab;

typedef struct			s_obj
{
	void				*data;
	t_scene				*scene;
	unsigned int		type;
	int					not_rotate;
	struct s_obj		*parent;
	int					(*intersect)(struct s_obj *obj,
									const t_vect *start_pnt,
									const t_vect *vect,
									t_vect *inters_pnt);
	double				(*cut)(t_vect	t_t1_t2,
									const t_vect *start_pnt,
									const t_vect *vect,
									void *data);
	struct s_col		(*get_col)(const void *data,
									const t_vect *inters_pnt);
	struct s_vect		(*get_norm_vect)(void *data,
										const t_vect *inters_pnt);
	int					flag_soft_light;
	void				(*destruct_data)(void *data);
	t_col				current_col;
	double				refl;
	double				refr;
}						t_obj;

typedef struct			s_gtk
{
	GtkAdjustment		*red_adj;
	GtkBuilder			*builder;
	GtkWidget			*gtk_win;
	GtkWidget			*sepia_check;
	GtkWidget			*cartoon_check;
	GtkWidget			*label_null;
	GtkImage			*main_gtk_img;
	GtkAdjustment		*green_adj;
	GtkAdjustment		*blue_adj;
	GtkAdjustment		*posx_adj;
	GtkAdjustment		*posy_adj;
	GtkAdjustment		*posz_adj;
	GtkAdjustment		*spec_adj;
	GtkAdjustment		*refr_adj;
	GtkAdjustment		*refl_adj;
	GtkWidget			*rscale;
	GtkWidget			*gscale;
	GtkWidget			*bscale;
	GtkWidget			*spscale;
	GtkWidget			*refrscale;
	GtkWidget			*reflscale;
	GtkWidget			*xspin;
	GtkWidget			*yspin;
	GtkWidget			*zspin;
	GtkWidget			*null_butt;
	GtkWidget			*obj_box;
	GtkWidget			*lab_obj_name;
	GtkWidget			*back_butt;
	GtkWidget			*save_butt;
	GtkSpinner			*spinner;
	GtkEventBox			*previeweventbox;
	int					backup_fl;
	int					save_fl;
	int					num;
	char				name[2];
}						t_gtk;

typedef struct			s_env
{
	struct s_gtk		gtk;
	int					mute_signals;
	char				*w_name;
	struct s_bid_list	*scenes;
	t_scene				*scene;
	t_square			*current;
}						t_env;

typedef struct			s_quality
{
	double				x;
	double				y;
	double				qual;
	t_vect				dir;
	t_obj				*obj;
	t_light				*light;
	t_vect				inters_pnt;
	t_env				*env;
	double				min_obj;
	double				min_light;
}						t_quality;

typedef struct			s_atr
{
	t_img				*img;
	t_scene				*scene;
	t_quality			q;
	t_env				*env;
	t_newcol			colors;
	int					start;
	int					end;
	int					i;
	int					j;
	int					ref_numb;
	double				cosi;
	double				etai;
	double				etat;
	double				eta;
	double				sint;
	double				cost;
	double				rs;
	double				rp;
}						t_atr;

typedef struct			s_crutch
{
	t_env				*env;
	t_quality			*m_q;
	t_scene				*scene;
}						t_crutch;

int						throw_a_ray(t_atr *atr, int ref_numb,
										t_vect ray_start_point);
int						get_refl_color(int mirr_col, int obj_col,
											double refl_coef);

double					ini_get_refl_coef(ini_t *ini, int section);
unsigned int			get_int_col(const t_obj *obj, double *k,
									const t_vect *inters_pnt);
int						create_file(ini_t *ini_tmp, t_env *env);
char					*name_set(t_env *env);
void					ftoa(double n, char *res, int afterpoint);
double					ft_atof(const char *str);
int						refr_refl_backup(ini_t *ini, t_obj *obj, int sect_id);
int						pln_backup(ini_t *ini, t_obj *obj, int sect_id);
int						sph_backup(ini_t *ini, t_obj *obj, int sect_id);
int						cyl_backup(ini_t *ini, t_obj *obj, int sect_id);
int						con_backup(ini_t *ini, t_obj *obj, int sect_id);
int						squ_backup(ini_t *ini, t_obj *obj, int sect_id);
int						dis_backup(ini_t *ini, t_obj *obj, int sect_id);
int						eli_backup(ini_t *ini, t_obj *obj, int sect_id);
int						par_backup(ini_t *ini, t_obj *obj, int sect_id);

t_env					*ft_new_s_env(void);
t_vect					ft_vec_sum(t_vect v1, t_vect v2);
t_vect					ft_vec_mul_scal(t_vect v, double n);
t_mtrx					ft_cam_move_arbit_axis(t_vect *v, double ang_gam);
void					ft_matrix_vec_mult(t_mtrx mt, t_vect *v1);
void					ft_cam_move_forv(t_scene *scene);
void					ft_cam_move_back(t_scene *scene);
void					ft_cam_yaw(t_scene *scene, double angel);
void					ft_cam_pitch(t_scene *scene, double angel);
void					ft_cam_roll(t_scene *scene, double angel);
int						argument_check(int argc);

void					ft_destroy_env(t_env *env);
void					err_mess(char *mess, t_env *env);
void					reinit_cond(t_env *env);
void					ft_hooks(GtkWidget *widget, GdkEventKey *event,
									gpointer user_data);

int						check_d(double *t, t_vecparr v, t_obj *obj);
t_bid_list				*add_bid_lst(t_bid_list *lst, void *data);
t_light					*new_light(t_param param, t_vect secondary);
int						find_lights(t_vect *dirr, const t_obj *obj,
										t_vect *inters_pnt,
										const t_scene *scene);
void					render(t_scene *scene, double qual, t_img *img);
void					draw(t_env *env);
int						ft_rgb_to_int(unsigned char r,
											unsigned char g,
											unsigned char b);
double					*set_cartoon_filter(double	*k);
double					set_cartoon_filter_1(double	k);
void					set_sepia_filter(t_col *col);
int						check_refr_coef(t_obj *obj);
t_vect					get_reflect_ray(const t_vect *dirr, t_vect *normal);
double					find_shedow(const t_vect *inters_pnt,
										const t_scene *scene,
										const t_obj *obj, t_vect light_ray);
t_vecarr				check_soft_light(t_bid_list	*lights, t_vect *inters_pnt,
											const t_obj *obj, t_vecarr struc);
t_vecarr				compute_soft_light(t_bid_list*lights, t_vecarr struc,
											t_vect *inters_pnt,
											const t_obj *obj);
double					find_soft_light(t_scene *scene, t_vect *dirr,
											t_light **light,
											t_vect *inters_pnt);
double					cycle_shadow(const t_obj *obj, const t_vect *inters_pnt,
										t_vect light_ray, double light_ray_len);
t_vecarr				trans_shadow(t_vecarr struc, const t_obj *obj,
										t_vect *inters_pnt);
t_vecarr				spotlight(t_bid_list *lights, const t_obj *obj,
									t_vect *inters_pnt, t_vecarr struc);

/*
** vector
*/

t_vect					new_v(double x, double y, double z);
double					vect_multipl(t_vect a, t_vect b);
double					vect_mod_sqr(t_vect v);
double					vect_len(t_vect v);
t_vect					vect_substr(t_vect start, t_vect end);
t_vect					vect_sum(t_vect end, t_vect start);
void					vect_normalise(t_vect *v);
t_vect					vect_multipl_const(t_vect a, double c);
t_vect					vector_cross(t_vect v1, t_vect v2);
t_col					new_col(unsigned char r, unsigned char g,
									unsigned char b, unsigned char a);

/*
** area light
*/

t_light					*new_area_light(t_param param, t_vect secondary);
int						intersect_areal(t_light	*areal,
											const t_vect *start_pnt,
											const t_vect *vect,
											t_vect *inters_pnt);
t_col					get_col_areal(t_light	*lght,
										const t_vect *inters_pnt);
double					find_closest_obj(t_scene *scene, t_obj **obj,
										t_vect ray_start_point, t_vecparr2 v);

/*
** sphere
*/

t_obj					*new_sphere(t_vect pos, double r, t_col col, t_cut cut);
int						intersect_sphere(t_obj *obj,
											const t_vect *start_pnt,
											const t_vect *vect,
											t_vect *inters_pnt);
t_col					get_col_sphere(const void *data,
										const t_vect *inters_pnt);
void					destruct_sphere(void *data);
t_vect					get_norm_vect_sphere(void *data,
												const t_vect *inters_pnt);
double					cut_sphere(t_vect t_t1_t2, const t_vect *start_pnt,
										const t_vect *vect, void *data);
int						check_sphere_cut(t_sphere *sphere, const t_vect x_xx_t);
t_vect					cut_sphere_helper_one(t_vect t_t1_t2,
												t_sphere *sphere,
												const t_vect *vect,
												const t_vect *start_pnt);

/*
** cone
*/

t_obj					*new_cone(t_param param, double angel, t_cut cut);
int						intersect_cone(t_obj *obj,
											const t_vect *start_pnt,
											const t_vect *vect,
											t_vect *inters_pnt);
t_col					get_col_cone(const void *data,
										const t_vect *inters_pnt);
void					destruct_cone(void *data);
t_vect					get_norm_vect_cone(void *data,
												const t_vect *inters_pnt);
double					cut_cone(t_vect	t_t1_t2, const t_vect *start_pnt,
									const t_vect *vect, void *data);
int						check_cone_cut(t_cone *cone, const t_vect x_xx_t);
t_vect					cut_cone_helper_one(t_vect t_t1_t2, t_cone *cone,
												const t_vect *vect,
												const t_vect *start_pnt);

/*
** cylinder
*/

t_obj					*new_cylinder(t_param param, double r, t_cut cut);
int						intersect_cylinder(t_obj *obj,
												const t_vect *start_pnt,
												const t_vect *vect,
												t_vect *inters_pnt);
t_col					get_col_cylinder(const void *data,
											const t_vect *inters_pnt);
void					destruct_cylinder(void *data);
t_vect					get_norm_vect_cylinder(void *data,
													const t_vect *inters_pnt);
double					cut_cylinder(t_vect	t_t1_t2,
										const t_vect *start_pnt,
										const t_vect *vect, void *data);
int						check_cylinder_cut(t_cylinder *cylinder,
												const t_vect x_xx_t);
t_vect					cut_cylinder_helper_one(t_vect t_t1_t2,
													t_cylinder *cylinder,
													const t_vect *vect,
													const t_vect *start_pnt);

/*
** square
*/

t_obj					*new_square(t_param param, double k, int side,
										t_scene *scene);
int						intersect_square(t_obj *obj,
											const t_vect *start_pnt,
											const t_vect *vect,
											t_vect *inters_pnt);
t_col					get_col_square(const void *data,
										const t_vect *inters_pnt);
void					destruct_square(void *data);
t_vect					get_norm_vect_square(void *data,
												const t_vect *inters_pnt);
void					add_side_one(t_scene *scene, t_obj *base);
void					add_side_two(t_scene *scene, t_obj *base);
void					add_side_three (t_scene *scene, t_obj *base);
void					add_side_four(t_scene *scene, t_obj *base);
void					add_side_five(t_scene *scene, t_obj *base);
void					change_side_pos (t_square *square, t_obj *obj);
void					check_refr_pos(t_square *square, t_obj *obj);
double					check_square_cut(double t1,
											const t_vect *start_pnt,
											const t_vect *vect, void *data);
double					check_square_cut_help(double t1,
												const t_vect *start_pnt,
												const t_vect *vect,
												void *data);

/*
** plane
*/

t_obj					*new_plane(t_vect pos, t_vect dir,
									t_col col, t_cut cut);
int						intersect_plane(t_obj *obj,
											const t_vect *start_pnt,
											const t_vect *vect,
											t_vect *inters_pnt);
t_col					get_col_plane(const void *data,
										const t_vect *inters_pnt);
void					destruct_plane(void *data);
t_vect					get_norm_vect_plane(void *data,
												const t_vect *inters_pnt);
double					check_plane_cut(double t1, const t_vect *start_pnt,
											const t_vect *vect, void *data);

/*
** parab
*/

t_obj					*new_parab(t_param param, double scalar, t_cut cut);
int						intersect_parab(t_obj *obj,
											const t_vect *start_pnt,
											const t_vect *vect,
											t_vect *inters_pnt);
t_col					get_col_parab(const void *data,
										const t_vect *inters_pnt);
void					destruct_parab(void *data);
t_vect					get_norm_vect_parab(void *data,
												const t_vect *inters_pnt);
double					cut_parab(t_vect t_t1_t2, const t_vect *start_pnt,
									const t_vect *vect, void *data);
t_vect					cut_parab_helper_one(t_vect t_t1_t2, t_parab *parab,
							const t_vect *vect, const t_vect *start_pnt);
int						check_parab_cut(t_parab *parab, const t_vect x_xx_t);

/*
** disc
*/

t_obj					*new_disc(t_vect pos, t_vect dir,
									t_col col, double rad);
int						intersect_disc(t_obj *obj,
											const t_vect *start_pnt,
											const t_vect *vect,
											t_vect *inters_pnt);
t_col					get_col_disc(const void *data,
										const t_vect *inters_pnt);
void					destruct_disc(void *data);
t_vect					get_norm_vect_disc(void *data,
												const t_vect *inters_pnt);

/*
** pol
*/

t_obj					*new_pol(t_vect pos_a, t_vect pos_b,
									t_vect pos_c, t_col col);
int						intersect_poly(t_obj *obj,
											const t_vect *start_pnt,
											const t_vect *vect,
											t_vect *inters_pnt);
t_col					get_col_poly(const void *data,
										const t_vect *inters_pnt);
void					destruct_poly(void *data);
t_vect					get_norm_vect_poly(void *data,
												const t_vect *inters_pnt);
int						check_poly(t_poly *poly, t_vect *inters_pnt);

/*
** elips
*/

t_obj					*new_elips(t_param param, double rad,
									double dist, t_cut cut);
int						intersect_elips(t_obj *obj,
											const t_vect *start_pnt,
											const t_vect *vect,
											t_vect *inters_pnt);
t_col					get_col_elips(const void *data,
										const t_vect *inters_pnt);
void					destruct_elips(void *data);
t_vect					get_norm_vect_elips(void *data,
												const t_vect *inters_pnt);
double					cut_elips(t_vect t_t1_t2, const t_vect *start_pnt,
									const t_vect *vect, void *data);
int						check_elips_cut(t_elips *elips, t_vect x_xx_t);
t_vect					cut_elips_helper_one(t_vect t_t1_t2, t_elips *elips,
							const t_vect *vect, const t_vect *start_pnt);
int						is_it_mirror(t_atr *atr, int ref_numb);
int						is_it_glass(t_atr *atr, int ref_numb);

/*
** cam
*/

void					init_camera(t_camera *cam, ini_t *ini);
t_vect					init_cam_ray(double x, double y, const t_camera *cam);

/*
** scene
*/

t_scene					*scene_init(char *s_name, t_env *env);
void					add_obj_to_scene(t_scene *scene, t_obj *obj);

/*
** ini_get_funcs
*/

t_param					ini_get_param_side(t_col col, t_vect pos, t_vect dir);
t_vect					ini_get_secondary(ini_t *ini, int section);
const char				*ini_get_prop(ini_t const *ini,
										int section, char const *name);
t_col					ini_get_col(ini_t *ini, int section);
t_cut					ini_get_cut(ini_t *ini, int section, int *not_rot);
t_vect					ini_get_pos(ini_t *ini, int section);
t_vect					ini_get_dir(ini_t *ini, int section);
double					ini_get_refr_coef(ini_t *ini, int section);

t_cut					new_cut(int type, int axis,
									double ax_min, double ax_max);
int						backup(t_env *env);
t_param					ini_get_param(ini_t *ini, int section);
void					sph_init(t_scene *scene, ini_t *ini, int section);
void					lig_init(t_scene *scene, ini_t *ini, int section);
void					pln_init(t_scene *scene, ini_t *ini, int section);
void					cyl_init(t_scene *scene, ini_t *ini, int section);
void					con_init(t_scene *scene, ini_t *ini, int section);
void					dis_init(t_scene *scene, ini_t *ini, int section);
void					pol_init(t_scene *scene, ini_t *ini, int section);
void					par_init(t_scene *scene, ini_t *ini, int section);
void					eli_init(t_scene *scene, ini_t *ini, int section);
void					sqr_init(t_scene *scene, ini_t *ini, int section);
void					tor_init(t_scene *scene, ini_t *ini, int section);

/*
** s_img_funcs
*/

void					scale_img(t_img *q_img, double qual, t_img *img, int i);
void					image_init(t_img *img, int w, int h);

void					gtk_set_value_pos(t_env *env);
void					get_gtk_pointers(t_env *env, GtkBuilder *builder);
void					gtk_adj_set_val(t_env *env);
void					cartoon_toggled(GtkToggleButton *button,
										gpointer user_data);
void					crutch_save(t_crutch *crutch, t_env *env,
									t_scene *scene, t_quality *m_q);

/*
** matr
*/

double					***ft_rotate_x(double f_gr);
double					***ft_rotate_y(double f_gr);
double					***ft_rotate_z(double f_gr);
double					***ft_create_matrix(int i, int j, int dv);
void					ft_destroy_matrix(double ***m);
double					***ft_mulltipl_matr(double ***m1, double ***m2,
												double ***res);
void					calc_transform_matrix(t_env *env);
void					set_gtk_obj_name(t_env *env);
int						qual_hooks(GtkWidget *widget,
							GdkEventKey *event, t_scene *scene);
int						rotations(GtkWidget *widget,
									GdkEventKey *event, t_scene *scene);
int						read_ini(ini_t *ini, t_scene *scene);
char					*read_scene(char *s_name, t_scene *scene);
t_vecarr				find_shad(const t_obj *obj, t_obj *obj_shed, t_vecarr
						flag_dark_intpsh);
t_vecparr				new_vecparr(t_vect *a_b_c,
									const t_vect *start_pnt,
									const t_vect *vect);
t_vecparr2				new_vecparr2(t_vect *inters_pnt, t_vect *dirr);
#endif
