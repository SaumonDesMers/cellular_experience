#include "includes.h"

t_bool	init(int ac, char **av, t_root *root)
{
	int	i = -1;

	root->grid.agent_speed = 1;
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_root		root;
	int			signal;

	srand(time(NULL));
	(void)ac;
	(void)av;
	init(ac, av, &root);

	root.mlx = mlx_init();
	root.win.win = mlx_new_window(root.mlx, WIDHT, HEIGHT, "cellular experience");
	create_img(&root.img, WIDHT, HEIGHT, &root);

	mlx_hook(root.win.win, 2, 1L << 0, key_hook, &root);
	mlx_loop_hook(root.mlx, update_img, &root);
	mlx_mouse_hook(root.win.win, mouse_hook, &root);

	init_simulation(&root);

	mlx_loop(root.mlx);
	return (0);
}