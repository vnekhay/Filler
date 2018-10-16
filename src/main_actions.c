/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 20:15:42 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/18 20:15:45 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			count(t_token *piece, t_map *map2, int x, int y)
{
	int i;
	int j;
	int sum;
	int dots;

	dots = 0;
	sum = 0;
	i = -1;
	while (++i < piece->y1 && (j = -1))
		while (++j < piece->x1)
			if ((piece->token[i][j]))
			{
				if (i + y < 0 || i + y >= map2->y1 || \
					j + x < 0 || j + x >= map2->x1)
					return (0);
				if ((map2->map)[i + y][j + x] == 0)
					return (0);
				if ((map2->map)[i + y][j + x] == -1)
					dots++;
				else
					sum = sum + (map2->map)[i + y][j + x];
			}
	sum = sum > 0 ? sum : -1;
	return (dots == 1 ? sum : 0);
}

t_token		*placing_token(t_token *token, t_map *map)
{
	int i;
	int j;
	int min;
	int tmp;

	min = INF;
	i = -token->y1;
	while (++i < (map->y1) && (j = -token->x1))
	{
		while (++j < map->x1)
		{
			tmp = count(token, map, j, i);
			if (tmp && min > tmp)
			{
				min = tmp;
				token->final_x = j;
				token->final_y = i;
			}
		}
	}
	return (min != INF ? token : 0);
}

void		return_final_coord(t_token *token, int i)
{
	if (!i)
		write(1, "0 0\n", 4);
	else
	{
		ft_putnbr(token->final_y);
		write(1, " ", 1);
		ft_putnbr(token->final_x);
		write(1, "\n", 1);
	}
}

int			main_action(t_map *map, t_token *token)
{
	char *str;

	while (1488)
	{
		map = size_of_map(map);
		if (!get_next_line(0, &str))
			return (0);
		map = map_reader(map);
		map = map_filler(map);
		token = size_of_token();
		token = token_reader(token);
		if ((token = placing_token(token, map)))
			return_final_coord(token, 1);
		else
		{
			return_final_coord(token, 0);
			break ;
		}
		free(map->map);
		free(token);
	}
	return (0);
}

int			main(void)
{
	t_map	*map;
	t_token	*token;

	map = who_am_i();
	if (!main_action(map, token))
		return (0);
	return (1);
}
