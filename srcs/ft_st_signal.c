/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:28:54 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

static int		ft_st_signal_init(void)
{
	signal(SIGBUS, &ft_st_signal);
	signal(SIGEMT, &ft_st_signal);
	signal(SIGFPE, &ft_st_signal);
	signal(SIGHUP, &ft_st_signal);
	signal(SIGINT, &ft_st_signal);
	signal(SIGSYS, &ft_st_signal);
	signal(SIGABRT, &ft_st_signal);
	signal(SIGALRM, &ft_st_signal);
	signal(SIGCONT, &ft_st_signal);
	signal(SIGKILL, &ft_st_signal);
	signal(SIGPIPE, SIG_DFL);
	signal(SIGQUIT, &ft_st_signal);
	signal(SIGSEGV, &ft_st_signal);
	signal(SIGTERM, &ft_st_signal);
	signal(SIGTTOU, &ft_st_signal);
	signal(SIGSTOP, &ft_st_signal);
	signal(SIGTSTP, &ft_st_signal);
	signal(SIGUSR1, &ft_st_signal);
	signal(SIGUSR2, &ft_st_signal);
	signal(SIGXCPU, &ft_st_signal);
	signal(SIGXFSZ, &ft_st_signal);
	signal(SIGWINCH, &ft_st_signal);
	return (1);
}

static void		ft_st_signal_set(struct termios **config)
{
	struct termios			new;

	if (*config == NULL)
	{
		ft_st_signal_init();
		*config = (struct termios *)malloc(sizeof(struct termios));
		tcgetattr(STDIN_FILENO, *config);
	}
	new = **config;
	new.c_iflag |= IGNBRK;
	new.c_lflag |= ISIG;
	new.c_lflag &= ~(ICANON | ECHO | ECHOK | ECHOE | ECHONL | IEXTEN);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &new);
	return ;
}

static int		ft_st_signal_suspend(struct termios **config, int n)
{
	char					cp[3];

	if (n == SIGTSTP)
	{
		if (*config != NULL)
		{
			ft_st_clear();
			ft_st_cmdgoto(0, 0);
			ft_st_cmdput("ve");
			tcsetattr(STDIN_FILENO, TCSANOW, *config);
			signal(SIGTSTP, SIG_DFL);
			cp[0] = (*config)->c_cc[VSUSP];
			cp[1] = '\n';
			cp[2] = '\0';
			ioctl(isatty(STDOUT_FILENO), TIOCSTI, &cp);
			free(*config);
			*config = NULL;
			return (1);
		}
	}
	ft_st_cmdput("vi");
	ft_st_signal_set(config);
	return (0);
}

void			ft_st_signal(int n)
{
	static struct termios	*config;

	if (config == NULL || n == SIGTSTP || n == SIGCONT)
	{
		if (ft_st_signal_suspend(&config, n))
			return ;
		if (n == SIGCONT)
			ft_st_putcirc(0, NULL, NULL, 0);
	}
	else if (n == 28 || n == 11)
		ft_st_putcirc(0, NULL, NULL, 0);
	else
	{
		if (DEBUG)
			ft_printf("-[%d]-", n);
		ft_st_cmdput("ve");
		ft_st_cmdput("te");
		tcsetattr(STDIN_FILENO, TCSANOW, config);
		free(config);
		if (n != -1)
			exit(0);
	}
}
