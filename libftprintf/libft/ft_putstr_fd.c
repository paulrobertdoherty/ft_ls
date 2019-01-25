/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:09:11 by pdoherty          #+#    #+#             */
/*   Updated: 2018/09/17 19:09:13 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s[0] != '\0')
	{
		ft_putchar_fd(s[0], fd);
		ft_putstr_fd(&s[1], fd);
	}
}