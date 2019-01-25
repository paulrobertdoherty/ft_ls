/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:01:20 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/02 21:47:24 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	send_memory_error(void *val)
{
	if (val == NULL)
	{
		perror("ft_ls: ERROR: Out of memory: Insufficient or invalid memory");
		exit(1);
	}
}

void	print_error_start(char *dir)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(dir, 2);
	ft_putstr_fd(": ", 2);
}
