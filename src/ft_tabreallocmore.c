/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabreallocmore.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:29:04 by aliandie          #+#    #+#             */
/*   Updated: 2015/04/10 19:25:51 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**ft_tabreallocmore(char **env)
{
	char	**tmp;
	int		i;

	i = 0;
	if(!(tmp = (char**)malloc(sizeof(char*) * (ft_tablen(env) + 2))))
		return (NULL);
	while (env[i])
	{
		tmp[i] = ft_strdup(env[i]);
		i++;
	}
	return (tmp);
}
