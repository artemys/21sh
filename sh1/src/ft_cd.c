/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:18:19 by aliandie          #+#    #+#             */
/*   Updated: 2015/04/10 19:39:03 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <stdio.h>

char **go_home(char *tmp, char **arg, char **e)
{
	int		pwd;
	char	*new;

	if (!(new = malloc(sizeof(char) * ft_strlen(e[find_arg(e, "HOME")]) - 5)))
		return (NULL);
	new = get_param(e[find_arg(e, "HOME")]);
	if (new == NULL)
		exit(0);
	if (!arg[1])
		new = set_newenv(new, arg);
	if (ft_strlen(arg[1]) > 1)
		new = set_newenv(new, arg);
	chdir(new);
	pwd = find_arg(e, "PWD");
	e[find_arg(e, "OLDPWD")] = ft_strjoin("OLDPWD=", get_param(e[pwd]));
	e[pwd] = ft_strjoin("PWD=", getcwd(tmp, 2048));
	return (e);
}

// char **go_home_directory(char *tmp, char **e)
// {
// 	int 	pwd;
// 	char	*new;

// 	if(!(new = malloc(sizeof(char) * ft_strlen(e[find_arg(e, "HOME")]) - 5)))
// 		return (NULL);
// 	new = get_param(e[find_arg(e, "HOME")]);
// 	if (new == NULL)
// 		exit(0);
// 	chdir(new);
// 	pwd = find_arg(e, "PWD");
// 	e[find_arg(e, "OLDPWD")] = ft_strjoin("OLDPWD=", get_param(e[pwd]));
// 	e[pwd] = ft_strjoin("PWD=", getcwd(tmp, 2048));
// 	return (e);
// }

void creat_new_pwd(char *tmp,char **arg)
{
	char *new;

	new = ft_strjoin(getcwd(tmp, 2048), "/");
	new = ft_strjoin(new, arg[1]);
	new = ft_strjoin(new, "/");
	if (new)
		chdir(new);
	else
		return ;
}

char **ft_cd(char **arg, char **e)
{
	char	*tmp;
	int		pwd;

	pwd = find_arg(e, "PWD");
	tmp = NULL;

	if (!arg[1] || ft_strncmp(arg[1], "~", 1) == 0)
	{
		e = go_home(tmp, arg, e);
		return (e);
	}
	else if (arg[1] && access(arg[1], F_OK | R_OK) == 0)
	{
		creat_new_pwd(tmp, arg);
		pwd = find_arg(e, "PWD");
		e[find_arg(e, "OLDPWD")] = ft_strjoin("OLDPWD=", get_param(e[pwd]));
		e[pwd] = ft_strjoin("PWD=", getcwd(tmp, 2048));
	}
	else if (access(arg[1], F_OK ) == 0 && access(arg[1], R_OK) == -1)
		ft_putendl("Error : access denied.");
 	else if (access(arg[1], F_OK) != 0)
		ft_putendl("Error: No such file or directory.");
	return (e);
}
