/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:30:46 by microdri          #+#    #+#             */
/*   Updated: 2023/02/28 16:44:21 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit(char **arguments)
{
	int i = 0;

	while (arguments[i] != '\0')
		i++;

	if (i <= 2)
		//executar bult-in; 
		//se for 2 argumentos transformar segundo argumento em inteiro para poder exibir o exit_status referente aquele inteiro;
		//se for 2 argumentos e tiver letras coladas ao segundo numero, executar o exit e na linha de baixo colocar o error referente!
		//
	else
		//exibir mensagem de error da mesma forma que no bash;	
	
}
