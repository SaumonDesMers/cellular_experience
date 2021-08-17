#include "includes.h"

t_bool	init(t_root *root)
{
	int	i = -1;

	root->win.widht = 500;
	root->win.height = 500;

	root->grid.widht = root->win.widht;
	root->grid.height = root->win.height;
	root->grid.agent_nb = 500;
	root->grid.agent_speed = 1;
	if (!(root->grid.agent = malloc(sizeof(t_agent) * root->grid.agent_nb)))
		return (ERROR);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_root		root;
	int			signal;

	srand(time(NULL));
	(void)ac;
	(void)av;
	init(&root);

	root.mlx = mlx_init();
	root.win.win = mlx_new_window(root.mlx, root.win.widht, root.win.height, "fdf");
	create_img(&root.img, root.win.widht, root.win.height, &root);

	mlx_hook(root.win.win, 2, 1L << 0, key_hook, &root);
	mlx_loop_hook(root.mlx, update_img, &root);
	mlx_mouse_hook(root.win.win, mouse_hook, &root);

	init_simulation(&root);

	mlx_loop(root.mlx);
	return (0);
}