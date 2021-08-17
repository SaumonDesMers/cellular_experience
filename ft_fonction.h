#ifndef FT_FONCTION_H
# define FT_FONCTION_H

/*
** simulation.c
*/
void	init_simulation(t_root *root);
void	simulation(t_root *root);

/*
** drawing.c
*/
void	pixel_put(t_img	*img, t_vector2 coord, int color);
int		get_pixel(t_img *img, t_vector2 coord);
void	draw_square(t_img *img, t_vector2 pos1, t_vector2 pos2, int color);
void	clear_img(t_img *img, int color);
void	draw_line(t_img *img, t_vector2 pos1, t_vector2 pos2, int color);

/*
** divers.c
*/
void	get_data_img(t_img *img);
int		create_img(t_img *img, float widht, float height, t_root *root);
int		update_img(t_root *root);
void	decrease_color(t_img *img, t_root *root);

/*
** key_hook.c
*/
int		key_hook(int keycode, t_root *root);

/*
** mouse_hook.c
*/
int		mouse_hook(int button, int x, int y, t_root *root);

/*
** maths.c
*/
float	rad(float x);
float	normalized(float x);
float	bornes(float x, float inf, float sup);

#endif