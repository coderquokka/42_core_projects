#include "../includes/so_long.h"

/**
 * @note 
 * 
 */
void	print_map(t_game *game)
{
	int	i;

	if (!game || !game->map_mem_allocated)
		return ;
	i = 0;
	ft_printf("\n");
	while (game->map[i])
	{
		ft_printf("(adr: %p)%s", (void *)game->map[i], game->map[i]);
		i++;
	}
}



void	print_t_game(t_game *game)
{
	if (!game)
		return ;

	ft_printf("\nCurrent Row: %d\t", game->map_row_idx);
	ft_printf("Max Rows: %d\t", game->map_row);
	ft_printf("Max Columns: %d\n", game->map_column);
	ft_printf("Collectives: %d\t", game->map_collectives);
	ft_printf("Players: %d\t", game->map_player);
	ft_printf("Exits: %d\t", game->map_exit);
}