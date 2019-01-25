/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 17:16:43 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/03 11:22:44 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libftprintf/printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <unistd.h>
# include <limits.h>

typedef struct		s_args
{
	char			arg;
	struct s_args	*next;
}					t_args;

typedef struct stat	t_stats;

typedef struct		s_file
{
	char			*path;
	char			*name;
	t_stats			*stats;
}					t_file;

typedef struct		s_files
{
	unsigned int	size;
	t_file			**files;
}					t_files;

typedef int			(*t_comparison)(t_file *a, t_file *b);

void				ls(t_args *args, t_files *files, int r);
t_args				*new_t_args(char c);
int					add_arg(t_args *args, char *str);
t_files				*new_t_files();
void				add_file(t_files *files, char *path, char *file);
void				sort(t_files *files, t_args *args);
void				display(t_files *files, t_args *args, int r);
void				display_long(t_file *file, int l_spaces, int s_spaces);
void				free_t_args(t_args *args);
void				free_t_files(t_files *files);
void				send_memory_error(void *val);
void				quicksort(t_files *f, t_comparison cmp);
int					alphabetical(t_file *a, t_file *b);
int					reverse_alphabetical(t_file *a, t_file *b);
int					reverse_time_modified(t_file *a, t_file *b);
int					time_modified(t_file *a, t_file *b);
int					size_len(unsigned long long size);
void				print_error_start(char *dir);
void				display_dir(t_files *f, t_args *a, unsigned int i, int s);
void				err_putstr(char *str);
void				print_path(t_file *f);
char				*ft_strmcat(char *s1, char *s2);
int					ldir(int r, t_file *f);

#endif
