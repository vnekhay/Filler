/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 20:15:12 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/18 20:15:25 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			the_smallest_one(int p, int p1, int p2, int p3)
{
	int p11;
	int p22;

	p = p > -1 ? p : 1488;
	p1 = p1 > -1 ? p1 : 1488;
	p2 = p2 > -1 ? p2 : 1488;
	p3 = p3 > -1 ? p3 : 1488;
	p11 = p > p1 ? p1 : p;
	p22 = p2 > p3 ? p3 : p2;
	p11 = p22 < p11 ? p22 : p11;
	if (p11 == 1488)
		return (-42);
	return (p11);
}

int			check_border(int i, int j, t_map *map)
{
	int p;
	int p1;
	int p2;
	int p3;

	p = i - 1 > 0 ? map->map[i - 1][j] : -1;
	p1 = j - 1 > 0 ? map->map[i][j - 1] : -1;
	p2 = i + 1 < map->y1 ? map->map[i + 1][j] : -1;
	p3 = j + 1 < map->x1 ? map->map[i][j + 1] : -1;
	return (the_smallest_one(p, p1, p2, p3));
}

t_map		*map_filler(t_map *map)
{
	int i;
	int j;
	int m;

	m = (map->x1 + map->y1);
	while (m-- > 0 && (i = -1))
	{
		while (++i < map->y1 && (j = -1))
		{
			while (++j < map->x1)
			{
				if (map->map[i][j] != 0 && map->map[i][j] != -1)
					map->map[i][j] = 1 + check_border(i, j, map);
			}
		}
	}
	return (map);
}

t_map		*who_am_i(void)
{
	char	*str;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	get_next_line(0, &str);
	map->me = (str[10] == '1') ? 'O' : 'X';
	free(str);
	return (map);
}
