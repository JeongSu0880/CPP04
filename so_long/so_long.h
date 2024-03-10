#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
// # include "get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef WIN_NAME
#  define WIN_NAME "Banana allergy monkey!"
# endif

typedef struct s_buf
{
	int		read_len;
	char	buf[BUFFER_SIZE];
}	t_buf;

typedef struct s_data//화면에 출력할 이미지에 대한 데이터
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef	struct s_obj//각각의 객체 이미지의 좌표와 길이, 너비
{
	int		width;
	int		height;
	int		x;
	int		y;
	int		count;
}	t_obj;

typedef struct s_map // 전체 화면의 길이와 mlx 변수
{
	char	**input;
	// char input[10][20];
	void *mlx_win;
	int	width;
	int height;
} t_map;

typedef struct s_elements
{
	t_obj	background;
	t_obj	wall;
	t_obj	player;
	t_obj	coin;//얘만 따로 만들지...
	t_obj	exit;
} t_elements;

typedef enum objects
{
	ZERO, ONE, P, C, E//나중에 적도 추가
} OBJECTS;

char	*get_next_line(int fd);// 아직 안씀
char	*sl_strjoin(char *origin, t_buf unit, int joint_len);
int		fill_map_input(t_map *map, char *buf, int hei, int wid);
int		get_map_size(t_map *map, char *buf);
int		read_and_init_map(void *mlx, t_map *map, int fd);

#endif