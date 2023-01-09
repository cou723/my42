/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:48:57 by *******           #+#    #+#             */
/*   Updated: 2022/01/29 20:36:06 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*p_tmp;

	if (lst == NULL)
		return ;
	p = *lst;
	while (p != NULL)
	{
		p_tmp = p->next;
		ft_lstdelone(p, del);
		p = p_tmp;
	}
	*lst = NULL;
}
