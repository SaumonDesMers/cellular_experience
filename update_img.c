#include "includes.h"

void	decrease_color(t_img *img, t_root *root)
{
	int			color;
	t_vector2	coord;

	coord.x = 0;
	while (coord.x < WIDHT)
	{
		coord.y = 0;
		while (coord.y < HEIGHT)
		{
			color = get_pixel(img, coord);
			if (color != 0x00000000)
				color -= 0x05050505;
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
	while (i < AGENT_NB)
		pixel_put(&root->img, root->grid.agent[i++].pos, 0xffffffff);

	mlx_put_image_to_window(root->mlx, root->win.win, root->img.img, 0, 0);
	return (1);
}
