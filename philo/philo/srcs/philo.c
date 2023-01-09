/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:12:41 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>
#include <philo.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void	display_philo_action(t_table *table, t_id id, char *message)
{
	char	*output_str;
	t_msec	elapsed_time;

	pthread_mutex_lock(&table->exist_dead_mutex);
	if (table->exist_dead)
	{
		pthread_mutex_unlock(&table->exist_dead_mutex);
		return ;
	}
	output_str = "%s%8lld %3d %s%s\n";
	elapsed_time = get_time() - table->start_time;
	if (id % 6 == 1)
		printf(output_str, RED, elapsed_time, id, message, RESET);
	else if (id % 6 == 2)
		printf(output_str, GREEN, elapsed_time, id, message, RESET);
	else if (id % 6 == 3)
		printf(output_str, YELLOW, elapsed_time, id, message, RESET);
	else if (id % 6 == 4)
		printf(output_str, BLUE, elapsed_time, id, message, RESET);
	else if (id % 6 == 5)
		printf(output_str, MAGENTA, elapsed_time, id, message, RESET);
	else
		printf(output_str, CYAN, elapsed_time, id, message, RESET);
	pthread_mutex_unlock(&table->exist_dead_mutex);
}

bool	eating(t_table *table, t_philo *philo)
{
	if (!take_forks(table, philo))
		return (false);
	eat_spaghetti(table, philo);
	release_forks(table->forks, philo);
	return (true);
}

void	sleeping(t_table *table, t_philo *philo)
{
	display_philo_action(table, philo->id, PPAM_SLEEP);
	exact_msleep(philo->time_to_sleep);
}

// if philo can eat, this function will return soon.
void	thinking(t_table *table, t_philo *philo)
{
	display_philo_action(table, philo->id, PPAM_THINK);
}

void	*philo(void *void_param)
{
	t_routine_param	*param;

	param = (t_routine_param *)void_param;
	if (!(param->philo->id % 2))
		exact_msleep(20);
	while (1)
	{
		pthread_mutex_lock(&param->table->exist_dead_mutex);
		if (param->table->exist_dead)
		{
			pthread_mutex_unlock(&param->table->exist_dead_mutex);
			free(void_param);
			return (NULL);
		}
		pthread_mutex_unlock(&param->table->exist_dead_mutex);
		if (!eating(param->table, param->philo))
		{
			free(void_param);
			return (NULL);
		}
		sleeping(param->table, param->philo);
		thinking(param->table, param->philo);
	}
}
