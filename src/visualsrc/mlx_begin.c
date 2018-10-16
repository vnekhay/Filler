/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_begin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 01:54:31 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/19 03:03:25 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/filler.h"
#include <mlx.h>

void		draw_board(t_mlx *mlx)
{
	int		x;
	int		y;
	int		a;

	x = 250;
	y = 250;
	a = 1;
	draw_x(mlx);
	while (y < (250 + ((500 / mlx->i) * mlx->i)))
	{
		if (y == (250 + ((500 / mlx->i) * a)))
		{
			while (x < (250 + ((500 / mlx->j) * mlx->j)))
				PXL(PTR, WIN, x++, y, R);
			x = 250;
			a++;
		}
		PXL(PTR, WIN, x, y++, R);
	}
	while (x < (250 + ((500 / mlx->j) * mlx->j)))
		PXL(PTR, WIN, x++, y, R);
}

int			start_game(t_mlx *mlx)
{
	while (get_next_line(0, &mlx->str) > 0)
	{
		if (ft_strstr(mlx->str, "Plateau"))
		{
			free(mlx->str);
			fill_map(mlx);
			mlx_clear_window(PTR, WIN);
			draw_who_we_are(mlx);
			draw_board(mlx);
			draw_pieces(mlx);
			free(mlx->map);
			break ;
		}
		else if (ft_strstr(mlx->str, "=="))
			finish(mlx);
		else
			free(mlx->str);
	}
	return (0);
}

int			key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 49)
		mlx_loop_hook(PTR, start_game, mlx);
	return (0);
}

int			exit_x(void)
{
	exit(0);
}

int			main(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->str = NULL;
	mlx->i = 0;
	mlx->j = 0;
	who_we_are(mlx);
	get_next_line(0, &mlx->str);
	mlx->i = atoi(&mlx->str[8]);
	mlx->j = atoi(&mlx->str[8 + ft_count_base(mlx->i, 10)]);
	free(mlx->str);
	fill_map(mlx);
	PTR = mlx_init();
	WIN = mlx_new_window(PTR, 1000, 1000, "Filler Visualizator");
	draw_who_we_are(mlx);
	STR(PTR, WIN, 350, 800, 0x00FFFF, "Press space");
	STR(PTR, WIN, 470, 800, 0x00FFFF, "to start the game");
	draw_board(mlx);
	draw_pieces(mlx);
	mlx_hook(WIN, 2, 0, key_hook, mlx);
	mlx_hook(WIN, 17, 1L << 17, exit_x, 0);
	mlx_loop(PTR);
	return (0);
}
