/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_pair   <my_pair@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:19:48 by my_pair           #+#    #+#             */
/*   Updated: 2022/04/10 11:50:33 by my_pair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int n)
{
	if ((n > 64 && n < 91) || (n > 96 && n < 123) || (n > 47 && n < 58))
		return (1);
	else
		return (0);
}