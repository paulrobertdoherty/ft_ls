/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:00:36 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/02 21:47:11 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_args		*new_t_args(char c)
{
	t_args *tr;

	tr = (t_args *)malloc(sizeof(t_args));
	send_memory_error(tr);
	tr->arg = c;
	tr->next = NULL;
	return (tr);
}

static void	aa(t_args *args, char c)
{
	t_args	*a;

	a = args;
	if (a->arg == '\0')
		a->arg = c;
	else if (a->next != NULL)
		aa(a->next, c);
	else
		a->next = new_t_args(c);
}

int			add_arg(t_args *args, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'R' || str[i] == 'a' || str[i] == 'l'
				|| str[i] == 'r' || str[i] == 't')
			aa(args, str[i]);
		else
		{
			ft_putstr_fd("ft_ls: illegal option -- ", 2);
			write(2, &str[i], 1);
			ft_putchar_fd('\n', 2);
			return (0);
		}
		i++;
	}
	return (1);
}

void		free_t_args(t_args *t_args)
{
	if (t_args->next != NULL)
		free_t_args(t_args->next);
	free(t_args);
}
