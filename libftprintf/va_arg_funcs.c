/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:32:12 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/27 16:51:24 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long long	c_arg(va_list list, int *is_negative)
{
	char	c;

	c = (char)va_arg(list, int);
	if (c < 0)
	{
		*is_negative = 1;
		return ((unsigned long long)-c);
	}
	return (unsigned long long)c;
}

unsigned long long	s_arg(va_list list, int *is_negative)
{
	short	c;

	c = (short)va_arg(list, int);
	if (c < 0)
	{
		*is_negative = 1;
		return ((unsigned long long)-c);
	}
	return (unsigned long long)c;
}

unsigned long long	l_arg(va_list list, int *is_negative)
{
	long	c;

	c = va_arg(list, long);
	if (c < 0)
	{
		*is_negative = 1;
		return ((unsigned long long)-c);
	}
	return (unsigned long long)c;
}

unsigned long long	ll_arg(va_list list, int *is_negative)
{
	long long	c;

	c = va_arg(list, long long);
	if (c < 0)
	{
		*is_negative = 1;
		return ((unsigned long long)-c);
	}
	return (unsigned long long)c;
}

unsigned long long	i_arg(va_list list, int *is_negative)
{
	int	c;

	c = va_arg(list, int);
	if (c < 0)
	{
		*is_negative = 1;
		if (c == -2147483648)
			return (2147483648);
		return ((unsigned long long)-c);
	}
	return (unsigned long long)c;
}
