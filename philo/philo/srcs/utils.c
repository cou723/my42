/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:19:24 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <unistd.h>
#include <sys/time.h>

t_msec	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

t_usec	get_current_utime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + tv.tv_usec);
}

void	exact_usleep(t_usec usec)
{
	t_usec	start_time;

	start_time = get_current_utime();
	while (get_current_utime() < start_time + usec)
		usleep(10);
}

void	exact_msleep(t_msec msec)
{
	t_msec	start_time;

	start_time = get_time();
	while (get_time() < start_time + msec)
		usleep(100);
}

void	put_str(char *str)
{
	write(1, str, ft_strlen(str));
}
