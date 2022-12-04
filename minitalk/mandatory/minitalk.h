/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@xxxxxxxxx>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:55:01 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/07/24 16:55:02 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <errno.h>
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct sigaction	t_sigaction;

ssize_t			ft_putstr(char *s);
void			ft_bzero(void *str, size_t size);
void			ft_putunbrln(unsigned int num);
void			put_usage(void);
void			kill_error(void);
unsigned int	ft_atoui(const char *nptr);

#endif /* MINITALK_H */
