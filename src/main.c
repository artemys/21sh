/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 11:35:57 by aliandie          #+#    #+#             */
/*   Updated: 2015/04/08 14:17:29 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <stdio.h>

char	**ft_command(char **arg, char **e)
{
	if (ft_strcmp(arg[0], "exit") == 0)
		exit(0);
	else if (ft_findbuiltin(arg) == 1)
		e = ft_cd(arg, e);
	else if (ft_findbuiltin(arg) == 0)
		e = ft_builtin(arg, e);
	else
		ft_exe(arg, e);
	return (e);
}

void	ft_pipe(void)
{
	int fd[2];
	int pid;
	char buf[1000];
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		while(read(fd[0], buf, 1000) != 0)
			printf("%s\n", buf);
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		ft_strcpy(buf, "hello\n");
		write(fd[1], buf, ft_strlen(buf) + 1);
		close(fd[1]);
	}
}

int		main(int ac, char **av, char **env)
{
	char	buf[1000];
	int		nb;
	char	**arg;
	char	**e;
//	char 	**tab;

	if (ac && av)
		e = ft_env(env);
	while (1)
	{
		ft_putstr("8>");
		nb = read(0, buf, 1000);
		if (nb == 0)
		{
			ft_putchar('\n');
			exit(0);
		}
		buf[nb - 1] = '\0';

		//tab = ft_strsplit(buf, '|');
	//	while (*tab)
	//	{
			
			arg = get_arg(buf);
	//		ft_pipe();
			if (arg[0])
			{
				e = ft_command(arg, e);
			}
	//		tab++;
	//	}
	
	}
	return (0);
}
