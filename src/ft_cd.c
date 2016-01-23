/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:08:28 by aliandie          #+#    #+#             */
/*   Updated: 2016/01/05 14:08:30 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "sh21.h"
int 	ft_int_len(int nb)
{
	int l;
	l = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}

t_cd	*cd_init(t_env	*e)
{
	t_cd	*c;
	c = (t_cd*)malloc(sizeof(t_cd));	//2 be free
	c->pwd_p = find_arg_p(e->env_cpy, "PWD");
	return (c);
}

void	check_home(t_arg	*a, t_env	*e)
{
	if (!a->arg[1] || ft_strncmp(a->arg[1], "~", 1) == 0)
	{
		e->env = go_home(c, a, e);
		return (e);
	}
	else
		return (e);
}

void	ft_cd(t_arg		*a, t_env	*e)
{
	ft_puttab(a->arg);
	t_cd	*c;
	c = cd_init(e);
	check_home(a, e);
	else if( arg[1] && access(a->arg[1], F_OK | R_OK) == 0)
	{
		creat_new_pwd(c, a);
		pwd = find_arg_p(e, "PWD");
		e[find_arg_p(e, "OLDPWD")] = ft_strjoin("OLDPWD=", get_param(e[pwd]));
		e[pwd] = ft_strjoin("PWD=", getcwd(tmp, 2048));
	}

}
