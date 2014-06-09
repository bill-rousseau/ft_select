/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftselect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:05:15 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSELECT_H
# define FTSELECT_H
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <sys/stat.h>

# include "libft.h"
# include "libft_match.h"
# include "libft_printf.h"

# define DEBUG			0

# define GKEY_BSP		8
# define GKEY_TAB		9
# define GKEY_RTN		13
# define GKEY_ESC		27
# define GKEY_ESP		32
# define GKEY_LEFT		37
# define GKEY_UP		38
# define GKEY_RIGHT		39
# define GKEY_DOWN		40
# define GKEY_STAR		42
# define GKEY_PLUS		43
# define GKEY_MINUS		45
# define GKEY_DOT		46
# define GKEY_DIV		47
# define GKEY_ZERO		48
# define GKEY_DEL		51

typedef struct	s_choice
{
	char		*str;
	int			check;
}				t_choice;

typedef struct	s_putmenu
{
	int			*d;
	int			argc;
	int			*pos;
	t_choice	**choice;
}				t_putmenu;

typedef struct	s_search
{
	char		*str;
	int			nbr;
	t_choice	*first;
}				t_search;

int				ft_select(t_choice **ch, t_search **s, int *argc, int search);

int				ft_st_caption(int key, int clear);
void			ft_st_check(int argc, int key, t_choice **choice, int *pos);
t_choice		*ft_st_choice(int argc, char **argv);
void			ft_st_clear(void);
int				ft_st_cmdgoto(int x, int y);
void			ft_st_cmdput(char *str);
char			*ft_st_cmdstr(char *str);
void			ft_st_color(char *str, int key, int i, int pos);
int				ft_st_columns(int argc);
int				ft_st_decal(int argc, int lines);
void			ft_st_delmenu(int *argc, t_choice **choice, int *pos);
int				ft_st_getkey(char *str);
int				ft_st_init(void);
int				ft_st_maxlen(int argc, t_choice **choice, int y);
int				ft_st_putchoice(int argc, t_choice **choice, int print);
void			ft_st_putcirc(int argc, t_choice **choice, int *pos, int key);
void			ft_st_putmenu(int argc, t_choice **choice, int pos, int key);
int				ft_st_putstr(char *str, int argc, int col, int pos);
int				ft_st_search(t_choice **o, t_search **t, char *c);
void			ft_st_signal(int n);
int				ft_st_sound(int key);
int				ft_st_termsize(int y);

char			*ft_getch(void);
char			*ft_str_center(char *str, size_t size);

#endif
