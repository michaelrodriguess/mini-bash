/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:15:21 by fcaetano          #+#    #+#             */
/*   Updated: 2023/04/04 10:54:41 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(char *command)
{
	if (!ft_strcmp(command, "echo") || !ft_strcmp(command, "cd")
		|| !ft_strcmp(command, "exit") || !ft_strcmp(command, "pwd")
		|| !ft_strcmp(command, "env") || !ft_strcmp(command, "export")
		|| !ft_strcmp(command, "unset"))
		return (1);
	else
		return (0);
}

int	execute_builtins(t_data_shell *data_shell)
{
	char	*command;

	command = data_shell->sentence_list->args[0];
	if (!ft_strcmp(command, "echo")) //printar quebra de linha quando o input for echo sem argumentos ou flags
		ft_echo(&(data_shell->sentence_list->args[1]), data_shell->sentence_list->fd_out);
	if (!ft_strcmp(command, "pwd")) //atualizar $PWD e $OLDPWD
		ft_pwd();
	if (!ft_strcmp(command, "cd")) // error with only cd HOME at env[4]
		ft_cd(&(data_shell->sentence_list->args[1]), data_shell->copy_env);
	if (!ft_strcmp(command, "exit"))
		ft_exit(&(data_shell->sentence_list->args[1]));
	if (!ft_strcmp(command, "env"))
		ft_env(data_shell->copy_env);
	if (!ft_strcmp(command, "unset"))
		ft_unset(data_shell);
	if (!ft_strcmp(command, "export"))
		ft_export(data_shell);
	return (0);
}

void	execute_pipeline(t_data_shell *data_shell)
{
	config_pipes(data_shell);
	config_forks(data_shell);
}

void	execute_cmd(t_data_shell *data_shell)
{
	int	pid;

	if (data_shell->number_of_sentence == 1)
	{
		if (is_builtin(data_shell->sentence_list->args[0]) == 1)
	 		execute_builtins(data_shell);
		else
		{
			pid = fork();
			if (pid == -1)
				message_error("Error with Fork", -1);
			if (pid == 0)
			{
				if (data_shell->sentence_list->fd_in != 0)
					dup2(data_shell->sentence_list->fd_in, 0);
				if (data_shell->sentence_list->fd_out != 1)
					dup2(data_shell->sentence_list->fd_out, 1);
				if (execve(data_shell->sentence_list->args[0], data_shell->sentence_list->args, data_shell->copy_env) == -1)
				message_error("Error with exec command", -1);
			}
			else if (pid !=  0)
				wait(&pid);
		}
	}
	else if (data_shell->number_of_sentence > 1)
		execute_pipeline(data_shell);
}

void	verify_and_exec(t_data_shell *data_shell)
{
	data_shell->number_of_sentence = (count_pipes(data_shell->tok_lst) + 1);
	if (!data_shell->sentence_list)
		return ;
	else if (data_shell->sentence_list->args == NULL)
	{
		message_error("microtano: command not found", 127);
		return ;
	}
		execute_cmd(data_shell);
}
