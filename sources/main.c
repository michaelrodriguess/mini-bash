/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:51:58 by microdri          #+#    #+#             */
/*   Updated: 2023/03/06 11:00:32 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char** argv, char **env)
{
	char			*input;
	t_data_shell	data_shell;

	(void) argc;
	(void) *argv;
	set_sig();
	data_shell.tok_lst = NULL;
	data_shell.env = env;
	while (42)
	{
		input = readline("microtano$: ");
		if (ft_strcmp(input, "exit") == 0 || input == NULL)
		{
			write(1, "exit\n", 5);
			clear_history();
			free(input);
			ft_tokclear(&data_shell.tok_lst);
			break ;
		}
		if (input[0] != 0)
			add_history(input);
		data_shell.tok_lst = lexer(input);
		parser(lexer(input));
		free(input);
		ft_tokclear(&data_shell.tok_lst);
	}
	return (0);
}
