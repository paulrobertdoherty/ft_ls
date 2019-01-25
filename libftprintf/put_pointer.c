/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 21:04:56 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/25 10:39:20 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	put_pointer(va_list list, t_format *format, int *chars)
{
	void	*val;
	char	*num;
	int		z;

	val = va_arg(list, void *);
	format->hash = 1;
	z = 0;
	num = get_num_str(&z, (unsigned long long)val, 'x', format);
	ft_putstr_wc(num, chars);
	free(num);
}
