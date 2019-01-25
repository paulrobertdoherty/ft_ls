/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:07:20 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/02 21:09:08 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_strmcat(char *s1, char *s2)
{
	int		i;
	int		l1;
	int		l2;
	char	*tr;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	tr = (char *)malloc(sizeof(char) * (2 + l1 + l2));
	send_memory_error(tr);
	i = -1;
	while (++i < l1)
		tr[i] = s1[i];
	tr[i] = '/';
	i = -1;
	while (++i < l2)
		tr[i + l1 + 1] = s2[i];
	tr[i + l1 + 1] = '\0';
	return (tr);
}
