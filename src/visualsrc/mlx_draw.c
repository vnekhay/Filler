/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 01:55:32 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/19 01:57:49 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/filler.h"
#include <mlx.h>

void		draw_new_o(int a, int b, t_mlx *mlx)
{
	int x;
	int y;

	x = (250 + ((((500 / mlx->j) * b)) + 1));
	while (x < (250 + ((((500 / mlx->j) * (b + 1))))))
	{
		y = (250 + ((((500 / mlx->i) * a)) + 1));
		while (y < (250 + ((((500 / mlx->i) * (a + 1) - 1)))))
			PXL(PTR, WIN, x, y++, 0x008000);
		PXL(PTR, WIN, x++, y, 0x008000);
	}
}

void		draw_o(int a, int b, t_mlx *mlx)
{
	int x;
	int y;

	x = (250 + ((((500 / mlx->j) * b)) + 1));
	while (x < (250 + ((((500 / mlx->j) * (b + 1))))))
	{
		y = (250 + ((((500 / mlx->i) * a)) + 1));
		while (y < (250 + ((((500 / mlx->i) * (a + 1) - 1)))))
			PXL(PTR, WIN, x, y++, 0x00FF00);
		PXL(PTR, WIN, x++, y, 0x00FF00);
	}
}

void		draw_pieces(t_mlx *mlx)
{
	int a;
	int b;
	int x;
	int y;

	a = 0;
	x = -1;
	while (++x < mlx->i)
	{
		y = -1;
		b = 0;
		while (++y < mlx->j)
		{
			if (mlx->map[x][y] == 'x')
				draw_xx(a, b, mlx);
			else if (mlx->map[x][y] == 'X')
				draw_new_xx(a, b, mlx);
			else if (mlx->map[x][y] == 'o')
				draw_o(a, b, mlx);
			else if (mlx->map[x][y] == 'O')
				draw_new_o(a, b, mlx);
			b++;
		}
		a++;
	}
}

void		draw_x(t_mlx *mlx)
{
	int x;
	int y;
	int a;

	x = 250;
	a = 1;
	while (x < (250 + ((500 / mlx->j) * mlx->j)))
	{
		y = 250;
		if (x == (250 + ((500 / mlx->j) * a)))
		{
			while (y < (250 + ((500 / mlx->i) * mlx->i)))
				PXL(PTR, WIN, x, y++, R);
			a++;
		}
		PXL(PTR, WIN, x++, y, R);
	}
	while (y < (250 + ((500 / mlx->i) * mlx->i)))
		PXL(PTR, WIN, x, y++, R);
}
