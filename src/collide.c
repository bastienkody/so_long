#include "../inc/so_long.h"

void	collide(void)
{
	return ;
}

void	player_collect(t_vars *vars)
{
	if (vars->map[vars->player->y][vars->player->x] == 'C')
	{
		vars->player->points += 1;
		vars->map[vars->player->y][vars->player->x] = '0';
	}
}
void	player_exit(void)
{
	return ;
}
