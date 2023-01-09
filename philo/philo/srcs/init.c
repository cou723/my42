/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:12:28 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <stddef.h>

static bool	init_forks(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		if (pthread_mutex_init(&(table->forks[i]), NULL) == -1)
		{
			destroy_forks(table->forks, i);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	init_philo(t_table *table, char *argv[], size_t i)
{
	table->philos[i].id = i + 1;
	table->philos[i].right_fork = i;
	table->philos[i].left_fork = (i + 1) % table->num_of_philo;
	table->philos[i].last_eat = get_time();
	table->philos[i].eat_count = 0;
	table->philos[i].time_to_die = (t_msec)ft_atoli(argv[2]);
	table->philos[i].time_to_eat = (t_msec)ft_atoli(argv[3]);
	table->philos[i].time_to_sleep = (t_msec)ft_atoli(argv[4]);
	if (pthread_mutex_init(&(table->philos[i].last_eat_mutex), NULL))
		return (false);
	if (pthread_mutex_init(&(table->philos[i].eat_count_mutex), NULL))
	{
		pthread_mutex_destroy(&(table->philos[i].last_eat_mutex));
		return (false);
	}
	return (true);
}

static bool	init_philos(t_table *table, char *argv[])
{
	size_t	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		if (!init_philo(table, argv, i))
		{
			destroy_philos(table->philos, i);
			return (false);
		}
		i++;
	}
	return (true);
}

static void	init_args(t_table *table, int argc, char *argv[])
{
	table->num_of_philo = (size_t)ft_atoli(argv[1]);
	table->act_limit = -1;
	if (argc == 6)
		table->act_limit = (size_t)ft_atoli(argv[5]);
}

bool	init_table(t_table *table, int argc, char *argv[])
{
	init_args(table, argc, argv);
	if (!init_philos(table, argv))
		return (false);
	if (!init_forks(table))
	{
		destroy_philos(table->philos, table->num_of_philo);
		return (false);
	}
	table->exist_dead = false;
	if (pthread_mutex_init(&(table->exist_dead_mutex), NULL))
	{
		destroy_philos(table->philos, table->num_of_philo);
		destroy_forks(table->forks, table->num_of_philo);
		return (false);
	}
	return (true);
}
