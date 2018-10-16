/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 03:41:50 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/18 03:42:08 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/inc/libft.h"

char	*ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return (&s[i]);
	return (0);
}
