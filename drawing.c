#include "includes.h"

void	pixel_put(t_img *img, t_vector2 coord, int color)
{
	char	*dst;

	if (coord.x < 0 || coord.x > img->widht
		|| coord.y < 0 || coord.y > img->height)
		return ;
	dst = img->addr + ((int)coord.y * img->line_length
			+ (int)coord.x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_img *img, t_vector2 coord)
{
	char	*dst;

	if (coord.x < 0 || coord.x > img->widht
		|| coord.y < 0 || coord.y > img->height)
		return (0);
	dst = img->addr + ((int)coord.y * img->line_length
			+ (int)coord.x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	draw_square(t_img *img, t_vector2 pos1, t_vector2 pos2, int color)
{
	t_vector2	coord;

	coord.x = pos1.x;
	while (coord.x < pos2.x)
	{
		coord.y = pos1.y;
		while (coord.y < pos2.y)
		{
			pixel_put(img, coord, color);
			coord.y++;
		}
		coord.x++;
	}
}

void	draw_line(t_img *img, t_vector2 pos1, t_vector2 pos2, int color)
{
	t_vector2	coord;

	coord.x = pos1.x;
	coord.y = pos1.y;
	while (coord.x < pos2.x)
	{
		pixel_put(img, coord, color);
		coord.x += pos1.x;
		coord.y += pos1.y;
	}
}

void	clear_img(t_img *img, int color)
{
	t_vector2 pos1;
	t_vector2 pos2;

	pos1.x = 0;
	pos1.y = 0;
	pos2.x = img->widht;
	pos2.y = img->height;
	draw_square(img, pos1, pos2, color);
}
