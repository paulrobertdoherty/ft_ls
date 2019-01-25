/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:04:17 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/14 21:37:54 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

T	hh(char c)
{
	if (c == 'd' || c == 'i')
		return (CHAR);
	else
		return (UNSIGNED_CHAR);
}

T	h(char c)
{
	if (c == 'd' || c == 'i')
		return (SHORT);
	else
		return (UNSIGNED_SHORT);
}

T	l(char c)
{
	if (c == 'd' || c == 'i')
		return (LONG);
	else
		return (UNSIGNED_LONG);
}

T	ll(char c)
{
	if (c == 'd' || c == 'i')
		return (LONG_LONG);
	else
		return (UNSIGNED_LONG_LONG);
}

T	no_flag(char c)
{
	if (c == 'd' || c == 'i')
		return (INTEGER);
	else
		return (UNSIGNED_INTEGER);
}
