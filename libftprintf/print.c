/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:51:55 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/28 18:38:54 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	spaces(int n, int *chars)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_wc(' ', chars);
		i++;
	}
}

void		print_with_flags(char *str, t_format *format, int *chars)
{
	if (format->minus)
	{
		ft_putstr_wc(str, chars);
		spaces(format->width - (int)ft_strlen(str), chars);
	}
	else
	{
		spaces(format->width - (int)ft_strlen(str), chars);
		ft_putstr_wc(str, chars);
	}
}

void		printc_with_flags(char c, t_format *format, int *chars)
{
	if (format->minus)
	{
		ft_putchar_wc(c, chars);
		spaces(format->width - 1, chars);
	}
	else
	{
		spaces(format->width - 1, chars);
		ft_putchar_wc(c, chars);
	}
}
