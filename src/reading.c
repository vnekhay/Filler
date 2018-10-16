/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 20:15:29 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/18 20:15:34 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_token		*token_reader(t_token *piece)
{
	int		**suka;
	char	*str;
	int		i;
	int		j;

	suka = (int **)malloc(sizeof(int *) * piece->y1);
	i = -1;
	while (++i < piece->y1)
	{
		suka[i] = malloc(sizeof(int) * (piece->x1));
		get_next_line(0, &str);
		j = -1;
		while (++j < piece->x1)
			suka[i][j] = str[j] == '*' ? 1 : 0;
		free(str);
	}
	piece->token = suka;
	return (piece);
}

t_token		*size_of_token(void)
{
	char	*str;
	int		i;
	t_token	*token;

	str = 0;
	token = (t_token *)malloc(sizeof(t_token));
	get_next_line(0, &str);
	token->x1 = 0;
	token->y1 = 0;
	i = 6;
	while (ft_isdigit(str[i]))
		token->y1 = token->y1 * 10 + str[i++] - '0';
	i++;
	while (ft_isdigit(str[i]))
		token->x1 = token->x1 * 10 + str[i++] - '0';
	free(str);
	return (token);
}

t_map		*map_reader(t_map *map)
{
	int		i;
	int		j;
	char	*str;

	map->map = malloc(sizeof(int *) * (map->y1));
	i = -1;
	while (++i < map->y1)
	{
		map->map[i] = malloc(sizeof(int) * (map->x1));
		get_next_line(0, &str);
		j = -1;
		while (++j < map->x1)
		{
			if (str[j + 4] != '.')
				map->map[i][j] = (ft_toupper(str[j + 4]) == map->me) ? -1 : 0;
			else
				map->map[i][j] = -2;
		}
		free(str);
	}
	return (map);
}

t_map		*size_of_map(t_map *map)
{
	char	*str;
	int		i;

	map->x1 = 0;
	map->y1 = 0;
	i = 8;
	get_next_line(0, &str);
	while (ft_isdigit(str[i]))
		map->y1 = map->y1 * 10 + str[i++] - '0';
	i++;
	while (ft_isdigit(str[i]))
		map->x1 = map->x1 * 10 + str[i++] - '0';
	free(str);
	return (map);
}
