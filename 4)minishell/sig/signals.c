/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:44:16 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/27 13:40:37 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_set_term(char c)
{
	struct termios	term;

	tcgetattr(0, &term);
	if (c == '0')
		term.c_lflag &= ~ECHOCTL;
	else
		term.c_lflag |= ECHOCTL;
	tcsetattr(0, TCSANOW, &term);
}

void	ft_ctrl_c(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_ctrl_c_here(int sig)
{
	write(1, "\n", 1);
	rl_replace_line("", 0);
	exit(sig);
}

void	ft_signals(char c)
{
	struct sigaction	sig1;
	struct sigaction	sig2;

	sig1.sa_flags = SA_RESTART;
	sig2.sa_handler = SIG_IGN;
	ft_set_term('0');
	if (c == '0')
		sig1.sa_handler = &ft_ctrl_c;
	else if (c == '1')
		sig1.sa_handler = SIG_IGN;
	else if (c == '2')
		sig1.sa_handler = &ft_ctrl_c_here;
	else if (c == '3')
	{
		ft_set_term('1');
		sig1.sa_handler = SIG_DFL;
		sig2.sa_handler = SIG_DFL;
	}
	sigaction(SIGINT, &sig1, NULL);
	sigaction(SIGQUIT, &sig2, NULL);
}
