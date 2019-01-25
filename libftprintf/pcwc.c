/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcwc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:57:00 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/19 20:21:57 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_putchar_wc(char c, int *chars)
{
	write(1, &c, 1);
	(*chars)++;
}

void		ft_putstr_wc(char *str, int *chars)
{
	if (str[0])
	{
		ft_putchar_wc(str[0], chars);
		ft_putstr_wc(&str[1], chars);
	}
}
