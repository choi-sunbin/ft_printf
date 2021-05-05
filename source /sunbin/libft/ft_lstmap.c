/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:22:04 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/01/03 19:55:21 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*ret_lst;
	t_list		*cur;

	ret_lst = NULL;
	cur = NULL;
	if (lst == 0 || f == 0)
		return (0);
	while (lst != 0 && f != 0)
	{
		if ((cur = ft_lstnew(f(lst->content))))
		{
			if (ret_lst == 0)
				ret_lst = cur;
			else
				ft_lstadd_back(&ret_lst, cur);
		}
		else
		{
			ft_lstclear(&ret_lst, del);
			return (0);
		}
		lst = lst->next;
	}
	return (ret_lst);
}
