/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:51:58 by microdri          #+#    #+#             */
/*   Updated: 2023/03/02 11:31:59 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char** argv)
{
	char	*input;

	(void) argc;
	(void) *argv;
	set_sig();
	while (42)
	{
		input = readline("microtano$: ");
		if (ft_strcmp(input, "exit") == 0 || input == NULL)
		{
			write(1, "exit\n", 5);
			clear_history();
			break ;
		}
		if (input[0] != 0)
			add_history(input);
		parser(lexer(input));
		free(input);
	}
	return (0);
}
