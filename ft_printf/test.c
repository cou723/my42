/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:08:57 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPECIFIER "%c, %c, %s, %p, %d, %d, %d, %i, %i, %u, %u, %x, %X, %x, %X\n"
#define VALUE 'a', 0, "string", str1, -100, INT_MAX, INT_MIN, 0 -210, 100, UINT_MAX, 100, 100, 0, 0

int	main(void)
{
	int	i;
	int	expect_value;
	int	actual_value;

	i = 100;
	char str1="fdasfasd";
	expect_value = printf(SPECIFIER, VALUE);
	actual_value = ft_printf(SPECIFIER, VALUE );
	printf("%d\n%d\n", expect_value, actual_value);
}
