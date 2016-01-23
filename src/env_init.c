/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 20:00:26 by aliandie          #+#    #+#             */
/*   Updated: 2015/12/04 20:00:33 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char 	**envcpy(char **env)
{
	char **cpy;
	int i;

	i = 0;
	if(!(cpy = malloc(sizeof(char*) * ft_tablen(env) + 1))) // 2 be free
		return (NULL);
	while (env[i] && i <= ft_tablen(env) + 1)
	{
		cpy[i] = ft_strdup(env[i]);
		i++;
	}
	return (cpy);
}

t_env	*env_init(char **env)
{
	t_env	*e;
	e = (t_env*)malloc(sizeof(t_env)); // 2 be free
	e->env_cpy = envcpy(env);
	return(e);
}