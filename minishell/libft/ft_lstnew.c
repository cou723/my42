/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:21:57 by *******           #+#    #+#             */
/*   Updated: 2022/01/29 20:37:04 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rtn_list;

	rtn_list = (t_list *)malloc(sizeof(t_list));
	if (rtn_list == NULL)
		return (NULL);
	rtn_list->content = content;
	rtn_list->next = NULL;
	return (rtn_list);
}
