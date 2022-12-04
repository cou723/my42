/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_ft_printf.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:04:54 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/04/18 14:50:15 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_FT_PRINTF_H
# define PRIVATE_FT_PRINTF_H

# include "../libs/libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
size_t	put_char(char output);
size_t	put_str(char *output);
size_t	put_nbr(int output);
size_t	put_u_nbr_base(size_t n, const char *letters);
size_t	put_address(size_t output);
size_t	get_digit(size_t n, unsigned int base);

#endif
