/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:05:47 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	handler(int signal, siginfo_t *info, void *unused)
{
	static unsigned char	byte_buf = 0;
	static unsigned int		power = 0;

	(void)unused;
	if (signal == SIGUSR2)
		byte_buf += 1 << power;
	power++;
	if (power == 8)
	{
		ft_putchar(byte_buf);
		power = 0;
		byte_buf = 0;
	}
	return ;
}

void	puts_pid(void)
{
	ft_putstr("pid:\t");
	ft_putunbrln((int)getpid());
}

int	main(void)
{
	t_sigaction	action;

	ft_bzero(&action, sizeof(t_sigaction));
	action.sa_sigaction = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	puts_pid();
	while (1)
		;
	return (0);
}
