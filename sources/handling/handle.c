/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:52:00 by microdri          #+#    #+#             */
/*   Updated: 2023/02/28 16:46:53 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
int g_var; //assim se declara variaveis globais no escopo do projeto! 

void	handle(int signum)
{
	(void)signum;
	if (RL_ISSTATE(RL_STATE_READCMD))
	{
		// setar global para 1
		write(1, "\n", 1);
	}
	else
		ioctl(1, TIOCSTI, "\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	set_sig()
{
	signal(SIGINT, handle);
	signal(SIGQUIT, SIG_IGN);
}
