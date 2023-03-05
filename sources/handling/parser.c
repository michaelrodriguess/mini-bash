/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:45:22 by microdri          #+#    #+#             */
/*   Updated: 2023/03/02 19:53:42 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char **parser(t_token *token_lst)
{
	char *command;
	
	if (token_lst == NULL)
		return (NULL);
	command = token_lst->str;
	if (is_builtin(command) == 1)
	{
		parser_builtin(token_lst);
	}

	return (NULL);
}
