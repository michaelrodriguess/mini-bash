/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:56:22 by microdri          #+#    #+#             */
/*   Updated: 2023/04/08 16:39:01 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	count_pipes(t_token *lst_tok)
{
	int		count;
	t_token	*temp;

	if (!lst_tok)
		return (0);
	temp = lst_tok;
	count = 0;
	while (temp != NULL)
	{
		if (temp->type == 1)
			count++;
		temp = temp->next;
	}
	return (count);
}
