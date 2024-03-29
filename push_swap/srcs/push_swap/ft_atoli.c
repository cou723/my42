/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <courange.c@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:34:58 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/09 12:50:07 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_p_m(char c)
{
	return (c == '+' || c == '-');
}

static int	ft_isspace(char c)
{
	return ((c == ' ' || (c >= '\t' && c <= '\r')));
}

long int	ft_atoli(const char *nptr)
{
	int			sign_rev_num;
	long int	num;

	sign_rev_num = -1;
	num = 0;
	while ((ft_isspace(*nptr) && *nptr))
		nptr++;
	if (is_p_m(*nptr))
	{
		sign_rev_num = *nptr - 44;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		num *= 10;
		num -= *nptr - 48;
		nptr++;
	}
	return (num * (sign_rev_num));
}
