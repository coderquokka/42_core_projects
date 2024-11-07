# records

## 241104
- planning : [structrue](#structure)
- learning : how minilibx works

## 241106
- plan > check param, init map, validate map
# structure
/root of so_long
├── Makefile (for so_long)  
├── includes/  
│   ├── so_long.h  
│   ├── get_next_line.h  
├── get_next_line/  
│   ├── Makefile (for get_next_line)  
│   ├── get_next_line.c  
│   ├── get_next_line_utils.c  
├── ft_printf/  
│   ├── Makefile (for ft_printf)  
│   ├── ft_printf.c  
│   ├── printing_utils.c  
├── libft/  
│   ├── Makefile (for libft)  
│   ├── ft_*.c (all the libft source files)  
├──src/
│   ├── main.c (for so_long)  
│   ├── utils.c (for so_long)   


## basic plan

initializing the graphics, loading the map, rendering the game state, handling player input, and checking game conditions.


### param check -> map check

(1) param check
- argc = 2 
    -> fd = open(av[1], O_RDONLY)
    -> fd >= 0
    -> ft_strcmp(av[1], ".ber", 4)

(2) read map, errcheck map
- read_map()
    : get_next_line, line by line
        -> (1)add to map() (2)count> column, row, (3)free>last line, 
        -> if (!line)
                -> last line
                -> not last line : err
- errcheck_map()
    : missing_wall() 
        -> vertical_wall(), horizontal_wall()
    : character_check() 
        -> count nbr of each()
        -> errcheck : collectives > 1, player = 1, exit = 1

## init game

(1) save layout info: nubr of > row, col, exit, player, ghost, collectable
(2) save map
(3) save id = mlx_init()
(4) save window_id = mlx_new_window()
(5) save : nbr_frame, nbr_moves, width, height, layout, map, sprite,rate ...
(6) mlx_loop_hook(id, ...)
(6) mlx_hook(win_id, )
(7) mlx_key_hook(win_id, )
(8) mlx_loop(id, ...)

## put image, graphic
(1) save images
    t_complete->floor = mlx_xpm_file_to_image()
    + ->barrier/player/exit/collectable

(2) add images in graphics
    while(height < game->heigt_map)
        width = 0
        while(game->map[height][width])
            if == c/p/e/o/1
                mlx_put_image_to_window