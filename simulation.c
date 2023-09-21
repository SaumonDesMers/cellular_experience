#include "includes.h"

void	init_simulation(t_root *root)
{
	int	i = 0;

	while (i < AGENT_NB)
	{
		root->grid.agent[i].direction = rand() % 361;
		root->grid.agent[i].pos.x = rand() % (WIDHT + 1);
		root->grid.agent[i++].pos.y = rand() % (HEIGHT + 1);
	}
}

int	look(t_agent *agent, t_root *root, int angle_offset)
{
	int			i;
	int			j;
	t_vector2	pxl;
	int			retval = 0;
	int			lenght = 10;
	int			square_size = 4;
	float		angle = rad(agent->direction + angle_offset);
	float		cos_angle = cos(angle);
	float		sin_angle = sin(angle);
	t_vector2	starting_pxl = (t_vector2) {.x = agent->pos.x + lenght * cos_angle + square_size / 2 * cos(angle - M_PI_2),
								.y = agent->pos.y + lenght * sin_angle + square_size / 2 * sin(angle - M_PI_2)};

	i = -1;
	pxl.x = starting_pxl.x;
	pxl.y = starting_pxl.y;
	while (i++ < square_size)
	{
		j = -1;
		pxl.x = starting_pxl.x + i * cos_angle;
		pxl.y = starting_pxl.y + i * sin_angle;
		while (j++ < square_size)
		{
			retval += get_b(get_pixel(&root->img, pxl));

			pxl.x -= sin_angle;
			pxl.y += cos_angle;
		}
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

	while (i < AGENT_NB)
	{
		new_direction(&root->grid.agent[i], root);
		
		new_pos.x = agent[i].pos.x + root->grid.agent_speed * cos(rad(agent[i].direction));
		new_pos.y = agent[i].pos.y + root->grid.agent_speed * sin(rad(agent[i].direction));
		if (new_pos.x < 0 || new_pos.x > WIDHT
			|| new_pos.y < 0 || new_pos.y > HEIGHT)
		{
			root->grid.agent[i].direction = rand() % 361;
			continue ;
		}
		agent[i].pos.x = new_pos.x;
		agent[i].pos.y = new_pos.y;
		i++;
	}
}