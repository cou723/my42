/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:39:07 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	destroy_philo(t_philo *philo)
{
	pthread_mutex_destroy(&(philo->last_eat_mutex));
	pthread_mutex_destroy(&(philo->eat_count_mutex));
}

void	destroy_philos(t_philo *philo, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		destroy_philo(&philo[i]);
		i++;
	}
}

void	destroy_table_forks(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
}

void	destroy_forks(pthread_mutex_t forks[], size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&(forks[i]));
		i++;
	}
}
