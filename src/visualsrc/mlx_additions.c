/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_additions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 01:59:05 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/19 02:00:31 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/filler.h"
#include <mlx.h>

size_t		ft_count_base(intmax_t n, short int base)
{
	size_t i;

	if (n == -2147483648)
		return (11);
	if (n >= 0)
		i = 1;
	else if (n < 0)
		i = 2;
	while (n / base != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

void		who_we_are(t_mlx *mlx)
{
	int i;
	int	j;

	i = 0;
	while (i < 9 && (j = 7))
	{
		get_next_line(0, &mlx->str);
		if (ft_strstr(mlx->str, "launched"))
		{
			if (ft_strchr(&mlx->str[j], '/'))
			{
				while (mlx->str[j] != '/')
					j++;
			}
			if (i > 6)
				mlx->px = ft_strdup(&mlx->str[j + 1]);
			else
				mlx->po = ft_strdup(&mlx->str[j + 1]);
		}
		free(mlx->str);
		i++;
	}
}
