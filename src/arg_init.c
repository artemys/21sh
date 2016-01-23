/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:05:41 by aliandie          #+#    #+#             */
/*   Updated: 2016/01/05 13:05:43 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

t_arg	*arg_init(void)
{
	t_arg	*a;

	a = (t_arg*)malloc(sizeof(t_arg)); // 2 be free
	char buf[1000]; // ballec de la taille on met un '\0' apres
	a->arg_len = read(0, buf, 1000);
	printf("%d\n", a->arg_len);
	buf[a->arg_len - 1] = '\0';
	printf("%s\n", buf);
	a->arg = ft_strsplit(buf, ' '); // a->arg = commande entree dans le shell

	return (a);
}