/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:06:36 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/28 21:48:12 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef IMG_WIDTH
#  define IMG_WIDTH 64
# endif

# ifndef IMG_HEIGHT
#  define IMG_HEIGHT 64
# endif

# ifndef WIN_NAME
#  define WIN_NAME "Banana allergy monkey!"
# endif

# ifndef WIN_HEIGHT_MAX
#  define WIN_HEIGHT_MAX 22
# endif

# ifndef WIN_WIDTH_MAX
#  define WIN_WIDTH_MAX 40
# endif

# ifndef IMG_NAME_MAX_LEN
#  define IMG_NAME_MAX_LEN 11
# endif

# ifndef MOVE_MAX
#  define MOVE_MAX 4
# endif

enum e_keycode
{
	Keycode_W = 13,
	Keycode_A = 0,
	Keycode_S = 1,
	Keycode_D = 2,
	Keycode_ESC = 53
};

typedef struct s_coordinate
{
	int	i;
	int	j;
}	t_coordinate;

typedef struct s_map
{
	char	**input;
	void	*mlx_win;
	int		width;
	int		height;
}	t_map;

typedef struct s_enemy
{
	t_coordinate	now;
	int				move_cnt;
}	t_enemy;

typedef struct s_elements
{
	t_coordinate	player;
	t_coordinate	exit;
	t_enemy			*enemies;
	int				enemy_cnt;
	int				collect;
}	t_elements;

typedef struct s_param
{
	void		*mlx;
	int			keycode;
	t_elements	elem;
	t_map		map;
	int			move;
	char		*char_move;
	int			game_end;
	int			frame;
}	t_param;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_stack
{
	t_coordinate	*stack;
	int				top;
}	t_stack;

int				move_enemy(t_param *param);
int				check_if_fail(t_param *param, t_coordinate coor);
void			check_enemy(t_param *param);
void			handle_perror(void);
void			handle_str_error(char *str);
void			handle_success(void *mlx, t_map *map, t_elements elem);
int				handle_fail(void *mlx, t_map *map);
void			print_img(t_param *param, char *str, int i, int j);
char			*classify_img(char c, t_coordinate *now);
char			*sl_strjoin(char *origin, char *new_read, int joint_len);
char			*sl_strnbr(int num, int *digit);
int				close_win(void);
void			push(t_coordinate *stack, int i, int j, int *top);
t_coordinate	pop(t_coordinate *stack, int *top);
int				update_and_add(char **map, int i, int j, char dest);
int				push_surround(char **map, t_stack *stack, t_coordinate now, \
				char dest);
int				is_not_wall_or_enemy(t_map map, int i, int j);
int				check_now(t_param *param);
int				check_texture(t_param *param, t_coordinate next);
void			print_background(t_param *param);
void			print_enemy(t_param *param);
void			print_map(t_param *param);
void			display_movement(t_param *param);
int				walk_direction(int keycode, t_param *param, t_coordinate *next);
int				move_player(t_param *param);
void			swap_locat(t_param *param, t_coordinate next);
void			write_movement(t_param *param);
void			read_and_init_map(void *mlx, t_map *map, int fd);
char			**copy_map(t_map map);
void			map_free(char **map, int map_i);
void			check_path(t_map map, t_elements elem, char dest, \
				t_coordinate *checked);
void			check_map_validity(t_map map, t_elements *p_elem);
int				walk_motion(t_param *param, char **img_1, char **img_2);

#endif