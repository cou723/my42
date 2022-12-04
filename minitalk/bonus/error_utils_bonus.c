/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@xxxxxxxxx>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:57:25 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/07/27 14:57:25 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
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
