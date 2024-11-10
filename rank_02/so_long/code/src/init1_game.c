/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:40:03 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/10 21:40:03 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_pointers(t_game *game)
{
	game->mlx_pointer = mlx_init();
	if (!game->mlx_pointer)
		return (clean_exit(-1, game, NULL, "Error: MLX init failed"));
	game->window_pointer = mlx_new_window(game->mlx_pointer,
			game->map_row * 32, game->map_column * 32, "so_long");
	if (!game->window_pointer)
		return (clean_exit(-1, game, NULL, "Error: Window creation failed"));
	return (0);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	game->map_row_idx = 0;
	while (game->map_mem_allocated && game->map_row_idx < game->map_row)
	{
		free(game->map[game->map_row_idx]);
		game->map_row_idx++;
	}
	if (game->map)
		free(game->map);
	free(game);
}

/**
 * @brief Malloc 't_game *game', assign Null, 0 to elements
 * @return 0 if malloc was successful, otherwise 1
 */
int	init_game(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		return (report_error("Malloc failed"));
	(*game)->mlx_pointer = NULL;
	(*game)->window_pointer = NULL;
	(*game)->map = NULL;
	//(*game)->image = NULL; //err: incompatible
	(*game)->map_row_idx = 0;
	(*game)->map_row = 0;
	(*game)->map_column = 0;
	(*game)->map_collectives = 0;
	(*game)->map_player = 0;
	(*game)->map_exit = 0;
	(*game)->map_mem_allocated = 0;
	return (0);
}
