/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:00:46 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/28 14:36:48 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	add_flags(char *str, t_format *format)
{
	if (ft_strchr(str, '#'))
		format->hash = 1;
	if (ft_strchr(str, '+'))
		format->plus = 1;
	if (ft_strchr(str, '-'))
		format->minus = 1;
	if (ft_strstr(str, "hh"))
		format->hh = 1;
	if (ft_strchr(str, 'h'))
		format->h = 1;
	if (ft_strchr(str, 'l'))
		format->l = 1;
	if (ft_strstr(str, "ll"))
		format->ll = 1;
	if (ft_strchr(str, 'L'))
		format->L = 1;
	if (ft_strchr(str, ' '))
		format->space = 1;
}

void	add_zero(char *str, t_format *format)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((ft_isdigit(str[i]) && str[i] != '0') || str[i] == '.')
			return ;
		else if (str[i] == '0')
		{
			format->zero = 1;
			return ;
		}
		i++;
	}
}

void	add_precision(char *str, t_format *format)
{
	char	*pnum;

	pnum = ft_strchr(str, '.');
	if (pnum != NULL)
		format->precision = ft_atoi(&pnum[1]);
}

void	add_width(char *str, t_format *format)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			return ;
		if (ft_isdigit(str[i]) && str[i] != '0')
		{
			format->width = ft_atoi(&str[i]);
			return ;
		}
		i++;
	}
}
