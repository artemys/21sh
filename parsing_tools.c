/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:24:20 by aliandie          #+#    #+#             */
/*   Updated: 2016/01/22 13:24:23 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



char	**sep_trim(char **arg)
{
	int i;
	int j;
	int k;
	k = 0;
	j = 0;
	i = 1;
	char	**tab;
	tab = malloc(sizeof(char*) * ft_tablen(arg) - 1);
	
	while (arg[i])
	{
		while (arg[i][j] && arg)
			j++;
		if (arg[i][0] == '|' || i == ft_tablen(arg))
		{	
			printf("%d\n", j);
			tab[k] = malloc(sizeof(char) * j);
			j = 0;
			i++;
			k++;
		}
		else
			i++;
	}
	i = 1;
	j = 0;
	k = 0;
	while (arg[i] && arg[i][j])
	{
		//printf("j=%d\narg[j]=%c\n", j, arg[i][j]);
		tab[k][j] = arg[i][j];
		if (arg[i][j] == '|')
		{
			j = 0;
			i++;
			k++;
		}
		else
			i++;
		j++;
	}
	ft_puttab(tab);
	return (tab);
}
int		sep_count(char	**arg)
{
	int i;
	int sep_nb;
	i = 0;
	sep_nb = 0;

	while (arg[i])
	{
		if (ft_strcmp(arg[i], "|") == 0)
		{
			sep_nb++;
			i++;
		}
		else
			i++;
		
	}
	return (sep_nb);
}

char		**sep_trim(char	**arg)
{
	char	**tab;
	int	i;
	i = 0;
	tab = malloc(sizeof(char*) * ft_tablen(arg));
	while(arg[i])
	{
		
		if(!tab[i][0])
		{
			printf("%s\n", "coucou");
			tab[i] = ft_strdup(arg[i]);
		}
		else if (ft_strcmp(arg[i], "|") != 0)
			tab[i] = ft_strjoin(tab[i], arg[i]);
		else
			i++;
		i++;
	}
	//ft_puttab(tab);
	return (tab);
}