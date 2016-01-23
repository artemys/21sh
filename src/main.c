/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:34:01 by aliandie          #+#    #+#             */
/*   Updated: 2015/12/04 18:34:04 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"


// int 	cmd_cmp(t_arg	*a)
// {
// 	if (ft_strcmp(a->arg[0], "cd") == 0)
// 		return (1);
// 	if (ft_strcmp(arg[0], "env") == 0 || ft_strcmp(arg[0], "unsetenv") == 0 ||
// ft_strcmp(arg[0], "setenv") == 0)
// 			return (2);
// 	return (0);	
// }

// void	ft_command(t_arg *a)
// {
// 	if (ft_strcmp(a->arg[0], "exit") == 0)
// 		exit(0);
// 	else if (cmd_cmp(a) == 1)
// 		ft_cd(a);
// 	else if (cmd_cmp(a) == 2)
// 		builtin(a);
// 	else
// 		ft_exe(a);
// 	return ;
// }


int		main(int ac, char **av, char **env)
{
	t_arg	*a;
	t_env	*e;

	if (av && ac && env)
		e = env_init(env);
	while (1)
	{
		ft_putstr("8=============>");
		a = arg_init();
		if (a->arg)
			ft_cd(a, e);
	}
	return(0);
}
	