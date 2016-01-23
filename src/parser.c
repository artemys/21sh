/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 16:19:57 by aliandie          #+#    #+#             */
/*   Updated: 2016/01/19 16:19:58 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdio.h>
#include "sh21.h"




t_list	*ft_lst_arg_new(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = (t_list*)malloc(sizeof(t_list));
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
		lst->next = NULL;
		return (lst);
	}
	if (lst == NULL)
		return (NULL);
	lst->content = (void*)malloc(sizeof(void) * content_size);
	if (lst->content == NULL)
		return (NULL);
	lst->content = ft_memcpy(lst->content, content, content_size);
	lst->content_size = content_size;
	lst->next = NULL;
	return (lst);
}


void	del(void *c, size_t c_size)
{
	free(c);
	free(&c_size);

}

t_list	*parser(char **arg, t_arg	*a)
{
	t_list  *tmp;
	t_list  *begin_list;
	char	*join;
	int i;
	i = 1;
	
	a->lst = ft_lstnew("begin", 5);
	printf("%s\n", a->lst->content);
	begin_list = a->lst; 
	while (i < ft_tablen(arg) - 1 && tmp && a->lst)
	{		
		if (ft_strcmp(arg[i], "|") == 0)
		{
			a->sep = ft_strdup("|");
			printf("%s\n", a->sep);
			i++;
		}
		else if (ft_strcmp(arg[i + 1], "|") != 0)
		{
			join = ft_strjoin(arg[i], " ");
			join = ft_strjoin(join, arg[i+1]);
			tmp = ft_lstnew(join, ft_strlen(join - 1));
			ft_lstadd(&tmp, a->lst);

			a->lst = a->lst->next;
			i++;
		}
		else
			i++;
	}
	tmp = begin_list->next;
	free(begin_list);
	begin_list = tmp;
	free(tmp);
	a->lst->next = NULL;
	return (begin_list);
}

int main(int ac, char **av)
{
	int i;
	i = 0;
	(void)ac;
	t_arg	*a;
	printf("%s\n", av[2]);
	a = arg_init();
	ft_puttab(a->arg);
//	a->lst = parser(av, a);
	i = 0;
	while (i < ft_tablen(av) && a->lst)
	{
		ft_putstr(a->lst->content);
		ft_putchar(' ');
		a->lst = a->lst->next;
		i++;
	}
	return (0);
}