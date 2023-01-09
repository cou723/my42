/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:12:36 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static bool	is_dead(t_philo *philo)
{
	bool	is_dead;

	pthread_mutex_lock(&(philo->last_eat_mutex));
	is_dead = get_time() - philo->last_eat > philo->time_to_die;
	pthread_mutex_unlock(&(philo->last_eat_mutex));
	return (is_dead);
}

static bool	check_exist_dead(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		if (is_dead(&table->philos[i]))
		{
			display_philo_action(table, (&table->philos[i])->id, PPAM_DIE);
			pthread_mutex_lock(&table->exist_dead_mutex);
			table->exist_dead = true;
			pthread_mutex_unlock(&table->exist_dead_mutex);
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	is_eat_limit(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		pthread_mutex_lock(&(table->philos[i].eat_count_mutex));
		if (table->philos[i].eat_count > table->act_limit)
		{
			pthread_mutex_unlock(&(table->philos[i].eat_count_mutex));
			pthread_mutex_lock(&table->exist_dead_mutex);
			table->exist_dead = true;
			pthread_mutex_unlock(&table->exist_dead_mutex);
			return (true);
		}
		pthread_mutex_unlock(&(table->philos[i].eat_count_mutex));
		i++;
	}
	return (false);
}

void	*philo_monitor(void *void_param)
{
	t_table	*table;

	table = (t_table *)void_param;
	while (true)
	{
		if (is_eat_limit(table) || check_exist_dead(table))
			return (NULL);
		exact_usleep(10);
	}
}
