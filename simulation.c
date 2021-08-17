#include "includes.h"

void	init_simulation(t_root *root)
{
	int	i = 0;

	while (i < root->grid.agent_nb)
	{
		root->grid.agent[i].direction = rand() % 361;
		root->grid.agent[i].pos.x = rand() % (root->grid.widht + 1);
		root->grid.agent[i++].pos.y = rand() % (root->grid.height + 1);
	}
}

int	look(t_agent *agent, t_root *root, int angle)
{
	int			i;
	int			j;
	t_vector2	pxl;
	int			retval = 0;

	i = 0;
	pxl.x = agent->pos.x + 20 * cos(rad(agent[i].direction + angle));
	while (i < 10)
	{
		j = 0;
		pxl.y = agent->pos.y + 20 * sin(rad(agent[i].direction + angle));
		while (j < 10)
		{
			retval += get_b(get_pixel(&root->img, pxl));
			pxl.y += sin(rad(agent[i].direction + angle));
			j++;
		}
		pxl.x += cos(rad(agent[i].direction + angle));
		i++;
	}
	return (retval);
}

void	new_direction(t_agent *agent, t_root *root)
{
	int			change_direction;
	int			angle = 30;
	int			left;
	int			front;
	int			right;

	change_direction = rand() % 101;
	if (change_direction < 2)
		agent->direction = rand() % 361;
	else
	{
		left = look(agent, root, -angle);
		front = look(agent, root, 0);
		right = look(agent, root, angle);
		if (left > front && left > right)
			agent->direction -= angle;
		else if (right > front && right > left)
			agent->direction += angle;
	}
}

void	simulation(t_root *root)
{
	t_agent		*agent = root->grid.agent;
	t_vector2	new_pos;
	int			i = 0;

	while (i < root->grid.agent_nb)
	{
		new_direction(&root->grid.agent[i], root);
		
		new_pos.x = agent[i].pos.x + root->grid.agent_speed * cos(rad(agent[i].direction));
		new_pos.y = agent[i].pos.y + root->grid.agent_speed * sin(rad(agent[i].direction));
		if (new_pos.x < 0 || new_pos.x > root->grid.widht
			|| new_pos.y < 0 || new_pos.y > root->grid.height)
		{
			root->grid.agent[i].direction = rand() % 361;
			continue ;
		}
		agent[i].pos.x = new_pos.x;
		agent[i].pos.y = new_pos.y;
		i++;
	}
}