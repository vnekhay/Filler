/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 03:00:41 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/19 03:02:19 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/inc/libft.h"

static t_gnl	*find(t_gnl **gnl, int fd)
{
	t_gnl	*new;
	t_gnl	*tmp;

	tmp = *gnl;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		if (tmp->next == 0)
			break ;
		tmp = tmp->next;
	}
	new = malloc(sizeof(t_gnl));
	if (*gnl != 0)
		(tmp)->next = new;
	else
		*gnl = new;
	new->fd = fd;
	new->data = 0;
	new->next = 0;
	return (new);
}

static void		write_again(char **dest, char *s0, char *s2)
{
	char		*tmp;

	tmp = ft_strjoin(s0, s2);
	if (!*tmp)
	{
		free(tmp);
		tmp = 0;
	}
	if (*dest)
		free(*dest);
	*dest = tmp;
}

static int		ret(char **f, char **line, char **buffer)
{
	free(*buffer);
	if (*f)
	{
		*line = ft_strdup(*f);
		free(*f);
		*f = 0;
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl = 0;
	t_gnl			*ptr;
	char			*buffer;

	if (fd < 0 || !line || read(fd, 0, 0) < 0)
		return (-1);
	ptr = find(&gnl, fd);
	buffer = malloc(sizeof(char) * (BUFF_SIZE + 1));
	while (1)
	{
		if (ptr->data && ft_strchr(ptr->data, '\n'))
		{
			*line = ft_strsub(ptr->data, 0, \
					ft_strchr(ptr->data, '\n') - ptr->data);
			write_again(&ptr->data, 0, ft_strchr(ptr->data, '\n') + 1);
			free(buffer);
			return (1);
		}
		ft_memset(buffer, 0, BUFF_SIZE + 1);
		read(fd, buffer, BUFF_SIZE);
		if (!(*buffer))
			return (ret(&ptr->data, line, &buffer));
		write_again(&ptr->data, ptr->data, buffer);
	}
}
