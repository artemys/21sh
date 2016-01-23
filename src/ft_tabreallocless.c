/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabreallocless.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:31:45 by aliandie          #+#    #+#             */
/*   Updated: 2015/04/10 19:25:23 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char		**ft_tabreallocless(char **env, int j)
{
	char	**tmp;
	int		i;
	int		k;

	k = 0;
	i = 0;
	if(!(tmp = (char**)malloc(sizeof(char*) * (ft_tablen(env)))))
		return (NULL);
	while (i < ft_tablen(env))
	{
		if (i == j)
			i++;
		if (env[i] != NULL)
			tmp[k] = ft_strdup(env[i]);
		else
			tmp[k] = NULL;
		i++;
		k++;
	}
	return (tmp);
}
