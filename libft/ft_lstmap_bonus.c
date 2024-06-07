/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:34:19 by uahmed            #+#    #+#             */
/*   Updated: 2023/11/24 21:36:05 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*temp;

	if (!f || !del)
		return (0);
	newlst = NULL;
	while (lst)
	{
		temp = ft_lstnew(f(lst -> content));
		if (!temp)
		{
			del(newlst -> content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, temp);
		lst = lst -> next;
	}
	return (newlst);
}
