#include "includes.h"

void	get_data_img(t_img *img)
{
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}

int	create_img(t_img *img, float widht, float height, t_root *root)
{
	img->widht = widht;
	img->height = height;
	img->img = mlx_new_image(root->mlx, widht, height);
	if (img->img == NULL)
		exit(0);
	get_data_img(img);
	return (1);
}
