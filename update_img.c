#include "includes.h"

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
				color -= 0x0f0f0f0f;
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

	i = 0;
	while (i < root->grid.agent_nb)
		pixel_put(&root->img, root->grid.agent[i++].pos, 0xffffffff);

	mlx_put_image_to_window(root->mlx, root->win.win, root->img.img, 0, 0);
	return (1);
}
