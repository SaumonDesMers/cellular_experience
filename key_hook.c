#include "includes.h"

int	key_hook(int keycode, t_root *root)
{
	(void)root;
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(root->mlx, root->win.win);
		mlx_destroy_display(root->mlx);
		exit(0);
	}
	return (0);
}
