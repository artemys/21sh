/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_newenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:51:35 by aliandie          #+#    #+#             */
/*   Updated: 2015/04/10 19:27:02 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char *set_newenv(char *n, char **arg)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!arg[1])
		arg[1] = ft_strdup("~");
	if (!(tmp = malloc(sizeof(char) * (ft_strlen(arg[1]) - 1))))
		return (NULL);
	while (arg[1][i] == '~')
		i++;
	while (i < ft_strlen(arg[1]))
	{
		tmp[j] = arg[1][i];
		j++;
		i++;
	}
	n = ft_strjoin(n, tmp);
	return (n);
}
