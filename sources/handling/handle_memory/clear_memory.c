/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:13:23 by microdri          #+#    #+#             */
/*   Updated: 2023/04/08 16:35:16 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	free_copy_env(char **env_copy)
{
	int	i;

	i = 0;
	while (env_copy[i])
	{
		free(env_copy[i]);
		i++;
	}
	free(env_copy);
}

void	close_red_files(t_data_shell data_shell)
{
	while (data_shell.n_redis--)
	{
		if (data_shell.fd_redis[data_shell.n_redis] > 2)
			close(data_shell.fd_redis[data_shell.n_redis]);
	}
}

void	clear_memory(t_data_shell data_shell, int end_exec)
{
	if (data_shell.input)
		free(data_shell.input);
	ft_tokclear(&data_shell.tok_lst);
	sentence_clear(&data_shell.sentence_list);
	if (data_shell.fd_pipes)
	{
		free(data_shell.fd_pipes);
		data_shell.fd_pipes = NULL;
	}
	if (data_shell.fd_redis)
	{
		close_red_files(data_shell);
		free(data_shell.fd_redis);
		data_shell.fd_redis = NULL;
	}
	data_shell.n_redis = 0;
	if (end_exec == 1)
	{
		clear_history();
		free_copy_env(data_shell.copy_env);
	}
}
