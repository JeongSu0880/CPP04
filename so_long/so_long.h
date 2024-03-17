#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
// # include <mlx_int.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
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

typedef struct s_coordinate
{
	int	i;
	int	j;
}	t_coordinate;

typedef struct s_map // 전체 화면의 길이와 mlx 변수
{
	char	**input;
	void	*mlx_win;
	int		width;
	int		height;
} t_map;

typedef struct s_elements
{
	t_coordinate	player;
	t_coordinate	exit;
	int			enemy;
	int			collect;
} t_elements;

typedef	struct s_param
{
	void	*mlx;
	t_elements	elem;
	t_map		map;
	int		move;
} t_param;


char	*get_next_line(int fd);// 아직 안씀
char	*sl_strjoin(char *origin, char *new_read, int joint_len);
void	fill_map_input(t_map *map, char *buf);
void	get_map_size(t_map *map, char *buf);
void	read_and_init_map(void *mlx, t_map *map, int fd);

void	check_map_validity(t_map map, t_elements *p_elem);
void	check_edge(t_map map);
void	check_elem(t_map map, t_elements *p_elem);
void	handle_perror();
void	handle_strerror();
void	handle_success(void *mlx, t_map map);

void	handle_fail(void *mlx, t_map map);

#endif