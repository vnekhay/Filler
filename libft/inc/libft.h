/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 03:47:33 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/19 02:59:18 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 999

typedef struct		s_gnl
{
	struct s_gnl	*next;
	char			*data;
	int				fd;
}					t_gnl;

char				*ft_strstr(const char *s1, const char *s2);
int					ft_isdigit(int c);
int					ft_toupper(int c);
void				ft_putnbr(int n);
void				*ft_memset(void *b, int c, size_t n);
char				*ft_strchr(char *s, int c);
char				*ft_strdup(char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
void				ft_bzero(void *s, size_t n);
int					get_next_line(const int fd, char **line);

#endif
