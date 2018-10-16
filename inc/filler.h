/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 15:06:51 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/19 02:58:03 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/inc/libft.h"
# define INF 1000000
# define STR mlx_string_put
# define PTR mlx->mlx_ptr
# define WIN mlx->win_ptr
# define PXL mlx_pixel_put
# define V 0x9900cc
# define P 0xff0066
# define R 0xFF0000

/*
** main functions and structures
*/

typedef struct		s_token
{
	int				**token;
	int				x1;
	int				y1;
	int				final_x;
	int				final_y;
}					t_token;

typedef struct		s_map
{
	int				me;
	int				x1;
	int				y1;
	int				**map;
}					t_map;

t_token				*size_of_token();
t_token				*token_reader(t_token *piece);
t_token				*placing_token(t_token *token, t_map *map);
t_map				*who_am_i(void);
t_map				*map_filler(t_map *map);
t_map				*map_reader(t_map *map);
t_map				*size_of_map(t_map *map);
int					the_smallest_one(int p, int p1, int p2, int p3);
int					count(t_token *piece, t_map *map2, int x, int y);
int					check_border(int i, int j, t_map *map);
int					main_action(t_map *map, t_token *token);

/*
** mlx functions and structures
*/

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*str;
	char			*px;
	char			*po;
	char			**map;
	int				i;
	int				j;
}					t_mlx;

size_t				ft_count_base(intmax_t n, short int base);
void				who_we_are(t_mlx *mlx);
void				draw_board(t_mlx *mlx);
int					start_game(t_mlx *mlx);
int					key_hook(int keycode, t_mlx *mlx);
int					exit_x(void);
void				draw_new_xx(int a, int b, t_mlx *mlx);
void				draw_new_o(int a, int b, t_mlx *mlx);
void				draw_o(int a, int b, t_mlx *mlx);
void				draw_pieces(t_mlx *mlx);
void				draw_x(t_mlx *mlx);
void				fill_map(t_mlx *mlx);
void				draw_who_we_are(t_mlx *mlx);
void				draw_xx(int a, int b, t_mlx *mlx);
void				draw_new_xx(int a, int b, t_mlx *mlx);
void				finish_adds2(t_mlx *mlx);
void				finish_adds(t_mlx *mlx, char *x);
void				finish(t_mlx *mlx);

#endif
