/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:07:14 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_byte(pid_t process_id, char byte)
{
	int	bit;
	int	i;
	int	send_signal;

	i = 0;
	while (i < 8)
	{
		usleep(100000);
		bit = (byte >> i) & 0x01;
		if (bit)
			send_signal = SIGUSR2;
		else
			send_signal = SIGUSR1;
		if (kill(process_id, send_signal) == -1)
			kill_error();
		i++;
	}
}

void	send_message(pid_t process_id, const char *message)
{
	while (*message != '\0')
	{
		send_byte(process_id, *message);
		message++;
	}
	send_byte(process_id, 0);
}

bool	is_correct_args(int argc, char **argv)
{
	ssize_t	is_error;
	size_t	len;

	is_error = 0;
	if (argc != 3)
		is_error = ft_putstr("Only two arguments are allowed.\n");
	else {
		len = 0;
		while (argv[1][len] != '\0')
			len++;
		if (!is_only_num(argv[1]))
			is_error = ft_putstr("The first argument must be a <pid>.\n");
		else if (len > 7)
			is_error = ft_putstr("Too many digits in <pid>.\n");
		else if (ft_atoui(argv[1]) < (unsigned int)2)
			is_error = ft_putstr("<pid> must be greater than 2.\n");
	}
	if (is_error != 0)
		put_usage();
	return (!is_error);
}

void	put_reception_message(int sig)
{
	ft_putstr("Message successfully sent!\n");
}

int	main(int argc, char **argv)
{
	pid_t		process_id;
	char		*message;
	t_sigaction	action;

	if (!is_correct_args(argc, argv))
		exit(1);
	process_id = (pid_t)ft_atoui(argv[1]);
	message = argv[2];
	action.sa_handler = put_reception_message;
	sigaction(SIGUSR1, &action, NULL);
	send_message(process_id, message);
	pause();
	return (0);
}
