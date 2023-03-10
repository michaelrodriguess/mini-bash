/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:04:06 by fcaetano          #+#    #+#             */
/*   Updated: 2023/03/02 17:40:04 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen((s));
	if (!i && (unsigned char)c)
		return (NULL);
	while ((int)i >= 0)
	{
		if ((unsigned char)c == (unsigned char)s[i])
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
