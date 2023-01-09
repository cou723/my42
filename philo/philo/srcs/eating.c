/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:12:25 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	take_forks(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&(table->forks[philo->left_fork]));
	display_philo_action(table, philo->id, PPAM_TAKE_FORK);
	pthread_mutex_lock(&(table->exist_dead_mutex));
	if (table->exist_dead || philo->left_fork == philo->right_fork)
	{
		pthread_mutex_unlock(&(table->exist_dead_mutex));
		pthread_mutex_unlock(&(table->forks[philo->left_fork]));
		return (false);
	}
	pthread_mutex_unlock(&(table->exist_dead_mutex));
	pthread_mutex_lock(&(table->forks[philo->right_fork]));
	display_philo_action(table, philo->id, PPAM_TAKE_FORK);
	return (true);
}

void	eat_spaghetti(t_table *table, t_philo *philo)
{
	display_philo_action(table, philo->id, PPAM_EAT);
	pthread_mutex_lock(&(philo->last_eat_mutex));
	philo->last_eat = get_time();
	pthread_mutex_unlock(&(philo->last_eat_mutex));
	pthread_mutex_lock(&(philo->eat_count_mutex));
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->eat_count_mutex));
	exact_msleep(philo->time_to_eat);
}

void	release_forks(pthread_mutex_t *forks, t_philo *philo)
{
	pthread_mutex_unlock(&(forks[(int)philo->left_fork]));
	pthread_mutex_unlock(&(forks[(int)philo->right_fork]));
}
