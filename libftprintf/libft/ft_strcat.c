/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:09:32 by pdoherty          #+#    #+#             */
/*   Updated: 2018/09/17 19:09:33 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char *s2)
{
	int i;
	int l;

	l = ft_strlen(s1);
	i = l;
	while (s2[i - l])
	{
		s1[i] = s2[i - l];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
