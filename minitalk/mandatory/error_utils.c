/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@xxxxxxxxx>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:55:10 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/07/24 16:55:11 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <errno.h>

void	put_usage(void)
{
	ft_putstr("Usage:\n");
	ft_putstr("	./client [server-pid] [send-message]\n");
}

void	kill_error(void)
{
	if (errno == EINVAL)
		ft_putstr("Invalid <pid> specified.");
	else if (errno == EPERM)
		ft_putstr("This process does not have permission to signal.");
	else
		ft_putstr("The target process or process group does not exist.");
	put_usage();
	exit(1);
}
