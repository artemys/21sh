/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_arg_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:13:19 by aliandie          #+#    #+#             */
/*   Updated: 2015/03/03 15:42:44 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		find_arg_p(char **e, char *arg)
{
	int i;

	i = 0;
	while (e[i] != NULL && arg)
	{
		if (ft_strncmp(e[i], arg, ft_strlen(arg)) == 0)
			return (i);
		i++;		
	}
	return (-1);
}
