#include "../inc/so_long.h"

int	player_wall(t_vars *vars, int y_offset, int x_offset)
{
	if (vars->map[vars->player->y + y_offset][vars->player->x + x_offset] == '1')
		return (1) ;
	return (0);
}

int	player_exit(t_vars *vars)
{
	if (vars->map[vars->player->y][vars->player->x] == 'E')
		return (1);
	return (0);
}

int	player_abt_to_exit(t_vars *vars)
{
	if (vars->map[vars->player->y - 1][vars->player->x] == 'E')
		return (1);
	if (vars->map[vars->player->y + 1][vars->player->x] == 'E')
		return (1);
	if (vars->map[vars->player->y][vars->player->x - 1] == 'E')
		return (1);
	if (vars->map[vars->player->y][vars->player->x + 1] == 'E')
		return (1);
	return (0);
}

void	player_collect(t_vars *vars)
{
	if (vars->map[vars->player->y][vars->player->x] == 'C')
	{
		vars->player->points += 1;
		vars->map[vars->player->y][vars->player->x] = '0';
	}
}

