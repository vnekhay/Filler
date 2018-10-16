/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_adds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 01:58:02 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/19 01:58:44 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/filler.h"
#include <mlx.h>

void		fill_map(t_mlx *mlx)
{
	int x;
	int y;

	get_next_line(0, &mlx->str);
	free(mlx->str);
	mlx->map = (char **)malloc(sizeof(char *) * (mlx->i + 1));
	x = -1;
	while (++x < mlx->i)
	{
		y = -1;
		mlx->map[x] = (char *)malloc(sizeof(char) * (mlx->j + 1));
		ft_bzero(mlx->map[x], mlx->j + 1);
		get_next_line(0, &mlx->str);
		while (++y < mlx->j)
			mlx->map[x][y] = mlx->str[4 + y];
		free(mlx->str);
	}
	mlx->map[x] = 0;
}

void		draw_who_we_are(t_mlx *mlx)
{
	STR(PTR, WIN, 150, 100, 0x00FF00, "Player O: ");
	STR(PTR, WIN, 250, 100, 0x00FF00, mlx->po);
	STR(PTR, WIN, 150, 150, 0x4169E1, "Player X: ");
	STR(PTR, WIN, 250, 150, 0x4169E1, mlx->px);
}

void		draw_xx(int a, int b, t_mlx *mlx)
{
	int x;
	int y;

	x = (250 + ((((500 / mlx->j) * b)) + 1));
	while (x < (250 + ((((500 / mlx->j) * (b + 1))))))
	{
		y = (250 + ((((500 / mlx->i) * a)) + 1));
		while (y < (250 + ((((500 / mlx->i) * (a + 1) - 1)))))
			PXL(PTR, WIN, x, y++, 0x4169E1);
		PXL(PTR, WIN, x++, y, 0x4169E1);
	}
}

void		draw_new_xx(int a, int b, t_mlx *mlx)
{
	int x;
	int y;

	x = (250 + ((((500 / mlx->j) * b)) + 1));
	while (x < (250 + ((((500 / mlx->j) * (b + 1))))))
	{
		y = (250 + ((((500 / mlx->i) * a)) + 1));
		while (y < (250 + ((((500 / mlx->i) * (a + 1) - 1)))))
			PXL(PTR, WIN, x, y++, 0x0000CD);
		PXL(PTR, WIN, x++, y, 0x0000CD);
	}
}
