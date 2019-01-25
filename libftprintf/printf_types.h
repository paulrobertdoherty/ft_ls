/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:25:19 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/19 19:04:17 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_TYPES_H
# define PRINTF_TYPES_H

# define CHAR				'\0'
# define UNSIGNED_CHAR		'\1'
# define SHORT				'\2'
# define UNSIGNED_SHORT		'\3'
# define LONG				'\4'
# define UNSIGNED_LONG		'\5'
# define LONG_LONG			'\6'
# define UNSIGNED_LONG_LONG	'\7'
# define INTEGER			'\10'
# define UNSIGNED_INTEGER	'\11'

typedef struct				s_format
{
	int						hash;
	int						plus;
	int						minus;
	int						hh;
	int						h;
	int						l;
	int						ll;
	int						L;
	int						precision;
	int						width;
	int						zero;
	int						space;
}							t_format;

typedef	char				T;
typedef unsigned long long	ull;

#endif
