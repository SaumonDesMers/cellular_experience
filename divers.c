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

void	decrease_color(t_img *img, t_root *root)
{
	int			color;
	t_vector2	coord;

	coord.x = 0;
	while (coord.x < root->grid.widht)
	{
		coord.y = 0;
		while (coord.y < root->grid.height)
		{
			color = get_pixel(img, coord);
			if (color != 0x00000000)
				color -= 0x01010101;
			pixel_put(img, coord, color);
			coord.y++;
		}
		coord.x++;
	}
}

int	update_img(t_root *root)
{
	int	i = 0;

	simulation(root);

	decrease_color(&root->img, root);
	// clear_img(&root->img, 0x00000000);

	i = 0;
	while (i < root->grid.agent_nb)
		pixel_put(&root->img, root->grid.agent[i++].pos, 0xffffffff);

	mlx_put_image_to_window(root->mlx, root->win.win, root->img.img, 0, 0);
	return (1);
}
