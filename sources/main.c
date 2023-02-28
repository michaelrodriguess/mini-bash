/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:51:58 by microdri          #+#    #+#             */
/*   Updated: 2023/02/28 16:48:35 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
int g_var;

int	main(void)
{
	char	*input;

	set_sig();
	while (42)
	{
		input = readline("microtano$: ");
		if(ft_strcmp(input, "exit") == 0 || input == NULL)
		{
			write(1, "exit\n", 5);
			rl_clear_history();
			break ;
		}
		add_history(input);
		free(input);
	}
	return (0);
}
