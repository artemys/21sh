/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 20:00:26 by aliandie          #+#    #+#             */
/*   Updated: 2015/12/04 20:00:33 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SH21_H
# define SH21_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

typedef struct 	s_env
{
	char 		**env_cpy;
	int			env_len;
}				t_env;

typedef	struct 	s_arg 
{
	char		**arg;
	int			arg_len;
	char		*sep;
	t_list		*lst;
}				t_arg;

typedef	struct  s_cd
{
	int 		pwd_p;
	char		tmp;


}				t_cd;

// cree la stucture env et fait une copie
// de l'env.
char 			**envcpy(char **env);
t_env			*env_init(char **env);
/******************************************/

//init la struct arg qui contien ce aue l'on recoit -> la commande
t_arg			*arg_init(void);
/******************************************/

//fct pour cd
void	ft_cd(t_arg		*a, t_env	*e);

// prend en paramettre l'environnement 
//et l'argument a rechercher et renvoit un pointeur sur la place de l'arg
int		find_arg_p(char **e, char *arg);



#endif