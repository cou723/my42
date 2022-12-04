/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:15:48 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	put_utf8(const char *s, size_t s_byte)
{
	write(1, s, s_byte);
}

unsigned int	get_utf8_bit_len(char byte)
{
	unsigned int	total;

	total = 1;
	if (!(byte >> 7 & 0x1))
		return (BYTE * 1);
	if (byte >> 5 & 0x1)
		total = 3;
	else
		return (2 * BYTE);
	if (byte >> 4 & 0x1)
		total = 4;
	return (BYTE * total);
}

void	handler(int signal, siginfo_t *info, void *unused)
{
	static unsigned char	bytes_buf[4];
	static unsigned int		bit_i = 0;
	static unsigned int		byte_i = 0;
	static unsigned int		bit_len = 8;

	(void)unused;
	if (signal == SIGUSR2)
		bytes_buf[byte_i] += 1 << bit_i % 8;
	if (bit_i + 1 == BYTE)
		bit_len = get_utf8_bit_len(bytes_buf[0]);
	if ((bit_i + 1) % BYTE == 0)
		byte_i++;
	if (bit_i + 1 == bit_len)
	{
		if (bytes_buf[0] == 0)
			kill(info->si_pid, SIGUSR1);
		put_utf8((char *)bytes_buf, bit_len / 8);
		bit_i = 0;
		byte_i = 0;
		ft_bzero(bytes_buf, sizeof(bytes_buf));
	}
	else
		bit_i++;
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
